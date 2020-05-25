#include "NeutralObject.hpp"

void NeutralObject::eventHandler(Event *event) {}

v8::Local<v8::Object> NeutralObject::getInfo()
{
    v8::Local<v8::Object> info = Object::getInfo();

    return info;
}