/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/revwalk.h"
#include "../include/oid.h"
#include "../include/repo.h"

using namespace v8;
using namespace node;

GitRevWalk::GitRevWalk(git_revwalk *raw) {
  this->raw = raw;
}

GitRevWalk::~GitRevWalk() {
  git_revwalk_free(this->raw);
}

void GitRevWalk::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("RevWalk"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "reset", Reset);
  NODE_SET_PROTOTYPE_METHOD(tpl, "push", Push);
  NODE_SET_PROTOTYPE_METHOD(tpl, "pushGlob", PushGlob);
  NODE_SET_PROTOTYPE_METHOD(tpl, "pushHead", PushHead);
  NODE_SET_PROTOTYPE_METHOD(tpl, "hide", Hide);
  NODE_SET_PROTOTYPE_METHOD(tpl, "hideGlob", HideGlob);
  NODE_SET_PROTOTYPE_METHOD(tpl, "hideHead", HideHead);
  NODE_SET_PROTOTYPE_METHOD(tpl, "pushRef", PushRef);
  NODE_SET_PROTOTYPE_METHOD(tpl, "hideRef", HideRef);
  NODE_SET_PROTOTYPE_METHOD(tpl, "next", Next);
  NODE_SET_PROTOTYPE_METHOD(tpl, "sorting", Sorting);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("RevWalk"), _constructor_template);
}

NAN_METHOD(GitRevWalk::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_revwalk is required.");
  }

  //GitRevWalk* object = new GitRevWalk((git_revwalk *) External::Unwrap(args[0]));
  GitRevWalk* object = ObjectWrap::Unwrap<GitRevWalk>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitRevWalk::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitRevWalk::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitRevWalk::constructor_template->NewInstance(1, argv));
}

git_revwalk *GitRevWalk::GetValue() {
  return this->raw;
}


/**
 */
NAN_METHOD(GitRevWalk::Reset) {
  NanScope();
  

  git_revwalk_reset(
    ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue()
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Oid} id
 */
class PushWorker : public NanAsyncWorker {
  public:
    PushWorker(NanCallback *callback
      , Local<Object> walkReference
      , Local<Object> idReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("walk", walkReference);
      SaveToPersistent("id", idReference);
    }
    ~PushWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRevWalk::Push) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid id is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->walkReference = Persistent<Value>::New(args.This());
  GitRevWalk* walk = ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue();
  //baton->idReference = Persistent<Value>::New(args[0]);
  //convert: 
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
        //baton->id = from_id;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new PushWorker(callback
      , args[0] //walk
      , args[1] //id
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} glob
 */
class PushGlobWorker : public NanAsyncWorker {
  public:
    PushGlobWorker(NanCallback *callback
      , Local<Object> walkReference
      , Local<Object> globReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("walk", walkReference);
      SaveToPersistent("glob", globReference);
    }
    ~PushGlobWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRevWalk::PushGlob) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String glob is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->walkReference = Persistent<Value>::New(args.This());
  GitRevWalk* walk = ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue();
  //baton->globReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_glob;
            //String::Utf8Value glob(args[0]->ToString());
      //from_glob = strdup(*glob);
      from_glob = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->glob = from_glob;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new PushGlobWorker(callback
      , args[0] //walk
      , args[1] //glob
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class PushHeadWorker : public NanAsyncWorker {
  public:
    PushHeadWorker(NanCallback *callback
      , Local<Object> walkReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("walk", walkReference);
    }
    ~PushHeadWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRevWalk::PushHead) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->walkReference = Persistent<Value>::New(args.This());
  GitRevWalk* walk = ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new PushHeadWorker(callback
      , args[0] //walk
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Oid} commit_id
 */
class HideWorker : public NanAsyncWorker {
  public:
    HideWorker(NanCallback *callback
      , Local<Object> walkReference
      , Local<Object> commit_idReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("walk", walkReference);
      SaveToPersistent("commit_id", commit_idReference);
    }
    ~HideWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRevWalk::Hide) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid commit_id is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->walkReference = Persistent<Value>::New(args.This());
  GitRevWalk* walk = ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue();
  //baton->commit_idReference = Persistent<Value>::New(args[0]);
  //convert: 
  const git_oid * from_commit_id;
            from_commit_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
        //baton->commit_id = from_commit_id;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new HideWorker(callback
      , args[0] //walk
      , args[1] //commit_id
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} glob
 */
