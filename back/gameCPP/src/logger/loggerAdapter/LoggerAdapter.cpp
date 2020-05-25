
#include "LoggerAdapter.hpp"

LoggerAdapter::LoggerAdapter()
{
    this->status = true;
}

LoggerAdapter::LoggerAdapter(bool status)
{
    this->status = status;
}

std::string
LoggerAdapter::adaptFormat(v8::Local<v8::Object> objLog)
{

    //strLogType
    std::string strLogType;
    GetObjField(objLog, "logType", strLogType);

    //strLogData
    std::string strLogData;
    v8::Local<v8::Object> objLogData = Nan::New<v8::Object>();
    GetObjField(objLog, "data", objLogData);
    strLogData = JSONStringified(objLogData);

    //strLogTime
    std::time_t logTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::string strLogTime(std::ctime(&logTime));

    //strLog;
    std::string strLog = strLogType + ";" + strLogData + ";" + strLogTime;

    return strLog;
}

void LoggerAdapter::setStatus(bool status)
{
    this->status = status;
}

bool LoggerAdapter::getStatus()
{
    return this->status;
}
