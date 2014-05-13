/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/diff_range.h"

using namespace v8;
using namespace node;

GitDiffRange::GitDiffRange(git_diff_range *raw) {
  this->raw = raw;
}

GitDiffRange::~GitDiffRange() {
  free(this->raw);
}

void GitDiffRange::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("DiffRange"));


  NODE_SET_PROTOTYPE_METHOD(tpl, "oldStart", OldStart);
  NODE_SET_PROTOTYPE_METHOD(tpl, "oldLines", OldLines);
  NODE_SET_PROTOTYPE_METHOD(tpl, "newStart", NewStart);
  NODE_SET_PROTOTYPE_METHOD(tpl, "newLines", NewLines);

  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("DiffRange"), _constructor_template);
}

NAN_METHOD(GitDiffRange::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_diff_range is required.");
  }

  //GitDiffRange* object = new GitDiffRange((git_diff_range *) External::Unwrap(args[0]));
  GitDiffRange* object = ObjectWrap::Unwrap<GitDiffRange>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitDiffRange::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitDiffRange::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitDiffRange::constructor_template->NewInstance(1, argv));
}

git_diff_range *GitDiffRange::GetValue() {
  return this->raw;
}


NAN_METHOD(GitDiffRange::OldStart) {
  NanScope();
    Handle<Value> to;

  int old_start =
    ObjectWrap::Unwrap<GitDiffRange>(args.This())->GetValue()->old_start;

    to = NanNew<Integer>(old_start);
  return scope.Close(to);
}

NAN_METHOD(GitDiffRange::OldLines) {
  NanScope();
    Handle<Value> to;

  int old_lines =
    ObjectWrap::Unwrap<GitDiffRange>(args.This())->GetValue()->old_lines;

    to = NanNew<Integer>(old_lines);
  return scope.Close(to);
}

NAN_METHOD(GitDiffRange::NewStart) {
  NanScope();
    Handle<Value> to;

  int new_start =
    ObjectWrap::Unwrap<GitDiffRange>(args.This())->GetValue()->new_start;

    to = NanNew<Integer>(new_start);
  return scope.Close(to);
}

NAN_METHOD(GitDiffRange::NewLines) {
  NanScope();
    Handle<Value> to;

  int new_lines =
    ObjectWrap::Unwrap<GitDiffRange>(args.This())->GetValue()->new_lines;

    to = NanNew<Integer>(new_lines);
  return scope.Close(to);
}

Persistent<Function> GitDiffRange::constructor_template;
