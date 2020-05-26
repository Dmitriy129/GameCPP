#include "Object.hpp"

std::string Object::getObjectType() { return objectType; }
std::string Object::getPlayerID() { return playerID; }

v8::Local<v8::Object> Object::getFullInfo()
{
    v8::Local<v8::Object> info = Nan::New<v8::Object>();

    SetObjField(info, "objectType", objectType);
    SetObjField(info, "ID", ID);
    SetObjField(info, "playerID", playerID);

    return info;
}
