/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/blob.h"
#include "../include/repo.h"
#include "../include/oid.h"
#include "../include/wrapper.h"
#include "node_buffer.h"

using namespace v8;
using namespace node;

GitBlob::GitBlob(git_blob *raw) {
  this->raw = raw;
}

GitBlob::~GitBlob() {
  git_blob_free(this->raw);
}

void GitBlob::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Blob"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "oid", Oid);
  NODE_SET_PROTOTYPE_METHOD(tpl, "content", Content);
  NODE_SET_PROTOTYPE_METHOD(tpl, "size", Size);
  NODE_SET_PROTOTYPE_METHOD(tpl, "isBinary", IsBinary);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Blob"), _constructor_template);
}

NAN_METHOD(GitBlob::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_blob is required.");
  }

  //GitBlob* object = new GitBlob((git_blob *) External::Unwrap(args[0]));
  GitBlob* object = ObjectWrap::Unwrap<GitBlob>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitBlob::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitBlob::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitBlob::constructor_template->NewInstance(1, argv));
}

git_blob *GitBlob::GetValue() {
  return this->raw;
}


/**
 * @return {Oid} result
 */
NAN_METHOD(GitBlob::Oid) {
  NanScope();
  

  const git_oid * result = git_blob_id(
    ObjectWrap::Unwrap<GitBlob>(args.This())->GetValue()
  );

  Handle<Value> to;
    if (result != NULL) {
    result = (const git_oid * )git_oid_dup(result);
  }
  if (result != NULL) {
    to = GitOid::New((void *)result);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @return {Wrapper} result
 */
NAN_METHOD(GitBlob::Content) {
  NanScope();
  

  const void * result = git_blob_rawcontent(
    ObjectWrap::Unwrap<GitBlob>(args.This())->GetValue()
  );

  Handle<Value> to;
    if (result != NULL) {
    to = Wrapper::New((void *)result);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @return {Number} result
 */
NAN_METHOD(GitBlob::Size) {
  NanScope();
  

  git_off_t result = git_blob_rawsize(
    ObjectWrap::Unwrap<GitBlob>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Number>(result);
  NanReturnValue(to);
}

/**
 * @return {Boolean} result
 */
NAN_METHOD(GitBlob::IsBinary) {
  NanScope();
  

  int result = git_blob_is_binary(
    ObjectWrap::Unwrap<GitBlob>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Boolean>(result);
  NanReturnValue(to);
}

Persistent<Function> GitBlob::constructor_template;
