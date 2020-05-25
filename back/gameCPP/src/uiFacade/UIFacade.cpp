#include "UIFacade.hpp"

namespace demo
{

UIFacade::UIFacade()
{
    // std::cout << "#**UIFacade con start\n";

    this->game = new Game();

    // std::cout << "#**UIFacade con 1\n";

    logger = new LoggerProxy("file", "GameLogs");
    // logger = new LoggerProxy("console");

    // std::cout << "#**UIFacade con 2\n";

    game->attachEvent("object updated", this);
    game->attachEvent("tabel of GameRooms update", this);
    game->attachEvent("get full field", this);

    // game->attachEvent("all events", logger);
    game->attachEvent("log", logger);
    this->attachEvent("command", logger);
    // std::cout << "#**UIFacade con eend\n";
}
UIFacade::~UIFacade()
{
    delete this->game;
    delete this->logger;
}

void UIFacade::Init(v8::Local<v8::Object> exports)
{

    v8::Isolate *isolate = exports->GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::ObjectTemplate> addon_data_tpl = v8::ObjectTemplate::New(isolate);
    addon_data_tpl->SetInternalFieldCount(1);
    v8::Local<v8::Object> addon_data = addon_data_tpl->NewInstance(context).ToLocalChecked();

    v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New, addon_data);
    tpl->SetClassName(v8::String::NewFromUtf8(isolate, "UIFacade", v8::NewStringType::kNormal).ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    /* PROTOTYPE METHODS */

    NODE_SET_PROTOTYPE_METHOD(tpl, "sendRequest", sendRequest);

    /* * * * * * * * * * */

    v8::Local<v8::Function> constructor = tpl->GetFunction(context).ToLocalChecked();
    addon_data->SetInternalField(0, constructor);
    exports->Set(context, v8::String::NewFromUtf8(isolate, "UIFacade", v8::NewStringType::kNormal).ToLocalChecked(), constructor).FromJust();
}

void UIFacade::New(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    if (args.IsConstructCall())
    {
        UIFacade *obj = new UIFacade();
        obj->Wrap(args.This());
        args.GetReturnValue().Set(args.This());
    }
    else
    {
        const int argc = 1;
        v8::Local<v8::Value> argv[argc] = {args[0]};
        v8::Local<v8::Function> cons =
            args.Data().As<v8::Object>()->GetInternalField(0).As<v8::Function>();
        v8::Local<v8::Object> result =
            cons->NewInstance(context, argc, argv).ToLocalChecked();
        args.GetReturnValue().Set(result);
    }
}

void UIFacade::sendRequest(const v8::FunctionCallbackInfo<v8::Value> &args)
{
    v8::Isolate *isolate = args.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> request = v8::Local<v8::Value>::Cast(args[0]);

    UIFacade *uiFacade = ObjectWrap::Unwrap<UIFacade>(args.Holder());

    uiFacade->response = v8::Array::New(isolate);
    uiFacade->fireEvent("command", request);
    // std::cout << "#1#\n";

    GameCommand *gameCommand = new GameCommand(uiFacade->game /* , isolate */);
    gameCommand->execute(request);

    delete gameCommand;

    // args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, "COMMAND EXEC"));
    args.GetReturnValue().Set(uiFacade->response);
}

void UIFacade::eventHandler(Event *event)
{
    // std::cout << "#UI ev1#\n";

    v8::Local<v8::Object> objResponse = Nan::New<v8::Object>();
    // std::cout << "#UI ev2#\n";

    SetObjField(objResponse, "eventType", event->getSEventId());
    SetObjField(objResponse, "data", event->getData());
    // std::cout << "#UI ev3#\n";

    SetArrField(this->response, this->response->Length(), objResponse);
    // std::cout << "#UI ev4#\n";
};

} // namespace demo