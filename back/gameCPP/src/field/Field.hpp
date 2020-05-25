#ifndef field_hpp
#define field_hpp

#include <stdio.h>
#include <iostream>
#include "FieldCell.hpp"
#include "../objects/Object.hpp"
#include "../objects/combatObject/CombatObject.hpp"
#include "../objects/neutralObject/NeutralObject.hpp"
#include "../eventProvider/EventProvider.hpp"
#include "../mediator/Mediator.hpp"

// class FieldMediator;
class Unit;
class Base;
class Field : public EventProvider
{
private:
    FieldCell **fieldGrid;

    unsigned int rowsQuantity;
    unsigned int columnsQuantity;
    unsigned int currentObjectsQuantity;
    unsigned int maximumObjectsQuantity;
    Mediator *mediator;

    // void battle(CombatObject *obj1, CombatObject *obj2);
    // void interactionObjObj(Object *object1, Object *object2);

public:
    Field(unsigned int rowsQuantity, unsigned int columnsQuantity, unsigned int maximumObjectsQuantity, Mediator *mediator);
    Field(const Field &lastField);
    Field(Field &&lastField);
    ~Field();

    void setRowsQuantity(unsigned int rowsQuantity);
    void setColumnsQuantity(unsigned int columnsQuantity);
    void setMaximumObject(unsigned int maximumObjectsQuantity);
    void setCurrentObject(unsigned int currentObjectsQuantity);
    void setMediator(Mediator *mediator);

    unsigned int getRowsQuantity() const;
    unsigned int getColumnsQuantity() const;
    unsigned int getMaximumObject() const;
    unsigned int getCurrentObject() const;
    std::vector<std::string> getLandscapes();
    std::vector<std::string> getObjects();

    Mediator *getMediator() const;

    void addObject(unsigned int rowNumber, unsigned int columnNumber, Object *object);
    void updateLandscape(unsigned int rowNumber, unsigned int columnNumber, std::string landscapeType /* Landscape *landscape */);
    void removeObject(Object *object);
    void removeObject(unsigned int rowNumber, unsigned int columnNumber);
    void moveObject(unsigned int fromRowNumber, unsigned int fromColumnNumber, unsigned int toRowNumber, unsigned int toColumnNumber);

    FieldCell &getFieldCell(unsigned int rowNumber, unsigned int columnNumber);

    v8::Local<v8::Array> getLandscapesData();
    v8::Local<v8::Array> getObjectsData();
    v8::Local<v8::Object> getLandscapeData(unsigned int rowNumber, unsigned int columnNumber);
    v8::Local<v8::Object> getObjectData(unsigned int rowNumber, unsigned int columnNumber);
    void eventHandler(Event *event) override;

    //memento
    v8::Local<v8::Object> getFullInfo();
};

#endif /* field_hpp */
