#include <nan.h>
#include <iostream>
#include <string>
#include <atlstr.h>
#include "selectedText.hpp"

using namespace v8;
using namespace std;

void copy(const Nan::FunctionCallbackInfo<Value> &info)
{
    SelectedText::copy();
}

void paste(const Nan::FunctionCallbackInfo<Value> &info)
{
    SelectedText::paste();
}

void getFromClipboard(const Nan::FunctionCallbackInfo<Value> &info)
{
    auto result = SelectedText::getTextFromClipboard();
    info.GetReturnValue().Set(Nan::New(result).ToLocalChecked());
}

void setToClipboard(const Nan::FunctionCallbackInfo<Value> &info)
{
    if (info.Length() < 1)
    {
        Nan::ThrowTypeError("Wrong number of arguments");
        return;
    }

    if (!info[0]->IsString())
    {
        Nan::ThrowTypeError("Wrong argument");
    }

    String::Utf8Value param1(info[0]->ToString());
    string myString = string(*param1);
    CStringW cstr(myString.c_str());
    SelectedText::setTextToClipboard(cstr);
}

void getSelectedText(const Nan::FunctionCallbackInfo<Value> &info)
{
    auto prevTextInClipboard = SelectedText::getTextFromClipboard();
    SelectedText::copy();
    auto result = SelectedText::getTextFromClipboard();
    CStringW cstr(prevTextInClipboard.c_str());
    SelectedText::setTextToClipboard(cstr);
    info.GetReturnValue().Set(Nan::New(result).ToLocalChecked());
}

void Init(Local<Object> exports)
{
    exports->Set(Nan::New("copy").ToLocalChecked(),
                 Nan::New<FunctionTemplate>(copy)->GetFunction());

    exports->Set(Nan::New("paste").ToLocalChecked(),
                 Nan::New<FunctionTemplate>(copy)->GetFunction());

    exports->Set(Nan::New("getFromClipboard").ToLocalChecked(),
                 Nan::New<FunctionTemplate>(getFromClipboard)->GetFunction());

    exports->Set(Nan::New("setToClipboard").ToLocalChecked(),
                 Nan::New<FunctionTemplate>(setToClipboard)->GetFunction());

    exports->Set(Nan::New("getSelectedText").ToLocalChecked(),
                 Nan::New<FunctionTemplate>(getSelectedText)->GetFunction());
}

NODE_MODULE(getSelectedText, Init) // no need for semi-colon here
