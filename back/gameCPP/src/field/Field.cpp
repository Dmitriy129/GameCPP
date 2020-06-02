#include "Field.hpp"
Field::Field(unsigned int rowsQuantity, unsigned int columnsQuantity, unsigned int maximumObjectsQuantity, Mediator *mediator)
{
    // std::cout << "##########Field::1\n";

    this->rowsQuantity = rowsQuantity;
    this->columnsQuantity = columnsQuantity;
    this->currentObjectsQuantity = 0;
    this->maximumObjectsQuantity = maximumObjectsQuantity;
    this->mediator = mediator;

    fieldGrid = new FieldCell *[rowsQuantity];
    for (unsigned int i = 0; i < rowsQuantity; i++)
        fieldGrid[i] = new FieldCell[columnsQuantity];
}

Field::Field(unsigned int rowsQuantity, unsigned int columnsQuantity, Mediator *mediator)
{
    // std::cout << "##########Field::2\n";

    this->rowsQuantity = rowsQuantity;
    this->columnsQuantity = columnsQuantity;
    this->currentObjectsQuantity = 0;
    this->maximumObjectsQuantity = rowsQuantity * columnsQuantity * 0.8;
    this->mediator = mediator;

    fieldGrid = new FieldCell *[rowsQuantity];
    for (unsigned int i = 0; i < rowsQuantity; i++)
        fieldGrid[i] = new FieldCell[columnsQuantity];
}

Field::Field(const Field &lastField)
{
    // std::cout << "##########Field::3\n";

    this->rowsQuantity = lastField.rowsQuantity;
    this->columnsQuantity = lastField.columnsQuantity;
    this->currentObjectsQuantity = lastField.currentObjectsQuantity;
    this->maximumObjectsQuantity = lastField.maximumObjectsQuantity;
    this->mediator = lastField.mediator;

    fieldGrid = new FieldCell *[lastField.rowsQuantity];
    for (unsigned int i = 0; i < lastField.rowsQuantity; i++)
    {
        fieldGrid[i] = new FieldCell[lastField.columnsQuantity];
        for (unsigned int j = 0; j < lastField.columnsQuantity; j++)
            this->fieldGrid[i][j] = lastField.fieldGrid[i][j];
    }
}

Field::Field(Field &&lastField)
{
    // std::cout << "##########Field::4\n";
    this->fieldGrid = lastField.fieldGrid;
    this->rowsQuantity = lastField.rowsQuantity;
    this->columnsQuantity = lastField.columnsQuantity;
    this->currentObjectsQuantity = lastField.currentObjectsQuantity;
    this->maximumObjectsQuantity = lastField.maximumObjectsQuantity;
    this->mediator = lastField.mediator;

    fieldGrid = new FieldCell *[lastField.rowsQuantity];
    for (unsigned int i = 0; i < lastField.rowsQuantity; i++)
    {
        fieldGrid[i] = new FieldCell[lastField.columnsQuantity];
        for (unsigned int j = 0; j < lastField.columnsQuantity; j++)
            this->fieldGrid[i][j] = lastField.fieldGrid[i][j];
    }

    // lastField.fieldGrid = nullptr;
    // lastField.rowsQuantity = 0;
    // lastField.columnsQuantity = 0;
    // lastField.currentObjectsQuantity = 0;
    // lastField.maximumObjectsQuantity = 0;
    // lastField.mediator = nullptr;
}
Field::~Field()
{
    // std::cout << "##########Field::DEL\n";
    for (unsigned int i = 0; i < rowsQuantity; i++)
    {
        for (unsigned int j = 0; j < columnsQuantity; j++)
        {
            delete &fieldGrid[i][j];
            //remove all object in this fieldCell
        }
        delete[] fieldGrid[i];
    }
    delete[] fieldGrid;
    delete mediator;
}
/* 
void Field::setRowsQuantity(unsigned int rowsQuantity)
{
    this->rowsQuantity = rowsQuantity;
}
void Field::setColumnsQuantity(unsigned int columnsQuantity)
{
    this->columnsQuantity = columnsQuantity;
}
void Field::setMaximumObject(unsigned int maximumObjectsQuantity)
{
    this->maximumObjectsQuantity = maximumObjectsQuantity;
}
void Field::setCurrentObject(unsigned int currentObjectsQuantity)
{
    this->currentObjectsQuantity = currentObjectsQuantity;
}
void Field::setMediator(Mediator *mediator)
{
    this->mediator = mediator;
}
*/

unsigned int Field::getRowsQuantity() const
{
    return rowsQuantity;
}
unsigned int Field::getColumnsQuantity() const
{
    return columnsQuantity;
}
unsigned int Field::getMaximumObject() const
{
    return maximumObjectsQuantity;
}
unsigned int Field::getCurrentObject() const
{
    return currentObjectsQuantity;
}

