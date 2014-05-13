/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/submodule.h"
#include "../include/oid.h"
#include "../include/repo.h"

using namespace v8;
using namespace node;

GitSubmodule::GitSubmodule(git_submodule *raw) {
  this->raw = raw;
}

GitSubmodule::~GitSubmodule() {
  free(this->raw);
}

void GitSubmodule::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Submodule"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "addFinalize", AddFinalize);
  NODE_SET_PROTOTYPE_METHOD(tpl, "addToIndex", AddToIndex);
  NODE_SET_PROTOTYPE_METHOD(tpl, "save", Save);
  NODE_SET_PROTOTYPE_METHOD(tpl, "name", Name);
  NODE_SET_PROTOTYPE_METHOD(tpl, "path", Path);
  NODE_SET_PROTOTYPE_METHOD(tpl, "url", Url);
  NODE_SET_PROTOTYPE_METHOD(tpl, "setUrl", SetUrl);
  NODE_SET_PROTOTYPE_METHOD(tpl, "indexId", IndexId);
  NODE_SET_PROTOTYPE_METHOD(tpl, "headId", HeadId);
  NODE_SET_PROTOTYPE_METHOD(tpl, "init", Init);
  NODE_SET_PROTOTYPE_METHOD(tpl, "sync", Sync);
  NODE_SET_PROTOTYPE_METHOD(tpl, "open", Open);
  NODE_SET_PROTOTYPE_METHOD(tpl, "reload", Reload);
  NODE_SET_PROTOTYPE_METHOD(tpl, "status", Status);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Submodule"), _constructor_template);
}

NAN_METHOD(GitSubmodule::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_submodule is required.");
  }

  //GitSubmodule* object = new GitSubmodule((git_submodule *) External::Unwrap(args[0]));
  GitSubmodule* object = ObjectWrap::Unwrap<GitSubmodule>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitSubmodule::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitSubmodule::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitSubmodule::constructor_template->NewInstance(1, argv));
}

git_submodule *GitSubmodule::GetValue() {
  return this->raw;
}


#include "../include/functions/copy.h"

/**
 */
class AddFinalizeWorker : public NanAsyncWorker {
  public:
    AddFinalizeWorker(NanCallback *callback
      , Local<Object> submoduleReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("submodule", submoduleReference);
    }
    ~AddFinalizeWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitSubmodule::AddFinalize) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->submoduleReference = Persistent<Value>::New(args.This());
  GitSubmodule* submodule = ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new AddFinalizeWorker(callback
      , args[0] //submodule
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Number} write_index
 */
