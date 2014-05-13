/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/signature.h"
#include "../include/time.h"

using namespace v8;
using namespace node;

GitSignature::GitSignature(git_signature *raw) {
  this->raw = raw;
}

GitSignature::~GitSignature() {
  git_signature_free(this->raw);
}

void GitSignature::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Signature"));

  NODE_SET_METHOD(tpl, "create", Create);
  NODE_SET_METHOD(tpl, "now", Now);

  NODE_SET_PROTOTYPE_METHOD(tpl, "name", Name);
  NODE_SET_PROTOTYPE_METHOD(tpl, "email", Email);
  NODE_SET_PROTOTYPE_METHOD(tpl, "time", Time);

  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Signature"), _constructor_template);
}

NAN_METHOD(GitSignature::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_signature is required.");
  }

  //GitSignature* object = new GitSignature((git_signature *) External::Unwrap(args[0]));
  GitSignature* object = ObjectWrap::Unwrap<GitSignature>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitSignature::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitSignature::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitSignature::constructor_template->NewInstance(1, argv));
}

git_signature *GitSignature::GetValue() {
  return this->raw;
}


/**
 * @param {String} name
 * @param {String} email
 * @param {Number} time
 * @param {Number} offset
 * @return {Signature} out
 */
NAN_METHOD(GitSignature::Create) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String name is required.");
  }
  if (args.Length() == 1 || !args[1]->IsString()) {
    NanThrowError("String email is required.");
  }
  if (args.Length() == 2 || !args[2]->IsInt32()) {
    NanThrowError("Number time is required.");
  }
  if (args.Length() == 3 || !args[3]->IsInt32()) {
    NanThrowError("Number offset is required.");
  }

  git_signature * out = 0;

  const char * from_name;
            //String::Utf8Value name(args[0]->ToString());
      //from_name = strdup(*name);
      from_name = strdup(NanCString(args[0]->ToString(), NULL));
      
  const char * from_email;
            //String::Utf8Value email(args[1]->ToString());
      //from_email = strdup(*email);
      from_email = strdup(NanCString(args[1]->ToString(), NULL));
      
  git_time_t from_time;
            from_time = (git_time_t)   args[2]->ToInt32()->Value();
      
  int from_offset;
            from_offset = (int)   args[3]->ToInt32()->Value();
      
  int result = git_signature_new(
    &out
    , from_name
    , from_email
    , from_time
    , from_offset
  );
  free((void *)from_name);
  free((void *)from_email);
  if (result != GIT_OK) {
    const git_error* err;
    if ((err = giterr_last()) != NULL) {
      NanThrowError(err->message);
    } else {
      NanThrowError("Unknown Error");
    }
  }

  Handle<Value> to;
    if (out != NULL) {
    to = GitSignature::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {String} name
 * @param {String} email
 * @return {Signature} out
 */
NAN_METHOD(GitSignature::Now) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String name is required.");
  }
  if (args.Length() == 1 || !args[1]->IsString()) {
    NanThrowError("String email is required.");
  }

  git_signature * out = 0;

  const char * from_name;
            //String::Utf8Value name(args[0]->ToString());
      //from_name = strdup(*name);
      from_name = strdup(NanCString(args[0]->ToString(), NULL));
      
  const char * from_email;
            //String::Utf8Value email(args[1]->ToString());
      //from_email = strdup(*email);
      from_email = strdup(NanCString(args[1]->ToString(), NULL));
      
  int result = git_signature_now(
    &out
    , from_name
    , from_email
  );
  free((void *)from_name);
  free((void *)from_email);
  if (result != GIT_OK) {
    const git_error* err;
    if ((err = giterr_last()) != NULL) {
      NanThrowError(err->message);
    } else {
      NanThrowError("Unknown Error");
    }
  }

  Handle<Value> to;
    if (out != NULL) {
    to = GitSignature::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

NAN_METHOD(GitSignature::Name) {
  NanScope();
    Handle<Value> to;

  const char * name =
    ObjectWrap::Unwrap<GitSignature>(args.This())->GetValue()->name;

    to = NanNew<String>(name);
  return scope.Close(to);
}

NAN_METHOD(GitSignature::Email) {
  NanScope();
    Handle<Value> to;

  const char * email =
    ObjectWrap::Unwrap<GitSignature>(args.This())->GetValue()->email;

    to = NanNew<String>(email);
  return scope.Close(to);
}

NAN_METHOD(GitSignature::Time) {
  NanScope();
    Handle<Value> to;

  git_time *when =
    &ObjectWrap::Unwrap<GitSignature>(args.This())->GetValue()->when;

    if (when != NULL) {
    when = (git_time *)git_time_dup(when);
  }
  if (when != NULL) {
    to = GitTime::New((void *)when);
  } else {
    to = NanNew(NanNull());
  }
  return scope.Close(to);
}

Persistent<Function> GitSignature::constructor_template;
