#include "FieldCell.hpp"

FieldCell::FieldCell()
{
    this->object = nullptr;
    int val = rand() % 4;
    // this->landscape = val == 1 ? new LandscapeProxy("Plain") : val == 2 ? new LandscapeProxy("Mountain") : val == 3 ? new LandscapeProxy("Swamp") : new LandscapeProxy("Forest");
    // this->landscape = new LandscapeProxy("Plain");
    this->landscape = new LandscapeProxy(0);
}

FieldCell::FieldCell(Object *object, Landscape *landscape)
{
    this->object = object;
    this->landscape = landscape;
}

FieldCell::~FieldCell()
{
    delete object;
    delete landscape;
}
void FieldCell::setObject(Object *object)
{
    this->object = object;
}

void FieldCell::setLandscape(Landscape *landscape)
{
    this->landscape = landscape;
}

Object *FieldCell::getObject()
{
    return this->object;
}
Landscape *FieldCell::getLandscape()
{
    return this->landscape;
}