class AddToIndexWorker : public NanAsyncWorker {
  public:
    AddToIndexWorker(NanCallback *callback
      , Local<Object> submoduleReference
      , Local<Object> write_indexReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("submodule", submoduleReference);
      SaveToPersistent("write_index", write_indexReference);
    }
    ~AddToIndexWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitSubmodule::AddToIndex) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsInt32()) {
    NanThrowError("Number write_index is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->submoduleReference = Persistent<Value>::New(args.This());
  GitSubmodule* submodule = ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue();
  //baton->write_indexReference = Persistent<Value>::New(args[0]);
  //convert: 
  int from_write_index;
            from_write_index = (int)   args[0]->ToInt32()->Value();
        //baton->write_index = from_write_index;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new AddToIndexWorker(callback
      , args[0] //submodule
      , args[1] //write_index
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class SaveWorker : public NanAsyncWorker {
  public:
    SaveWorker(NanCallback *callback
      , Local<Object> submoduleReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("submodule", submoduleReference);
    }
    ~SaveWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitSubmodule::Save) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->submoduleReference = Persistent<Value>::New(args.This());
  GitSubmodule* submodule = ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new SaveWorker(callback
      , args[0] //submodule
  );

  NanReturnUndefined();
}

/**
 * @return {String} result
 */
NAN_METHOD(GitSubmodule::Name) {
  NanScope();
  

  const char * result = git_submodule_name(
    ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @return {String} result
 */
NAN_METHOD(GitSubmodule::Path) {
  NanScope();
  

  const char * result = git_submodule_path(
    ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @return {String} result
 */
NAN_METHOD(GitSubmodule::Url) {
  NanScope();
  

  const char * result = git_submodule_url(
    ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @param {String} url
 */
NAN_METHOD(GitSubmodule::SetUrl) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String url is required.");
  }


  const char * from_url;
            //String::Utf8Value url(args[0]->ToString());
      //from_url = strdup(*url);
      from_url = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_submodule_set_url(
    ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue()
    , from_url
  );
  free((void *)from_url);
  if (result != GIT_OK) {
    const git_error* err;
    if ((err = giterr_last()) != NULL) {
      NanThrowError(err->message);
    } else {
      NanThrowError("Unknown Error");
    }
  }

  NanReturnUndefined();
}

/**
 * @return {Oid} result
 */
NAN_METHOD(GitSubmodule::IndexId) {
  NanScope();
  

  const git_oid * result = git_submodule_index_id(
    ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue()
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
 * @return {Oid} result
 */
NAN_METHOD(GitSubmodule::HeadId) {
  NanScope();
  

  const git_oid * result = git_submodule_head_id(
    ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue()
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
 * @param {Number} overwrite
 */
class InitWorker : public NanAsyncWorker {
  public:
    InitWorker(NanCallback *callback
      , Local<Object> submoduleReference
      , Local<Object> overwriteReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("submodule", submoduleReference);
      SaveToPersistent("overwrite", overwriteReference);
    }
    ~InitWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitSubmodule::Init) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsInt32()) {
    NanThrowError("Number overwrite is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->submoduleReference = Persistent<Value>::New(args.This());
  GitSubmodule* submodule = ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue();
  //baton->overwriteReference = Persistent<Value>::New(args[0]);
  //convert: 
  int from_overwrite;
            from_overwrite = (int)   args[0]->ToInt32()->Value();
        //baton->overwrite = from_overwrite;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new InitWorker(callback
      , args[0] //submodule
      , args[1] //overwrite
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class SyncWorker : public NanAsyncWorker {
  public:
    SyncWorker(NanCallback *callback
      , Local<Object> submoduleReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("submodule", submoduleReference);
    }
    ~SyncWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitSubmodule::Sync) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->submoduleReference = Persistent<Value>::New(args.This());
  GitSubmodule* submodule = ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new SyncWorker(callback
      , args[0] //submodule
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Repository} callback
 */
class OpenWorker : public NanAsyncWorker {
  public:
    OpenWorker(NanCallback *callback
      , Local<Object> submoduleReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("submodule", submoduleReference);
    }
    ~OpenWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->repo != NULL) {
    to = GitRepo::New((void *)this->repo);
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
      int result = git_submodule_open(&this->repo, this->submodule);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_repository * repo;
    git_submodule * submodule;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitSubmodule::Open) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->submoduleReference = Persistent<Value>::New(args.This());
  GitSubmodule* submodule = ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new OpenWorker(callback
      , args[1] //submodule
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class ReloadWorker : public NanAsyncWorker {
  public:
    ReloadWorker(NanCallback *callback
      , Local<Object> submoduleReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("submodule", submoduleReference);
    }
    ~ReloadWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitSubmodule::Reload) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->submoduleReference = Persistent<Value>::New(args.This());
  GitSubmodule* submodule = ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new ReloadWorker(callback
      , args[0] //submodule
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Number} status
 */
class StatusWorker : public NanAsyncWorker {
  public:
    StatusWorker(NanCallback *callback
      , Local<Object> statusReference
      , Local<Object> submoduleReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("status", statusReference);
      SaveToPersistent("submodule", submoduleReference);
    }
    ~StatusWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitSubmodule::Status) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsInt32()) {
    NanThrowError("Number status is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->statusReference = Persistent<Value>::New(args[0]);
  //convert: 
  unsigned int * from_status;
            from_status = (unsigned int *)   args[0]->ToInt32()->Value();
        //baton->status = from_status;
  //this->submoduleReference = Persistent<Value>::New(args.This());
  GitSubmodule* submodule = ObjectWrap::Unwrap<GitSubmodule>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new StatusWorker(callback
      , args[0] //status
      , args[1] //submodule
  );

  NanReturnUndefined();
}

Persistent<Function> GitSubmodule::constructor_template;
