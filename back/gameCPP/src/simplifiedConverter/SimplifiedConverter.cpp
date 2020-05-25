#include "SimplifiedConverter.hpp"
// SimplifiedConverter::SimplifiedConverter(v8::Isolate *isolate)
// {
//     this->isolate = isolate;
// }
// SimplifiedConverter::SimplifiedConverter()
// {
// }
// SimplifiedConverter::~SimplifiedConverter()
// {
// }

// v8::Isolate *SimplifiedConverter::GetIsolate()
// {
//     return this->isolate;
// }
// void SimplifiedConverter::SetIsolate(v8::Isolate *isolate)
// {
//     this->isolate = isolate;
// }

bool SimplifiedConverter::GetObjField(v8::Local<v8::Object> obj, std::string propertyName, unsigned int &value)
{
    v8::Isolate *isolate = obj->GetIsolate();

    if (obj->IsObject())
    {
        if (obj->Has(v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked()))
        {
            v8::Local<v8::Value> propertyValue;
            Nan::GetRealNamedProperty(obj, v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked()).ToLocal(&propertyValue);
            if (propertyValue->IsNumber())
            {
                v8::Local<v8::Number> propertyUint32 = propertyValue->ToNumber(isolate);
                value = static_cast<unsigned int>(propertyUint32->Value() + 0.5);
                return true;
            }
        }
    }
    return false;
}

bool SimplifiedConverter::GetObjField(v8::Local<v8::Object> obj, std::string propertyName, double &value)
{
    v8::Isolate *isolate = obj->GetIsolate();

    if (obj->IsObject())
    {
        if (obj->Has(v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked()))
        {
            v8::Local<v8::Value> propertyValue;
            Nan::GetRealNamedProperty(obj, v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked()).ToLocal(&propertyValue);
            if (propertyValue->IsNumber())
            {
                v8::Local<v8::Number> propertyUint32 = propertyValue->ToNumber(isolate);
                value = propertyUint32->Value();
                return true;
            }
        }
    }
    return false;
}

bool SimplifiedConverter::GetObjField(v8::Local<v8::Object> obj, std::string propertyName, std::string &value)
{

    v8::Isolate *isolate = obj->GetIsolate();

    if (obj->IsObject())
    {
        if (obj->Has(v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked()))
        {
            v8::Local<v8::Value> propertyValue;
            Nan::GetRealNamedProperty(obj, v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked()).ToLocal(&propertyValue);
            v8::Local<v8::String> propertyString = propertyValue->ToString(isolate);
            v8::String::Utf8Value expr(propertyString);
            std::string propertyStdString = (std::string(*expr));
            value = propertyStdString;
            return true;
        }
    }
    return false;
}

bool SimplifiedConverter::GetObjField(v8::Local<v8::Object> obj, std::string propertyName, v8::Local<v8::Object> &value)
{
    v8::Isolate *isolate = obj->GetIsolate();

    if (obj->IsObject())
    {
        if (obj->Has(v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked()))
        {
            v8::Local<v8::Value> propertyValue;
            Nan::GetRealNamedProperty(obj, v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked()).ToLocal(&propertyValue);
            if (propertyValue->IsObject())
            {
                v8::Local<v8::Object> propertyObject = propertyValue->ToObject(isolate);
                value = propertyObject;
                return true;
            }
        }
    }
    return false;
}

bool SimplifiedConverter::SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, unsigned int value)
{
    obj->Set(Nan::New(propertyName.c_str()).ToLocalChecked(), Nan::New(value));
    return true;
}

bool SimplifiedConverter::SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, double value)
{
    obj->Set(Nan::New(propertyName.c_str()).ToLocalChecked(), Nan::New(value));
    return true;
}

bool SimplifiedConverter::SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, std::string value)
{
    v8::Isolate *isolate = obj->GetIsolate();

    if (obj->IsObject())
    {
        obj->Set(v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked(), v8::String::NewFromUtf8(isolate, value.c_str(), v8::NewStringType::kNormal).ToLocalChecked());
        return true;
    }
    return false;
}

bool SimplifiedConverter::SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, v8::Local<v8::Array> value)
{
    v8::Isolate *isolate = obj->GetIsolate();

    if (obj->IsObject())
    {
        obj->Set(v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked(), value);
        return true;
    }
    return false;
}

bool SimplifiedConverter::SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, v8::Local<v8::Object> value)
{
    v8::Isolate *isolate = obj->GetIsolate();

    if (obj->IsObject())
    {
        obj->Set(v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked(), value);
        return true;
    }
    return false;
}

bool SimplifiedConverter::SetObjField(v8::Local<v8::Object> &obj, std::string propertyName, v8::Local<v8::Value> value)
{
    v8::Isolate *isolate = obj->GetIsolate();

    if (obj->IsObject())
    {
        obj->Set(v8::String::NewFromUtf8(isolate, propertyName.c_str(), v8::NewStringType::kNormal).ToLocalChecked(), value);
        return true;
    }
    return false;
}

bool SimplifiedConverter::SetObjField(v8::Local<v8::Object> &obj, unsigned int index, v8::Local<v8::Object> value)
{
    v8::Isolate *isolate = obj->GetIsolate();

    if (obj->IsObject())
    {
        obj->Set(index, value);
        return true;
    }
    return false;
}

bool SimplifiedConverter::SetArrField(v8::Local<v8::Array> &array, unsigned int index, std::string value)
{
    v8::Isolate *isolate = array->GetIsolate();

    if (array->IsArray())
    {
        array->Set(index, v8::String::NewFromUtf8(isolate, value.c_str(), v8::NewStringType::kNormal).ToLocalChecked());
        return true;
    }
    return false;
}

bool SimplifiedConverter::SetArrField(v8::Local<v8::Array> &array, unsigned int index, v8::Local<v8::Object> value)
{
    v8::Isolate *isolate = array->GetIsolate();

    if (array->IsArray())
    {
        array->Set(index, value);
        return true;
    }
    return false;
}

bool SimplifiedConverter::SetArrField(v8::Local<v8::Array> &array, unsigned int index, v8::Local<v8::Array> value)
{
    v8::Isolate *isolate = array->GetIsolate();

    if (array->IsArray())
    {
        array->Set(index, value);
        return true;
    }
    return false;
}

std::string SimplifiedConverter::JSONStringified(v8::Local<v8::Object> obj)
{
    Nan::JSON NanJSON;
    Nan::MaybeLocal<v8::String> result = NanJSON.Stringify(obj);
    v8::Local<v8::String> stringified = result.ToLocalChecked();
    v8::String::Utf8Value strUtf8(stringified);
    return std::string(*strUtf8);
}

v8::Local<v8::Object> SimplifiedConverter::JSONParse(std::string json_string)
{
    Nan::JSON NanJSON;
    Nan::MaybeLocal<v8::Value> result = NanJSON.Parse(Nan::New(json_string.c_str()).ToLocalChecked());
    v8::Local<v8::Value> val = result.ToLocalChecked();
    return val->ToObject();
}