class HideGlobWorker : public NanAsyncWorker {
  public:
    HideGlobWorker(NanCallback *callback
      , Local<Object> walkReference
      , Local<Object> globReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("walk", walkReference);
      SaveToPersistent("glob", globReference);
    }
    ~HideGlobWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRevWalk::HideGlob) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String glob is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->walkReference = Persistent<Value>::New(args.This());
  GitRevWalk* walk = ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue();
  //baton->globReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_glob;
            //String::Utf8Value glob(args[0]->ToString());
      //from_glob = strdup(*glob);
      from_glob = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->glob = from_glob;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new HideGlobWorker(callback
      , args[0] //walk
      , args[1] //glob
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class HideHeadWorker : public NanAsyncWorker {
  public:
    HideHeadWorker(NanCallback *callback
      , Local<Object> walkReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("walk", walkReference);
    }
    ~HideHeadWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRevWalk::HideHead) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->walkReference = Persistent<Value>::New(args.This());
  GitRevWalk* walk = ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new HideHeadWorker(callback
      , args[0] //walk
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} refname
 */
class PushRefWorker : public NanAsyncWorker {
  public:
    PushRefWorker(NanCallback *callback
      , Local<Object> walkReference
      , Local<Object> refnameReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("walk", walkReference);
      SaveToPersistent("refname", refnameReference);
    }
    ~PushRefWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRevWalk::PushRef) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String refname is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->walkReference = Persistent<Value>::New(args.This());
  GitRevWalk* walk = ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue();
  //baton->refnameReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_refname;
            //String::Utf8Value refname(args[0]->ToString());
      //from_refname = strdup(*refname);
      from_refname = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->refname = from_refname;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new PushRefWorker(callback
      , args[0] //walk
      , args[1] //refname
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} refname
 */
class HideRefWorker : public NanAsyncWorker {
  public:
    HideRefWorker(NanCallback *callback
      , Local<Object> walkReference
      , Local<Object> refnameReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("walk", walkReference);
      SaveToPersistent("refname", refnameReference);
    }
    ~HideRefWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRevWalk::HideRef) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String refname is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->walkReference = Persistent<Value>::New(args.This());
  GitRevWalk* walk = ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue();
  //baton->refnameReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_refname;
            //String::Utf8Value refname(args[0]->ToString());
      //from_refname = strdup(*refname);
      from_refname = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->refname = from_refname;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new HideRefWorker(callback
      , args[0] //walk
      , args[1] //refname
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Oid} callback
 */
class NextWorker : public NanAsyncWorker {
  public:
    NextWorker(NanCallback *callback
      , Local<Object> walkReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("walk", walkReference);
    }
    ~NextWorker() {}

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
      this->out = (git_oid *)malloc(sizeof(git_oid ));
      int result = git_revwalk_next(this->out, this->walk);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * out;
    git_revwalk * walk;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRevWalk::Next) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->walkReference = Persistent<Value>::New(args.This());
  GitRevWalk* walk = ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new NextWorker(callback
      , args[1] //walk
  );

  NanReturnUndefined();
}

/**
 * @param {Number} sort_mode
 */
NAN_METHOD(GitRevWalk::Sorting) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsUint32()) {
    NanThrowError("Number sort_mode is required.");
  }


  unsigned int from_sort_mode;
            from_sort_mode = (unsigned int)   args[0]->ToUint32()->Value();
      
  git_revwalk_sorting(
    ObjectWrap::Unwrap<GitRevWalk>(args.This())->GetValue()
    , from_sort_mode
  );

  NanReturnUndefined();
}

Persistent<Function> GitRevWalk::constructor_template;
