#include "GameRoomMemento.hpp"

// GameRoomMemento::GameRoomMemento(std::string filename, v8::Local<v8::Object> data)
// {
//     this->file.open(filename);
//     file << JSONStringified(data);
// }
GameRoomMemento::GameRoomMemento(std::string filename, GameRoom<Rule> *gameRoom)
{
    this->gameRoom = gameRoom;
    std::string dir = "saves/" + gameRoom->getRoomName() + "#" + gameRoom->getRoomID();
    // mkdir(dir);
    if (!std::__fs::filesystem::exists(dir))
        std::__fs::filesystem::create_directory(dir);

    // this->gameRoom = gameRoom;
    {
        std::ofstream ofile;
        ofile.open(dir + "/" + filename + ".json");
        // std::cout << "strt#########RoomMemento::GameRoomMemento\n";
        ofile << JSONStringified(gameRoom->getFullInfo());
        // std::cout << "end#########RoomMemento::GameRoomMemento\n";

        ofile.close();
    }
    this->ifile.open(dir + "/" + filename + ".json");
}

GameRoomMemento::~GameRoomMemento()
{
    ifile.close();
}

// std::string GameRoomMemento::getSaveID() { return saveID; }

// v8::Local<v8::Object> GameRoomMemento::getMemento()
// {
//     std::string jsonStr;
//     file >> jsonStr;
//     return JSONParse(jsonStr);
// }

