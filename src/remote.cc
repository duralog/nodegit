/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/remote.h"
#include "git2/net.h"

using namespace v8;
using namespace node;

GitRemote::GitRemote(git_remote *raw) {
  this->raw = raw;
}

GitRemote::~GitRemote() {
  git_remote_free(this->raw);
}

void GitRemote::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Remote"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "name", Name);
  NODE_SET_PROTOTYPE_METHOD(tpl, "url", Url);
  NODE_SET_PROTOTYPE_METHOD(tpl, "pushUrl", PushUrl);
  NODE_SET_PROTOTYPE_METHOD(tpl, "setUrl", SetUrl);
  NODE_SET_PROTOTYPE_METHOD(tpl, "setPushUrl", SetPushUrl);
  NODE_SET_PROTOTYPE_METHOD(tpl, "connect", Connect);
  NODE_SET_PROTOTYPE_METHOD(tpl, "download", Download);
  NODE_SET_PROTOTYPE_METHOD(tpl, "connected", Connected);
  NODE_SET_PROTOTYPE_METHOD(tpl, "stop", Stop);
  NODE_SET_PROTOTYPE_METHOD(tpl, "disconnect", Disconnect);
  NODE_SET_PROTOTYPE_METHOD(tpl, "updateTips", UpdateTips);
  NODE_SET_METHOD(tpl, "validUrl", ValidUrl);
  NODE_SET_METHOD(tpl, "supportedUrl", SupportedUrl);
  NODE_SET_PROTOTYPE_METHOD(tpl, "checkCert", CheckCert);
  NODE_SET_PROTOTYPE_METHOD(tpl, "updateFetchhead", UpdateFetchhead);
  NODE_SET_PROTOTYPE_METHOD(tpl, "setUpdateFetchhead", SetUpdateFetchhead);
  NODE_SET_METHOD(tpl, "isValidName", IsValidName);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Remote"), _constructor_template);
}

NAN_METHOD(GitRemote::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_remote is required.");
  }

  //GitRemote* object = new GitRemote((git_remote *) External::Unwrap(args[0]));
  GitRemote* object = ObjectWrap::Unwrap<GitRemote>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitRemote::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitRemote::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitRemote::constructor_template->NewInstance(1, argv));
}

git_remote *GitRemote::GetValue() {
  return this->raw;
}


/**
 * @return {String} result
 */
