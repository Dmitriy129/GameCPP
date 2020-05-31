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
    bool GetObjProperty(v8::Local<v8::Object> obj, std::string propertyName, unsigned int &value);          //Uint32
    bool GetObjProperty(v8::Local<v8::Object> obj, std::string propertyName, double &value);                //double
    bool GetObjProperty(v8::Local<v8::Object> obj, std::string propertyName, std::string &value);           //String
    bool GetObjProperty(v8::Local<v8::Object> obj, std::string propertyName, v8::Local<v8::Object> &value); //v8::Object
    bool GetObjProperty(v8::Local<v8::Object> obj, std::string propertyName, v8::Local<v8::Array> &value);  //v8::Array

    //setters
    bool SetObjProperty(v8::Local<v8::Object> &obj, std::string propertyName, unsigned int value);          //Uint
    bool SetObjProperty(v8::Local<v8::Object> &obj, std::string propertyName, double value);                //double
    bool SetObjProperty(v8::Local<v8::Object> &obj, std::string propertyName, std::string value);           //String
    bool SetObjProperty(v8::Local<v8::Object> &obj, std::string propertyName, v8::Local<v8::Array> value);  //v8::Array
    bool SetObjProperty(v8::Local<v8::Object> &obj, std::string propertyName, v8::Local<v8::Object> value); //v8::Object
    bool SetObjProperty(v8::Local<v8::Object> &obj, std::string propertyName, v8::Local<v8::Value> value);  //v8::Value
    bool SetObjProperty(v8::Local<v8::Object> &obj, unsigned int index, v8::Local<v8::Object> value);       //v8::Object

    bool SetArrProperty(v8::Local<v8::Array> &array, unsigned int index, unsigned int value); //unsigned int
    bool SetArrProperty(v8::Local<v8::Array> &array, unsigned int index, std::string value);  //std:::string
    // bool SetArrProperty(v8::Local<v8::Array> &array, unsigned int index, v8::Local<v8::String> value); //v8::String
    bool SetArrProperty(v8::Local<v8::Array> &array, unsigned int index, v8::Local<v8::Object> value); //v8::Object
    bool SetArrProperty(v8::Local<v8::Array> &array, unsigned int index, v8::Local<v8::Array> value);  //v8::Array

    bool GetArrProperty(v8::Local<v8::Array> obj, unsigned int index, unsigned int &value);          //Uint32
    bool GetArrProperty(v8::Local<v8::Array> obj, unsigned int index, v8::Local<v8::Object> &value); //v8::Object

    std::string JSONStringified(v8::Local<v8::Object> obj);
    v8::Local<v8::Object> JSONParse(std::string json_string);
};
#endif /* SimplifiedConverter_hpp */