/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/diff_options.h"

using namespace v8;
using namespace node;

GitDiffOptions::GitDiffOptions(git_diff_options *raw) {
  this->raw = raw;
}

GitDiffOptions::~GitDiffOptions() {
  free(this->raw);
}

void GitDiffOptions::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("DiffOptions"));



  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("DiffOptions"), _constructor_template);
}

NAN_METHOD(GitDiffOptions::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_diff_options is required.");
  }

  //GitDiffOptions* object = new GitDiffOptions((git_diff_options *) External::Unwrap(args[0]));
  GitDiffOptions* object = ObjectWrap::Unwrap<GitDiffOptions>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitDiffOptions::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitDiffOptions::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitDiffOptions::constructor_template->NewInstance(1, argv));
}

git_diff_options *GitDiffOptions::GetValue() {
  return this->raw;
}


Persistent<Function> GitDiffOptions::constructor_template;