NAN_METHOD(GitRemote::Name) {
  NanScope();
  

  const char * result = git_remote_name(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @return {String} result
 */
NAN_METHOD(GitRemote::Url) {
  NanScope();
  

  const char * result = git_remote_url(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @return {String} result
 */
NAN_METHOD(GitRemote::PushUrl) {
  NanScope();
  

  const char * result = git_remote_pushurl(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @param {String} url
 */
NAN_METHOD(GitRemote::SetUrl) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String url is required.");
  }


  const char* from_url;
            //String::Utf8Value url(args[0]->ToString());
      //from_url = strdup(*url);
      from_url = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_remote_set_url(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
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
 * @param {String} url
 */
NAN_METHOD(GitRemote::SetPushUrl) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String url is required.");
  }


  const char* from_url;
            //String::Utf8Value url(args[0]->ToString());
      //from_url = strdup(*url);
      from_url = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_remote_set_pushurl(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
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

#include "../include/functions/copy.h"

/**
 * @param {Number} direction
 */
class ConnectWorker : public NanAsyncWorker {
  public:
    ConnectWorker(NanCallback *callback
      , Local<Object> remoteReference
      , Local<Object> directionReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("remote", remoteReference);
      SaveToPersistent("direction", directionReference);
    }
    ~ConnectWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRemote::Connect) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsNumber()) {
    NanThrowError("Number direction is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->remoteReference = Persistent<Value>::New(args.This());
  GitRemote* remote = ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue();
  //baton->directionReference = Persistent<Value>::New(args[0]);
  //convert: 
  git_direction from_direction;
            from_direction = (git_direction) (int)  args[0]->ToNumber()->Value();
        //baton->direction = from_direction;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new ConnectWorker(callback
      , args[0] //remote
      , args[1] //direction
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Function} progress_cb
 * @param {void} payload
 */
class DownloadWorker : public NanAsyncWorker {
  public:
    DownloadWorker(NanCallback *callback
      , Local<Object> remoteReference
      , Local<Object> progress_cbReference
      , Local<Object> payloadReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("remote", remoteReference);
      SaveToPersistent("progress_cb", progress_cbReference);
      SaveToPersistent("payload", payloadReference);
    }
    ~DownloadWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRemote::Download) {
  NanScope();

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->remoteReference = Persistent<Value>::New(args.This());
  GitRemote* remote = ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue();
  //baton->progress_cbReference = Persistent<Value>::New(args[0]);
  //convert: 
  git_transfer_progress_callback from_progress_cb;
      if (args[0]->IsFunction()) {
            Persistent<Function>::New(Local<Function>::Cast(args[0]));
          } else {
      from_progress_cb = 0;
    }
    //baton->progress_cb = from_progress_cb;
  //baton->payloadReference = Persistent<Value>::New(args[1]);
  //convert: 
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new DownloadWorker(callback
      , args[0] //remote
      , args[1] //progress_cb
      , args[2] //payload
  );

  NanReturnUndefined();
}

/**
 */
NAN_METHOD(GitRemote::Connected) {
  NanScope();
  

  int result = git_remote_connected(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
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
NAN_METHOD(GitRemote::Stop) {
  NanScope();
  

  git_remote_stop(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class DisconnectWorker : public NanAsyncWorker {
  public:
    DisconnectWorker(NanCallback *callback
      , Local<Object> remoteReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("remote", remoteReference);
    }
    ~DisconnectWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRemote::Disconnect) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->remoteReference = Persistent<Value>::New(args.This());
  GitRemote* remote = ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new DisconnectWorker(callback
      , args[0] //remote
  );

  NanReturnUndefined();
}

/**
 */
NAN_METHOD(GitRemote::UpdateTips) {
  NanScope();
  

  int result = git_remote_update_tips(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
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
 * @param {String} url
 */
NAN_METHOD(GitRemote::ValidUrl) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String url is required.");
  }


  const char * from_url;
            //String::Utf8Value url(args[0]->ToString());
      //from_url = strdup(*url);
      from_url = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_remote_valid_url(
    from_url
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
 * @param {String} url
 */
NAN_METHOD(GitRemote::SupportedUrl) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String url is required.");
  }


  const char* from_url;
            //String::Utf8Value url(args[0]->ToString());
      //from_url = strdup(*url);
      from_url = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_remote_supported_url(
    from_url
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
 * @param {Number} check
 */
NAN_METHOD(GitRemote::CheckCert) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsInt32()) {
    NanThrowError("Number check is required.");
  }


  int from_check;
            from_check = (int)   args[0]->ToInt32()->Value();
      
  git_remote_check_cert(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
    , from_check
  );

  NanReturnUndefined();
}

/**
 */
NAN_METHOD(GitRemote::UpdateFetchhead) {
  NanScope();
  

  int result = git_remote_update_fetchhead(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
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
 * @param {Number} value
 */
NAN_METHOD(GitRemote::SetUpdateFetchhead) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsInt32()) {
    NanThrowError("Number value is required.");
  }


  int from_value;
            from_value = (int)   args[0]->ToInt32()->Value();
      
  git_remote_set_update_fetchhead(
    ObjectWrap::Unwrap<GitRemote>(args.This())->GetValue()
    , from_value
  );

  NanReturnUndefined();
}

/**
 * @param {String} remote_name
 */
NAN_METHOD(GitRemote::IsValidName) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String remote_name is required.");
  }


  const char * from_remote_name;
            //String::Utf8Value remote_name(args[0]->ToString());
      //from_remote_name = strdup(*remote_name);
      from_remote_name = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_remote_is_valid_name(
    from_remote_name
  );
  free((void *)from_remote_name);
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

Persistent<Function> GitRemote::constructor_template;
