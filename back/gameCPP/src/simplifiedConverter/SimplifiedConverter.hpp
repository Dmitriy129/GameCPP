#ifndef SimplifiedConverter_hpp
#define SimplifiedConverter_hpp

#include <iostream>
#include <node.h>
#include <nan.h>
#include <node_object_wrap.h>

class SimplifiedConverter
{
protected:
    // v8::Isolate *isolate;

public:
    // SimplifiedConverter(v8::Isolate *isolate);
    // SimplifiedConverter();
    // ~SimplifiedConverter();
    // v8::Isolate *GetIsolate();
    // void SetIsolate(v8::Isolate *isolate);

    //getters
    bool GetObjField(v8::Local<v8::Object> obj, std::string propertyName, unsigned int &value);          //Uint32
    bool GetObjField(v8::Local<v8::Object> obj, std::string propertyName, double &value);                //double
    bool GetObjField(v8::Local<v8::Object> obj, std::string propertyName, std::string &value);           //String
    bool GetObjField(v8::Local<v8::Object> obj, std::string propertyName, v8::Local<v8::Object> &value); //v8::Object

    //setters
    bool SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, unsigned int value);          //String
    bool SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, double value);                //double
    bool SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, std::string value);           //String
    bool SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, v8::Local<v8::Array> value);  //v8::Array
    bool SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, v8::Local<v8::Object> value); //v8::Object
    bool SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, v8::Local<v8::Value> value);  //v8::Value
    bool SetObjField(v8::Local<v8::Object> &obj, unsigned int index, v8::Local<v8::Object> value);       //v8::Object

    bool SetArrField(v8::Local<v8::Array> &array, unsigned int index, std::string value); //v8::String
    // bool SetArrField(v8::Local<v8::Array> &array, unsigned int index, v8::Local<v8::String> value); //v8::String
    bool SetArrField(v8::Local<v8::Array> &array, unsigned int index, v8::Local<v8::Object> value); //v8::Object
    bool SetArrField(v8::Local<v8::Array> &array, unsigned int index, v8::Local<v8::Array> value);  //v8::Array

    std::string JSONStringified(v8::Local<v8::Object> obj);
    v8::Local<v8::Object> JSONParse(std::string json_string);
};
#endif /* SimplifiedConverter_hpp */