FieldCell &Field::getFieldCell(unsigned int rowNumber, unsigned int columnNumber)
{
    // std::cout << rowNumber << columnNumber << "##########Field::getFieldCell\n";

    // std::cout << rowsQuantity << "##########Field::getFieldCell\n";
    // std::cout << columnsQuantity << "##########Field::getFieldCell\n";
    return fieldGrid[rowNumber][columnNumber];
}
// std::vector<std::string> Field::getLandscapes()
// {
//     std::vector<std::string> landscapes;

//     for (unsigned int i = 0; i < rowsQuantity; i++)
//         for (unsigned int j = 0; j < this->columnsQuantity; j++)
//             // // // std::cout << this->fieldGrid[i][j].getLandscape()->getLandscapeType() << " --- " << i << " " << j << "\n";

//             landscapes.push_back(this->fieldGrid[i][j].getsLandscape()->getLandscapeType());
//     return landscapes;
// }

// std::vector<std::string> Field::getObjects()
// {
//     std::vector<int> objects;
//     for (int i = 0; i < this->rowsQuantity; i++)
//         for (int j = 0; j < this->columnsQuantity; j++)
//             objects.push_back(this->fieldGrid[i][j].getObject() != nullptr ? this->fieldGrid[i][j].getObject()->getObjectType() : -1);
//     return objects;
// }
Mediator *Field::getMediator() const
{
    return mediator;
}

void Field::addObject(unsigned int rowNumber, unsigned int columnNumber, Object *object)
{
    if (object == nullptr)
        return;
    if (rowNumber >= rowsQuantity || columnNumber >= columnsQuantity)
    {

        // // std::cout << "error# It is impossible to access the cell of the field\n * in file \"Field\"\n";
        return;
    }
    if (currentObjectsQuantity >= maximumObjectsQuantity)
    {
        // // std::cout << "error# You cannot create a new object. Maximum number of Objects created: " << currentObjectsQuantity << '/' << maximumObjectsQuantity
        //    <<std::endl
        //    <<"*in file \"Field\"\n";
        ;
        return;
    }
    if (fieldGrid[rowNumber][columnNumber].getObject() != nullptr)
    {
        // // std::cout << "error# The field cell is occupied by another object, and you cannot create a new object"
        //    <<std::endl
        //    <<"*in file \"Field\"\n";
        return;
    }

    fieldGrid[rowNumber][columnNumber].setObject(object);

    // object->attachEvent("object death", this);
    object->attachEvent("object updated", this);
    object->attachEvent("log", this);

    currentObjectsQuantity++;
    // // std::cout << "A new object is created and added to the field cell [" << rowNumber << "][" << columnNumber << "]."
    //    <<std::endl
    //    <<"*in file \"Field\"\n";

    fireEvent("object updated", getObjectData(rowNumber, columnNumber));
}

void Field::updateLandscape(unsigned int rowNumber, unsigned int columnNumber, unsigned int landscapeType /* Landscape *landscape */)
{
    fieldGrid[rowNumber][columnNumber].setLandscape(new LandscapeProxy(landscapeType));
}

void Field::removeObject(Object *object)
{
    for (int rowNumber = 0; rowNumber < rowsQuantity; rowNumber++)
        for (int columnNumber = 0; columnNumber < columnsQuantity; columnNumber++)
        {
            if (fieldGrid[rowNumber][columnNumber].getObject() == object)
            {
                // // // std::cout << "\n&find&\n";
                removeObject(rowNumber, columnNumber);
            }
        }
}
void Field::removeObject(unsigned int rowNumber, unsigned int columnNumber)
{

    if (rowNumber >= rowsQuantity || columnNumber >= columnsQuantity)
    {
        // // std::cout << "error# It is impossible to access the cell of the field\n * in file \"Field\"\n";
        return;
    }

    if (fieldGrid[rowNumber][columnNumber].getObject() == nullptr)
    {
        // // std::cout << "error# The field cell contains no objects. You cannot delete a void."
        //    <<std::endl
        //    <<"*in file \"Field\"\n";
        return;
    }
    // delete fieldGrid[rowNumber][columnNumber].getObject();
    fieldGrid[rowNumber][columnNumber].setObject(nullptr);
    currentObjectsQuantity--;
    // // std::cout << "The object was deleted from the field cell [" << rowNumber << "][" << columnNumber << "]."
    //    <<std::endl;
    fireEvent("object updated", getObjectData(rowNumber, columnNumber));
}