void GameRoomMemento::restoreMemento()
{
    std::cout << "#######::loadRoom\n";
    std::string jsonStr;
    ifile >> jsonStr;
    // std::cout << jsonStr << std::endl;

    v8::Local<v8::Object> info = JSONParse(jsonStr);
    // { //rule
    //     unsigned int rule;
    //     if (!GetObjProperty(info, "rule", rule))
    //         return;
    //     if (rule == 0)
    //         gameRoom->rule = new Rule1();
    //     if (rule == 1)
    //         gameRoom->rule = new Rule2();
    // }

    v8::Local<v8::Object> fieldInfo;

    if (!GetObjProperty(info, "field", fieldInfo))
        return;

    v8::Local<v8::Array> landscapes;
    unsigned int rowsQuantity;
    unsigned int columnsQuantity;
    unsigned int maximumObjectsQuantity;
    std::cout << "#######::loadRoom\n";

    if (!GetObjProperty(fieldInfo, "rowsQuantity", rowsQuantity))
        return;
    std::cout << rowsQuantity << "###11####::loadRoom\n";

    if (!GetObjProperty(fieldInfo, "columnsQuantity", columnsQuantity))
        return;
    std::cout << columnsQuantity << "####12###::loadRoom\n";

    if (!GetObjProperty(fieldInfo, "maximumObjectsQuantity", maximumObjectsQuantity))
        return;
    std::cout << maximumObjectsQuantity << "####13###::loadRoom\n";
    //landscape + delete obj
    for (unsigned int row = 0; row < rowsQuantity; row++)
        for (unsigned int column = 0; column < columnsQuantity; column++)
        {
            std::cout << row << column << "###14####::loadRoom\n";
            std::cout << gameRoom->field->getRowsQuantity() << gameRoom->field->getColumnsQuantity() << "###14-1####::loadRoom\n";

            FieldCell *cell = gameRoom->getFieldCell(row, column);
            unsigned int landscapeType = 0;
            // GetArrProperty(landscapes, row * columnsQuantity + column, landscapeType);
            std::cout << row << column << "####15###::loadRoom\n";
            cell->setLandscape(new LandscapeProxy(landscapeType));

            // if (cell->getObject() != nullptr)
            // {
            // delete cell->getObject();
            cell->setObject(nullptr);
            std::cout << (gameRoom->getFieldCell(row, column)->getObject() == nullptr ? "true" : "false______________________") << "\n";
            // }
            std::cout << row << column << "###16####::loadRoom\n";
        }
    std::cout << "###17####::loadRoom\n";
    //players

    v8::Local<v8::Array> playersInfo;
    if (!GetObjProperty(info, "playersInfo", playersInfo))
        return;
    std::cout << "###18####::loadRoom\n";

    std::for_each(gameRoom->players.begin(), gameRoom->players.end(), [](Player *player) { delete player; });
    gameRoom->players.clear();

    unsigned int len = playersInfo->Length();
    for (unsigned int index = 0; index < len; ++index)
    {
        v8::Local<v8::Object> player;
        if (!GetArrProperty(playersInfo, index, player))
            return;
        std::cout << "###19####::loadRoom\n";

        std::string playerID;
        std::string playerName;
        if (!GetObjProperty(player, "playerID", playerID))
            return;
        std::cout << "####20###::loadRoom\n";
        if (!GetObjProperty(player, "playerName", playerName))
            return;
        std::cout << "###21####::loadRoom\n";

        gameRoom->addPlayer(playerID, playerName);

        { //add Base
            unsigned int row, column;
            v8::Local<v8::Object> base;
            /*  */ v8::Local<v8::Object> stats;
            /*  */ /*  */ double health;
            if (!GetObjProperty(player, "base", base))
                return;
            if (!GetObjProperty(base, "x", column))
                return;
            if (!GetObjProperty(base, "y", row))
                return;
            if (!GetObjProperty(base, "stats", stats))
                return;
            if (!GetObjProperty(stats, "health", health))
                return;

            std::cout << "####22###::loadRoom\n";
            // std::cout << gameRoom->getPlayersNames().size();
            // std::cout<<gameRoom->getPlayersNames()[1];
            // std::cout << (gameRoom->getPlayer(playerID) == nullptr);
            gameRoom->getPlayer(playerID)->createBase(row, column);
            std::cout << "####22-1###::loadRoom\n";
            gameRoom->getPlayer(playerID)->getBase()->setHealth(health);
            std::cout << "####22-2###::loadRoom\n";
            std::cout << "#######::loadRoom\n_-______---------_-_-_Created";
            std::cout << JSONStringified(gameRoom->getFieldCell(column, row)->getObject()->getFullInfo()) << "\n";
        }
        { //add resource
            v8::Local<v8::Object> resourceBag;
            std::map<unsigned int, double> restoredResourceBag;
            // unsigned int type;
            // double quantity;
            std::cout << "###23####::loadRoom\n";

            if (!GetObjProperty(player, "resourceBag", resourceBag))
                return;
            std::cout << "###24####::loadRoom\n";

            if (!ObjToMap(resourceBag, restoredResourceBag))
                return;
            std::cout << "###25####::loadRoom\n";

            for (std::map<unsigned int, double>::iterator it = restoredResourceBag.begin(); it != restoredResourceBag.end(); ++it)
                gameRoom->getPlayer(playerID)->getResourceBag()->addResource(it->first, it->second);
        }
    }

    { //add nowPlayer
        unsigned int nowPlayerIndex = 0;
        if (GetObjProperty(info, "nowPlayer", nowPlayerIndex))
            gameRoom->nowPlayer = gameRoom->players[nowPlayerIndex];
    }

    std::cout << "###26####::loadRoom\n";
    //units

    {
        v8::Local<v8::Array> units;
        if (!GetObjProperty(fieldInfo, "units", units))
            return;
        for (unsigned int index = 0; index < units->Length(); index++)
        {

            v8::Local<v8::Object> unit;
            /*  */ std::string playerID;
            /*  */ unsigned int objectType, row, column;
            /*  */ v8::Local<v8::Object> stats;
            /*  */ /*  */ double health;
            if (!GetArrProperty(units, index, unit))
                return;
            if (!GetObjProperty(unit, "playerID", playerID))
                return;
            if (!GetObjProperty(unit, "objectType", objectType))
                return;
            if (!GetObjProperty(unit, "y", row))
                return;
            if (!GetObjProperty(unit, "x", column))
                return;
            if (!GetObjProperty(unit, "stats", stats))
                return;
            if (!GetObjProperty(stats, "health", health))
                return;
            gameRoom->getPlayer(playerID)->createUnit(row, column, objectType);
            static_cast<Unit *>(gameRoom->getFieldCell(row, column)->getObject())->setHealth(health);
        }
    }

    std::cout << "#######::loadRoom\n";
    { //resGens
        v8::Local<v8::Array> resGens;
        std::cout << "#######::loadRoom\n";

        if (!GetObjProperty(fieldInfo, "resGens", resGens))
            return;
        std::cout << "#######::loadRoom\n";

        for (unsigned int index = 0; index < resGens->Length(); index++)
        {
            std::cout << "#######::loadRoom\n";
            v8::Local<v8::Object> resGen;
            /*  */ std::string playerID;
            /*  */ unsigned int objectType, row, column;
            /*  */ v8::Local<v8::Object> stats;
            /*  */ /*  */ double coefficient;
            if (!GetArrProperty(resGens, index, resGen))
                return;
            if (!GetObjProperty(resGen, "playerID", playerID))
                return;
            if (!GetObjProperty(resGen, "objectType", objectType))
                return;
            if (!GetObjProperty(resGen, "y", row))
                return;
            if (!GetObjProperty(resGen, "x", column))
                return;
            if (!GetObjProperty(resGen, "stats", stats))
                return;
            if (!GetObjProperty(stats, "coefficient", coefficient))
                return;

            gameRoom->editor->createResourceGenerator(row, column, objectType);
            static_cast<ResourceGenerator *>(gameRoom->getFieldCell(row, column)->getObject())->setCoefficient(coefficient);
            static_cast<ResourceGenerator *>(gameRoom->getFieldCell(row, column)->getObject())->setPlayerID(playerID);
            std::cout << "#######::loadRoom\n";
        }
    }

    // GameRoom *restoredGameRoom = new GameRoom(gameRoom->getEditor()->getEditorID(),
    //                                           gameRoom->getRoomID(),
    //                                           gameRoom->getRoomName(),
    //                                           restoredField,
    //                                           gameRoom->getUuidGen(),
    //                                           gameRoom->getNeutralObjectFactory(),
    //                                           gameRoom->getCombatObjectTypeFactory(),
    //                                           gameRoom->getMediator());

    // GameRoom *restoredGameRoom = new GameRoom(gameRoom->getEditor(), gameRoom->getRoomID(), gameRoom->getRoomName(), )
    //todo
    std::cout << "#######::loadRoom\n";
}