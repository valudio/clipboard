#include <nan.h>
#include <iostream>
#include <string>
#include "selectedText.hpp"

using namespace v8;

void Method(const Nan::FunctionCallbackInfo<Value>& info) {
    SelectedText::copy();
    auto result = SelectedText::getTextFromClipboard();
    info.GetReturnValue().Set(Nan::New(result).ToLocalChecked());
}

void Init(Local<Object> exports) {
    exports->Set(Nan::New("getSelectedText").ToLocalChecked(),
        Nan::New<FunctionTemplate>(Method)->GetFunction());
}

NODE_MODULE(getSelectedText, Init) // no need for semi-colon here
