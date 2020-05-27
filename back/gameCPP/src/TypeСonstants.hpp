
#ifndef TypeСonstants_hpp
#define TypeСonstants_hpp
enum eTask
{
    ADD_ROOM,   //in game
    ADD_PLAYER, //in room
    ADD_OBJ,    //\/ \/ \/ eObjectType
    MOVE,       //in player
    UPD_LAND,   //in editor
    GET_FIELD,  //in room
    SAVE_ROOM,  //add
    LOAD_ROOM,  //add
};

enum eLandscapeType
{
    FOREST,
    MOUNTAIN,
    PLAIN,
    SWAMP,

};

enum eObjectType
{
    COMB_OBJ, //in player
    NEUT_OBJ, //in editor
};

enum eCombatObjectType //in player
{
    BASE,
    ARCH_TANK,
    ARCH_DPS,
    INF_TANK,
    INF_DPS,
    CAV_TANK,
    CAV_DPS,
};

enum eNeutralObjectType //in room
{
    GEN_GOLD,
    GEN_SAWMILL,
    GEN_FARM

};
#endif /* TypeСonstants_hpp */
