/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/reference.h"
#include "../include/repo.h"
#include "../include/oid.h"
#include "../include/object.h"

using namespace v8;
using namespace node;

GitReference::GitReference(git_reference *raw) {
  this->raw = raw;
}

GitReference::~GitReference() {
  git_reference_free(this->raw);
}

void GitReference::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Reference"));

  NODE_SET_METHOD(tpl, "oidForName", OidForName);
  NODE_SET_PROTOTYPE_METHOD(tpl, "target", Target);
  NODE_SET_PROTOTYPE_METHOD(tpl, "symbolicTarget", SymbolicTarget);
  NODE_SET_PROTOTYPE_METHOD(tpl, "type", Type);
  NODE_SET_PROTOTYPE_METHOD(tpl, "name", Name);
  NODE_SET_PROTOTYPE_METHOD(tpl, "resolve", Resolve);
  NODE_SET_PROTOTYPE_METHOD(tpl, "setSymbolicTarget", SetSymbolicTarget);
  NODE_SET_PROTOTYPE_METHOD(tpl, "setTarget", setTarget);
  NODE_SET_PROTOTYPE_METHOD(tpl, "rename", Rename);
  NODE_SET_PROTOTYPE_METHOD(tpl, "delete", Delete);
  NODE_SET_PROTOTYPE_METHOD(tpl, "isBranch", IsBranch);
  NODE_SET_PROTOTYPE_METHOD(tpl, "isRemote", IsRemote);
  NODE_SET_PROTOTYPE_METHOD(tpl, "peel", Peel);
  NODE_SET_METHOD(tpl, "isValidName", IsValidName);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Reference"), _constructor_template);
}

NAN_METHOD(GitReference::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_reference is required.");
  }

  //GitReference* object = new GitReference((git_reference *) External::Unwrap(args[0]));
  GitReference* object = ObjectWrap::Unwrap<GitReference>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitReference::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitReference::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitReference::constructor_template->NewInstance(1, argv));
}

git_reference *GitReference::GetValue() {
  return this->raw;
}


#include "../include/functions/copy.h"

/**
 * @param {Repository} repo
 * @param {String} name
 * @param {Oid} callback
 */
