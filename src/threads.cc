/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/threads.h"

using namespace v8;
using namespace node;

void GitThreads::Initialize(Handle<v8::Object> target) {
  NanScope();

  Persistent<Object> object = Persistent<Object>::New(Object::New());

  object->Set(NanSymbol("init"), FunctionTemplate::New(Init)->GetFunction());
  object->Set(NanSymbol("shutdown"), FunctionTemplate::New(Shutdown)->GetFunction());

  target->Set(NanSymbol("Threads"), object);
}


/**
 */
NAN_METHOD(GitThreads::Init) {
  NanScope();
  

  int result = git_threads_init(
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
NAN_METHOD(GitThreads::Shutdown) {
  NanScope();
  

  git_threads_shutdown(
  );

  NanReturnUndefined();
}