void Field::moveObject(unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber)
{
    Object *fromObj = fieldGrid[fromRowNumber][fromColumnNumber].getObject();
    Object *toObj = fieldGrid[toRowNumber][toColumnNumber].getObject();

    if (fromObj == nullptr)
    {
        // // std::cout << "The field cell contains no objects. You cannot move a void."
        //    <<std::endl
        //    <<"*in file \"Field\"\n";
        return;
    }

    if (!fromObj->isMoveable())
    {
        // // std::cout << "The Object cannot be moved. You cannot move this Object."
        //    <<std::endl
        //    <<"*in file \"Field\"\n";
        return;
    }

    if (toObj == nullptr)
    {
        if (!fieldGrid[toRowNumber][toColumnNumber].getLandscape()->checkAccessMove(fieldGrid[fromRowNumber][fromColumnNumber].getObject()->getObjectType()))
        {

            // // std::cout
            //    <<"The object cannot be moved to this cell .([" << fromRowNumber << "][" << fromColumnNumber << "]->[" << toRowNumber << "][" << toColumnNumber << "]) "
            //    <<std::endl
            //    <<"*in file \"Field\"\n";

            return;
        }
        fieldGrid[toRowNumber][toColumnNumber].setObject(fromObj);
        fieldGrid[fromRowNumber][fromColumnNumber].setObject(nullptr);
        // // std::cout << "The Object has been moved .([" << fromRowNumber << "][" << fromColumnNumber << "]->[" << toRowNumber << "][" << toColumnNumber << "]) "
        //    <<std::endl
        //    <<"*in file \"Field\"\n";
        fireEvent("object updated", getObjectData(fromRowNumber, fromColumnNumber));
        fireEvent("object updated", getObjectData(toRowNumber, toColumnNumber));
        return;
    }
    else
    {

        mediator->interactionObjObj(this, fromRowNumber, fromColumnNumber, toRowNumber, toColumnNumber);

        /* 
        if (!fieldGrid[toRowNumber][toColumnNumber].getLandscape()->checkAccessInteraction(fieldGrid[fromRowNumber][fromColumnNumber].getObject()->getObjectType()))
        {

            // // std::cout << "The Object cannot interact with object in this cell .([" << fromRowNumber << "][" << fromColumnNumber << "]->[" << toRowNumber << "][" << toColumnNumber << "]) "
                  //    <<std::endl
                  //    <<"*in file \"Field\"\n";
            return;
        }

        // // std::cout << "Object Interaction .([" << fromRowNumber << "][" << fromColumnNumber << "] & [" << toRowNumber << "][" << toColumnNumber << "]) "
              //    <<std::endl
              //    <<"*in file \"Field\"\n";
        interactionObjObj(fromObj, toObj);
         */
    }
}
/* 
void Field::battle(CombatObject *object1, CombatObject *object2)
{
    double damage1 = object1->getDamage(),
           damage2 = object2->getDamage(),
           armor1 = object1->getArmor(),
           armor2 = object2->getArmor();

    // // // std::cout << object1->getHealth() << std::endl;
    // // // std::cout << object2->getHealth() << std::endl;

    object1->underAttack(damage2, armor2);
    object2->underAttack(damage1, armor1);

    // // // std::cout << object1->getHealth() << std::endl;
    // // // std::cout << object2->getHealth() << std::endl;
}

void Field::interactionObjObj(Object *object1, Object *object2)
{
    if (object1 == nullptr || object2 == nullptr)
        return;
    std::string resGenerators = "Farm GoldMine Sawmill";
    if (resGenerators.find(object2->getObjectType()) != std::string::npos)
    {
        *object2 << object1;
        return;
    }

    // *((NeutralObject *)object2) + (CombatObject *)object1;

    if (object1->getPlayerID() == object2->getPlayerID())
    {
        // // std::cout << "You can not attack allies."
              //    <<std::endl
              //    <<"*in file \"Field\"\n";
        return;
    }
    else
        battle((CombatObject *)object1, (CombatObject *)object2);
}
 */

v8::Local<v8::Array> Field::getLandscapesData()
{
    v8::Local<v8::Array> rows = Nan::New<v8::Array>();
    for (unsigned int rowNumber = 0; rowNumber < rowsQuantity; rowNumber++)
    {
        v8::Local<v8::Array> columns = Nan::New<v8::Array>();
        for (unsigned int columnNumber = 0; columnNumber < columnsQuantity; columnNumber++)
        {
            SetArrProperty(columns, columnNumber, getLandscapeData(rowNumber, columnNumber));
        }
        SetArrProperty(rows, rowNumber, columns);
    }
    return rows;
}

