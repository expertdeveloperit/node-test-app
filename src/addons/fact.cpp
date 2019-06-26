#include <nan.h>

void Factorial(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (info.Length() < 1) {
    Nan::ThrowTypeError("Wrong number of arguments");
    return;
  }
  if (!info[0]->IsNumber()) {
    Nan::ThrowTypeError("Wrong arguments");
    return;
  }
  int number = info[0]->ToNumber(Nan::GetCurrentContext()).ToLocalChecked()->Value();
  int i;
  double fact=1; 

  for(i=1;i<=number;i++){    
      fact=fact*i;    
  } 

  v8::Local<v8::Number> num = Nan::New(fact);

  info.GetReturnValue().Set(num);
}

void Init(v8::Local<v8::Object> exports) {
  exports->Set(Nan::New("fact").ToLocalChecked(),
               Nan::New<v8::FunctionTemplate>(Factorial)->GetFunction());
}

NODE_MODULE(addon, Init)