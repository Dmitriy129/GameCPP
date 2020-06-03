#include <iostream>

#include "objects/combatObject/base/Base.hpp"
#include "field/Field.hpp"
#include "uuid/UUID.hpp"
#include "objects/neutralObject/NeutralObjectFactory.hpp"
#include "mediator/fieldMediator/FieldMediator.hpp"

int main()
{

    return 0;
}
/* 
void fun1()
{

    CombatObjectTypeFactory *combatObjectTypeFactory = new CombatObjectTypeFactory;

    Base *base1 = new Base("playerID1", 10, 50.0, 5.0, combatObjectTypeFactory);
    Base *base2 = new Base("playerID2", 10, 50, 5, combatObjectTypeFactory);

    Field *alpha = new Field(2000, 2000, 1000, new FieldMediator);

    UUID *uuidGen = new UUID;

    alpha->addObject(1, 1, base1);
    alpha->addObject(19, 19, base2);

    alpha->addObject(3, 3, base1->createUnit("archer", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    alpha->addObject(10, 10, base2->createUnit("archer", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));

    alpha->addObject(5, 5, base1->createUnit("cavalry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    alpha->addObject(5, 5, base1->createUnit("cavalry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));

    alpha->addObject(4, 4, base2->createUnit("archer", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    alpha->updateLandscape(10, 10, "Forest");

    
    
    

    
    

    alpha->moveObject(3, 3, 10, 10);
    alpha->moveObject(3, 3, 4, 4);
    alpha->moveObject(3, 3, 4, 4);
    alpha->moveObject(3, 3, 4, 4);
    alpha->moveObject(4, 4, 3, 3);

    
}

void fun2()
{
    NeutralObjectFactory *NeutralObjectFactory = new NeutralObjectFactory();
    CombatObjectTypeFactory *combatObjectTypeFactory = new CombatObjectTypeFactory();
    Field *beta = new Field(5000, 5000, 1000, new FieldMediator);

    Base *base1 = new Base("playerID1", 100, 50.0, 5.0, combatObjectTypeFactory);
    Base *base2 = new Base("playerID2", 100, 50, 5, combatObjectTypeFactory);

    
    UUID *uuidGen = new UUID;

    
    
    
    

    

    beta->addObject(3, 3, base1->createUnit("archer", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(10, 10, base2->createUnit("archer", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(5, 5, base1->createUnit("cavalry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(5, 5, base1->createUnit("infantry", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(4, 4, base2->createUnit("archer", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    

    
    beta->updateLandscape(10, 10, "Forest");
    

    beta->updateLandscape(20, 20, "Mountain");
    

    beta->updateLandscape(30, 30, "Swamp");
    

    

    
    beta->addObject(101, 101, base1->createUnit("archer", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(112, 112, base1->createUnit("archer", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(211, 211, base1->createUnit("cavalry", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(212, 212, base1->createUnit("cavalry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(311, 311, base1->createUnit("infantry", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(312, 312, base1->createUnit("infantry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    
    beta->addObject(121, 121, base2->createUnit("archer", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(122, 122, base2->createUnit("archer", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(221, 221, base2->createUnit("cavalry", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(222, 222, base2->createUnit("cavalry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(321, 321, base2->createUnit("infantry", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(322, 322, base2->createUnit("infantry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    

    beta->updateLandscape(100, 100, "Forest");
    

    beta->updateLandscape(200, 200, "Mountain");
    

    beta->updateLandscape(300, 300, "Swamp");
    

    beta->updateLandscape(400, 400, "Plain");
    

    
    beta->moveObject(221, 221, 100, 100);
    beta->moveObject(221, 221, 1221, 1221);

    
    beta->moveObject(322, 322, 100, 100);
    beta->moveObject(322, 322, 1322, 1322);

    
    beta->moveObject(112, 112, 200, 200);
    beta->moveObject(112, 112, 1112, 1112);

    
    beta->moveObject(122, 122, 300, 300);
    beta->moveObject(122, 122, 1122, 1122);

    
    beta->moveObject(321, 321, 300, 300);
    beta->moveObject(321, 321, 1321, 1321);

    

    beta->addObject(2001, 2001, base1->createUnit("infantry", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    beta->updateLandscape(2001, 2001, "Forest");
    
    

    beta->addObject(2002, 2002, base1->createUnit("infantry", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    beta->updateLandscape(2002, 2002, "Swamp");
    
    

    beta->addObject(2003, 2003, base1->createUnit("infantry", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    beta->updateLandscape(2003, 2003, "Swamp");
    
    

    beta->addObject(1001, 1001, base2->createUnit("archer", "DPS", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(1002, 1002, base2->createUnit("infantry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->addObject(1003, 1003, base2->createUnit("cavalry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    

    beta->moveObject(1001, 1001, 2001, 2001);
    beta->moveObject(1001, 1001, 3001, 3001);

    beta->moveObject(1002, 1002, 2002, 2002);
    beta->moveObject(1002, 1002, 3002, 3002);

    beta->moveObject(1003, 1003, 2003, 2003);
    beta->moveObject(1003, 1003, 3003, 3003);

    

    beta->addObject(4001, 4001, base2->createUnit("cavalry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    
    beta->addObject(4002, 4002, base1->createUnit("infantry", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    
    beta->addObject(4003, 4003, base2->createUnit("archer", "TANK", uuidGen->generateUUID(), combatObjectTypeFactory));
    
    beta->addObject(4000, 4000, NeutralObjectFactory->createResourceGenerator("GoldMine"));
    

    
    beta->moveObject(4001, 4001, 4000, 4000);
    beta->moveObject(4002, 4002, 4000, 4000);
    beta->moveObject(4003, 4003, 4000, 4000);
    
} */