v8::Local<v8::Array> Field::getObjectsData()
{
    v8::Local<v8::Array> rows = Nan::New<v8::Array>();
    for (unsigned int rowNumber = 0; rowNumber < rowsQuantity; rowNumber++)
    {
        v8::Local<v8::Array> columns = Nan::New<v8::Array>();
        for (unsigned int columnNumber = 0; columnNumber < columnsQuantity; columnNumber++)
        {
            SetArrProperty(columns, columnNumber, getObjectData(rowNumber, columnNumber));
        }
        SetArrProperty(rows, rowNumber, columns);
    }
    return rows;
}

v8::Local<v8::Object> Field::getObjectData(unsigned int rowNumber, unsigned int columnNumber)
{
    // // std::cout << "##########Field::getObjectData1111\n";

    // return getObjectData(fieldGrid[rowNumber][columnNumber].getObject());
    v8::Local<v8::Object> data = Nan::New<v8::Object>();
    std::string objectType("empty_");
    Object *object = fieldGrid[rowNumber][columnNumber].getObject();

    if (object != nullptr)
        data = object->getFullInfo();
    else
        SetObjProperty(data, "objectType", objectType);
    SetObjProperty(data, "x", columnNumber);
    SetObjProperty(data, "y", rowNumber);

    return data;
}

v8::Local<v8::Object> Field::getObjectData(Object *object)
{
    // // std::cout << "##########Field::getObjectData\n";

    for (unsigned int rowNumber = 0; rowNumber < rowsQuantity; rowNumber++)
        for (unsigned int columnNumber = 0; columnNumber < columnsQuantity; columnNumber++)
            if (object == fieldGrid[rowNumber][columnNumber].getObject())
            {
                // // std::cout << rowNumber << "_" << columnNumber << "##########Field::getObjectData\n";
                return getObjectData(rowNumber, columnNumber);
            }
}

v8::Local<v8::Object> Field::getLandscapeData(unsigned int rowNumber, unsigned int columnNumber)
{
    v8::Local<v8::Object> data = Nan::New<v8::Object>();
    SetObjProperty(data, "lanscapeType", fieldGrid[rowNumber][columnNumber].getLandscape()->getLandscapeType());
    return data;
}

void Field::eventHandler(Event *event)
{
    if (event->getSEventId() == "object death")
    {
        // // std::cout << "*Field* Event: \"" << event->getSEventId() << "\" started \n";
        removeObject((Object *)event->getSource());
    }
    else if (event->getSEventId() == "object updated")
    {
        for (unsigned int rowNumber = 0; rowNumber < rowsQuantity; rowNumber++)
            for (unsigned int columnNumber = 0; columnNumber < columnsQuantity; columnNumber++)
                if (fieldGrid[rowNumber][columnNumber].getObject() == (Object *)event->getSource())
                {
                    fireEvent("object updated", getObjectData(rowNumber, columnNumber));
                }
    }
};

//memento
v8::Local<v8::Object> Field::getFullInfo()
{
    v8::Local<v8::Object> info = Nan::New<v8::Object>();
    v8::Isolate *isolate = info->GetIsolate();
    v8::Local<v8::Context> context = v8::Context::New(isolate);

    v8::Local<v8::Array> landscapesArray = Nan::New<v8::Array>();
    v8::Local<v8::Array> unitsArray = Nan::New<v8::Array>();
    v8::Local<v8::Array> resGensArray = Nan::New<v8::Array>();
    for (unsigned int i = 0; i < rowsQuantity; i++)
    {
        for (unsigned int j = 0; j < columnsQuantity; j++)
        {

            SetArrProperty(landscapesArray, i * columnsQuantity + j, fieldGrid[i][j].getLandscape()->getLandscapeType());
            if (fieldGrid[i][j].getObject() != nullptr)
            {
                // // std::cout << "!!!!!" << fieldGrid[i][j].getObject()->getObjectType();
                unsigned int objectType = fieldGrid[i][j].getObject()->getObjectType();
                if (objectType > 0 && objectType < 7)
                {
                    // // std::cout << "############Field::getFullInfo\n";
                    SetArrProperty(unitsArray, unitsArray->Length(), getObjectData(i, j));
                }
                else if (objectType >= 7)
                {
                    SetArrProperty(resGensArray, resGensArray->Length(), getObjectData(i, j));
                }
            }
        }
    }
    SetObjProperty(info, "landscapes", landscapesArray);
    SetObjProperty(info, "units", unitsArray);
    SetObjProperty(info, "resGens", resGensArray);
    SetObjProperty(info, "rowsQuantity", rowsQuantity);
    SetObjProperty(info, "columnsQuantity", columnsQuantity);
    SetObjProperty(info, "currentObjectsQuantity", currentObjectsQuantity);
    SetObjProperty(info, "maximumObjectsQuantity", maximumObjectsQuantity);
    // // std::cout << "1############Field::getFullInfo\n";

    return info;
}