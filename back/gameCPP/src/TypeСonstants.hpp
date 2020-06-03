
#ifndef TypeСonstants_hpp
#define TypeСonstants_hpp
enum eTask
{
    ADD_ROOM,   //in game
    ADD_PLAYER, //in room
    ADD_OBJ,    //\/ \/ \/ eObjectType
    MOVE,       //in player
    UPD_LAND,   //in editor
    GET_FULL,  //in room
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

enum eCombNeutType
{
    COMB_OBJ, //in player
    NEUT_OBJ, //in editor
};

enum eObjectType //in player
{
    BASE,
    ARCH_TANK,
    ARCH_DPS,
    INF_TANK,
    INF_DPS,
    CAV_TANK,
    CAV_DPS,
    GEN_GOLD,
    GEN_SAWMILL,
    GEN_FARM,
};

enum eResourceType
{
    GOLD,
    WOOD,
    FOOD,
};

enum eRule
{
    RULE1,
    RULE2,
};

#endif /* TypeСonstants_hpp */
