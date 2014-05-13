/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/index_time.h"

using namespace v8;
using namespace node;

GitIndexTime::GitIndexTime(git_index_time *raw) {
  this->raw = raw;
}

GitIndexTime::~GitIndexTime() {
  free(this->raw);
}

void GitIndexTime::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("IndexTime"));


  NODE_SET_PROTOTYPE_METHOD(tpl, "seconds", Seconds);
  NODE_SET_PROTOTYPE_METHOD(tpl, "nanoseconds", Nanoseconds);

  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("IndexTime"), _constructor_template);
}

NAN_METHOD(GitIndexTime::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_index_time is required.");
  }

  //GitIndexTime* object = new GitIndexTime((git_index_time *) External::Unwrap(args[0]));
  GitIndexTime* object = ObjectWrap::Unwrap<GitIndexTime>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitIndexTime::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitIndexTime::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitIndexTime::constructor_template->NewInstance(1, argv));
}

git_index_time *GitIndexTime::GetValue() {
  return this->raw;
}


NAN_METHOD(GitIndexTime::Seconds) {
  NanScope();
    Handle<Value> to;

  git_time_t seconds =
    ObjectWrap::Unwrap<GitIndexTime>(args.This())->GetValue()->seconds;

    to = NanNew<Uint32>(seconds);
  return scope.Close(to);
}

NAN_METHOD(GitIndexTime::Nanoseconds) {
  NanScope();
    Handle<Value> to;

  unsigned int nanoseconds =
    ObjectWrap::Unwrap<GitIndexTime>(args.This())->GetValue()->nanoseconds;

    to = NanNew<Uint32>(nanoseconds);
  return scope.Close(to);
}

Persistent<Function> GitIndexTime::constructor_template;