class OidForNameWorker : public NanAsyncWorker {
  public:
    OidForNameWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> nameReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("name", nameReference);
    }
    ~OidForNameWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitOid::New((void *)this->out);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {
    free(this->out );
    
  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
  free((void *)this->name);  //delete baton;
      // normal callback...
      //NanScope();

      //Local<Value> argv[] = {
      //  NanNew(NanNull()),
      //  NanNewBufferHandle((char*)resultdata, resultsize)
      //};

      //callback->Call(2, argv);
    }

    void Execute() {
      this->out = (git_oid *)malloc(sizeof(git_oid ));
      int result = git_reference_name_to_id(this->out, this->repo, this->name);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * out;
    git_repository * repo;
    const char * name;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitReference::OidForName) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Repository repo is required.");
  }
  if (args.Length() == 1 || !args[1]->IsString()) {
    NanThrowError("String name is required.");
  }

  if (args.Length() == 2 || !args[2]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->repoReference = Persistent<Value>::New(args[0]);
  //convert: 
  git_repository * from_repo;
            from_repo = ObjectWrap::Unwrap<GitRepo>(args[0]->ToObject())->GetValue();
        //baton->repo = from_repo;
  //baton->nameReference = Persistent<Value>::New(args[1]);
  //convert: 
  const char * from_name;
            //String::Utf8Value name(args[1]->ToString());
      //from_name = strdup(*name);
      from_name = strdup(NanCString(args[1]->ToString(), NULL));
        //baton->name = from_name;
  NanCallback *callback = new NanCallback(args[2].As<v8::Function>());
  NanAsyncQueueWorker(new OidForNameWorker(callback
      , args[1] //repo
      , args[2] //name
  );

  NanReturnUndefined();
}

/**
 * @return {Oid} result
 */
NAN_METHOD(GitReference::Target) {
  NanScope();
  

  const git_oid * result = git_reference_target(
    ObjectWrap::Unwrap<GitReference>(args.This())->GetValue()
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
 * @return {String} result
 */
NAN_METHOD(GitReference::SymbolicTarget) {
  NanScope();
  

  const char * result = git_reference_symbolic_target(
    ObjectWrap::Unwrap<GitReference>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @return {Number} result
 */
NAN_METHOD(GitReference::Type) {
  NanScope();
  

  git_ref_t result = git_reference_type(
    ObjectWrap::Unwrap<GitReference>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Number>(result);
  NanReturnValue(to);
}

/**
 * @return {String} result
 */
NAN_METHOD(GitReference::Name) {
  NanScope();
  

  const char * result = git_reference_name(
    ObjectWrap::Unwrap<GitReference>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

#include "../include/functions/copy.h"

/**
 * @param {Reference} callback
 */
class ResolveWorker : public NanAsyncWorker {
  public:
    ResolveWorker(NanCallback *callback
      , Local<Object> refReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("ref", refReference);
    }
    ~ResolveWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitReference::New((void *)this->out);
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
      int result = git_reference_resolve(&this->out, this->ref);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_reference * out;
    const git_reference * ref;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitReference::Resolve) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->refReference = Persistent<Value>::New(args.This());
  GitReference* ref = ObjectWrap::Unwrap<GitReference>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new ResolveWorker(callback
      , args[1] //ref
  );

  NanReturnUndefined();
}

/**
 * @param {String} target
 * @return {Reference} out
 */
NAN_METHOD(GitReference::SetSymbolicTarget) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String target is required.");
  }

  git_reference * out = 0;

  const char * from_target;
            //String::Utf8Value target(args[0]->ToString());
      //from_target = strdup(*target);
      from_target = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_reference_symbolic_set_target(
    &out
    , ObjectWrap::Unwrap<GitReference>(args.This())->GetValue()
    , from_target
  );
  free((void *)from_target);
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
    to = GitReference::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {Oid} id
 * @return {Reference} out
 */
NAN_METHOD(GitReference::setTarget) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid id is required.");
  }

  git_reference * out = 0;

  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
      
  int result = git_reference_set_target(
    &out
    , ObjectWrap::Unwrap<GitReference>(args.This())->GetValue()
    , from_id
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
    if (out != NULL) {
    to = GitReference::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

#include "../include/functions/copy.h"

/**
 * @param {String} new_name
 * @param {Number} force
 * @param {Reference} callback
 */
class RenameWorker : public NanAsyncWorker {
  public:
    RenameWorker(NanCallback *callback
      , Local<Object> refReference
      , Local<Object> new_nameReference
      , Local<Object> forceReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("ref", refReference);
      SaveToPersistent("new_name", new_nameReference);
      SaveToPersistent("force", forceReference);
    }
    ~RenameWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitReference::New((void *)this->out);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {

  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
  free((void *)this->new_name);  //delete baton;
      // normal callback...
      //NanScope();

      //Local<Value> argv[] = {
      //  NanNew(NanNull()),
      //  NanNewBufferHandle((char*)resultdata, resultsize)
      //};

      //callback->Call(2, argv);
    }

    void Execute() {
      int result = git_reference_rename(&this->out, this->ref, this->new_name, this->force);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_reference * out;
    git_reference * ref;
    const char * new_name;
    int force;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitReference::Rename) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String new_name is required.");
  }
  if (args.Length() == 1 || !args[1]->IsInt32()) {
    NanThrowError("Number force is required.");
  }

  if (args.Length() == 2 || !args[2]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->refReference = Persistent<Value>::New(args.This());
  GitReference* ref = ObjectWrap::Unwrap<GitReference>(args.This())->GetValue();
  //baton->new_nameReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_new_name;
            //String::Utf8Value new_name(args[0]->ToString());
      //from_new_name = strdup(*new_name);
      from_new_name = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->new_name = from_new_name;
  //baton->forceReference = Persistent<Value>::New(args[1]);
  //convert: 
  int from_force;
            from_force = (int)   args[1]->ToInt32()->Value();
        //baton->force = from_force;
  NanCallback *callback = new NanCallback(args[2].As<v8::Function>());
  NanAsyncQueueWorker(new RenameWorker(callback
      , args[1] //ref
      , args[2] //new_name
      , args[3] //force
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class DeleteWorker : public NanAsyncWorker {
  public:
    DeleteWorker(NanCallback *callback
      , Local<Object> refReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("ref", refReference);
    }
    ~DeleteWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitReference::Delete) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->refReference = Persistent<Value>::New(args.This());
  GitReference* ref = ObjectWrap::Unwrap<GitReference>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new DeleteWorker(callback
      , args[0] //ref
  );

  NanReturnUndefined();
}

/**
 */
NAN_METHOD(GitReference::IsBranch) {
  NanScope();
  

  int result = git_reference_is_branch(
    ObjectWrap::Unwrap<GitReference>(args.This())->GetValue()
  );
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
 */
NAN_METHOD(GitReference::IsRemote) {
  NanScope();
  

  int result = git_reference_is_remote(
    ObjectWrap::Unwrap<GitReference>(args.This())->GetValue()
  );
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
 * @param {Number} type
 * @return {Object} out
 */
NAN_METHOD(GitReference::Peel) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsInt32()) {
    NanThrowError("Number type is required.");
  }

  git_object * out = 0;

  git_otype from_type;
            from_type = (git_otype)   args[0]->ToInt32()->Value();
      
  int result = git_reference_peel(
    &out
    , ObjectWrap::Unwrap<GitReference>(args.This())->GetValue()
    , from_type
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
    if (out != NULL) {
    to = GitObject::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {String} refname
 */
NAN_METHOD(GitReference::IsValidName) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String refname is required.");
  }


  const char * from_refname;
            //String::Utf8Value refname(args[0]->ToString());
      //from_refname = strdup(*refname);
      from_refname = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_reference_is_valid_name(
    from_refname
  );
  free((void *)from_refname);
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

Persistent<Function> GitReference::constructor_template;
