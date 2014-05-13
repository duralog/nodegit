/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/object.h"
#include "../include/oid.h"
#include "../include/repo.h"

using namespace v8;
using namespace node;

GitObject::GitObject(git_object *raw) {
  this->raw = raw;
}

GitObject::~GitObject() {
  git_object_free(this->raw);
}

void GitObject::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Object"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "oid", Oid);
  NODE_SET_PROTOTYPE_METHOD(tpl, "type", Type);
  NODE_SET_PROTOTYPE_METHOD(tpl, "peel", Peel);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Object"), _constructor_template);
}

NAN_METHOD(GitObject::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_object is required.");
  }

  //GitObject* object = new GitObject((git_object *) External::Unwrap(args[0]));
  GitObject* object = ObjectWrap::Unwrap<GitObject>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitObject::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitObject::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitObject::constructor_template->NewInstance(1, argv));
}

git_object *GitObject::GetValue() {
  return this->raw;
}


/**
 * @return {Oid} result
 */
NAN_METHOD(GitObject::Oid) {
  NanScope();
  

  const git_oid * result = git_object_id(
    ObjectWrap::Unwrap<GitObject>(args.This())->GetValue()
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
 * @return {Number} result
 */
NAN_METHOD(GitObject::Type) {
  NanScope();
  

  git_otype result = git_object_type(
    ObjectWrap::Unwrap<GitObject>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Number>(result);
  NanReturnValue(to);
}

#include "../include/functions/copy.h"

/**
 * @param {Number} target_type
 * @param {Object} callback
 */
class PeelWorker : public NanAsyncWorker {
  public:
    PeelWorker(NanCallback *callback
      , Local<Object> objectReference
      , Local<Object> target_typeReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("object", objectReference);
      SaveToPersistent("target_type", target_typeReference);
    }
    ~PeelWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->peeled != NULL) {
    to = GitObject::New((void *)this->peeled);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {

  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
  //delete baton;
      // normal callback...
      //NanScope();

      //Local<Value> argv[] = {
      //  NanNew(NanNull()),
      //  NanNewBufferHandle((char*)resultdata, resultsize)
      //};

      //callback->Call(2, argv);
    }

    void Execute() {
      int result = git_object_peel(&this->peeled, this->object, this->target_type);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_object * peeled;
    const git_object * object;
    git_otype target_type;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitObject::Peel) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsInt32()) {
    NanThrowError("Number target_type is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->objectReference = Persistent<Value>::New(args.This());
  GitObject* object = ObjectWrap::Unwrap<GitObject>(args.This())->GetValue();
  //baton->target_typeReference = Persistent<Value>::New(args[0]);
  //convert: 
  git_otype from_target_type;
            from_target_type = (git_otype)   args[0]->ToInt32()->Value();
        //baton->target_type = from_target_type;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new PeelWorker(callback
      , args[1] //object
      , args[2] //target_type
  );

  NanReturnUndefined();
}

Persistent<Function> GitObject::constructor_template;
