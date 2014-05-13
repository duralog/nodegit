/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/tag.h"
#include "../include/oid.h"
#include "../include/repo.h"
#include "../include/object.h"
#include "../include/signature.h"

using namespace v8;
using namespace node;

GitTag::GitTag(git_tag *raw) {
  this->raw = raw;
}

GitTag::~GitTag() {
  git_tag_free(this->raw);
}

void GitTag::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Tag"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "oid", Oid);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getTarget", GetTarget);
  NODE_SET_PROTOTYPE_METHOD(tpl, "targetId", TargetId);
  NODE_SET_PROTOTYPE_METHOD(tpl, "targetType", TargetType);
  NODE_SET_PROTOTYPE_METHOD(tpl, "name", Name);
  NODE_SET_PROTOTYPE_METHOD(tpl, "tagger", Tagger);
  NODE_SET_PROTOTYPE_METHOD(tpl, "message", Message);
  NODE_SET_PROTOTYPE_METHOD(tpl, "peel", Peel);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Tag"), _constructor_template);
}

NAN_METHOD(GitTag::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_tag is required.");
  }

  //GitTag* object = new GitTag((git_tag *) External::Unwrap(args[0]));
  GitTag* object = ObjectWrap::Unwrap<GitTag>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitTag::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitTag::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitTag::constructor_template->NewInstance(1, argv));
}

git_tag *GitTag::GetValue() {
  return this->raw;
}


/**
 * @return {Oid} result
 */
NAN_METHOD(GitTag::Oid) {
  NanScope();
  

  const git_oid * result = git_tag_id(
    ObjectWrap::Unwrap<GitTag>(args.This())->GetValue()
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

#include "../include/functions/copy.h"

/**
 * @param {Object} callback
 */
class GetTargetWorker : public NanAsyncWorker {
  public:
    GetTargetWorker(NanCallback *callback
      , Local<Object> tagReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("tag", tagReference);
    }
    ~GetTargetWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->target_out != NULL) {
    to = GitObject::New((void *)this->target_out);
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
      int result = git_tag_target(&this->target_out, this->tag);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_object * target_out;
    const git_tag * tag;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitTag::GetTarget) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->tagReference = Persistent<Value>::New(args.This());
  GitTag* tag = ObjectWrap::Unwrap<GitTag>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new GetTargetWorker(callback
      , args[1] //tag
  );

  NanReturnUndefined();
}

/**
 * @return {Oid} result
 */
NAN_METHOD(GitTag::TargetId) {
  NanScope();
  

  const git_oid * result = git_tag_target_id(
    ObjectWrap::Unwrap<GitTag>(args.This())->GetValue()
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
NAN_METHOD(GitTag::TargetType) {
  NanScope();
  

  git_otype result = git_tag_target_type(
    ObjectWrap::Unwrap<GitTag>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Int32>(result);
  NanReturnValue(to);
}

/**
 * @return {String} result
 */
NAN_METHOD(GitTag::Name) {
  NanScope();
  

  const char * result = git_tag_name(
    ObjectWrap::Unwrap<GitTag>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @return {Signature} result
 */
NAN_METHOD(GitTag::Tagger) {
  NanScope();
  

  const git_signature * result = git_tag_tagger(
    ObjectWrap::Unwrap<GitTag>(args.This())->GetValue()
  );

  Handle<Value> to;
    if (result != NULL) {
    result = (const git_signature * )git_signature_dup(result);
  }
  if (result != NULL) {
    to = GitSignature::New((void *)result);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @return {String} result
 */
NAN_METHOD(GitTag::Message) {
  NanScope();
  

  const char * result = git_tag_message(
    ObjectWrap::Unwrap<GitTag>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @param {Tag} tag
 * @return {Object} tag_target_out
 */
NAN_METHOD(GitTag::Peel) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Tag tag is required.");
  }

  git_object * tag_target_out = 0;

  const git_tag * from_tag;
            from_tag = ObjectWrap::Unwrap<GitTag>(args[0]->ToObject())->GetValue();
      
  int result = git_tag_peel(
    &tag_target_out
    , from_tag
  );
  if (result != GIT_OK) {
    const git_error* err;
    if ((err = giterr_last()) != NULL) {
      NanThrowError(err->message);
    } else {
      NanThrowError("Unknown Error");
    }
  }

  Handle<Value> to;
    if (tag_target_out != NULL) {
    to = GitObject::New((void *)tag_target_out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

Persistent<Function> GitTag::constructor_template;
