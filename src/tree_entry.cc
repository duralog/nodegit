/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/tree_entry.h"
#include "../include/oid.h"
#include "../include/repo.h"
#include "../include/object.h"

using namespace v8;
using namespace node;

GitTreeEntry::GitTreeEntry(git_tree_entry *raw) {
  this->raw = raw;
}

GitTreeEntry::~GitTreeEntry() {
  git_tree_entry_free(this->raw);
}

void GitTreeEntry::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("TreeEntry"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "name", Name);
  NODE_SET_PROTOTYPE_METHOD(tpl, "oid", Oid);
  NODE_SET_PROTOTYPE_METHOD(tpl, "type", Type);
  NODE_SET_PROTOTYPE_METHOD(tpl, "filemode", filemode);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getObject", GetObject);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("TreeEntry"), _constructor_template);
}

NAN_METHOD(GitTreeEntry::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_tree_entry is required.");
  }

  //GitTreeEntry* object = new GitTreeEntry((git_tree_entry *) External::Unwrap(args[0]));
  GitTreeEntry* object = ObjectWrap::Unwrap<GitTreeEntry>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitTreeEntry::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitTreeEntry::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitTreeEntry::constructor_template->NewInstance(1, argv));
}

git_tree_entry *GitTreeEntry::GetValue() {
  return this->raw;
}


/**
 * @return {String} result
 */
NAN_METHOD(GitTreeEntry::Name) {
  NanScope();
  

  const char * result = git_tree_entry_name(
    ObjectWrap::Unwrap<GitTreeEntry>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @return {Oid} result
 */
NAN_METHOD(GitTreeEntry::Oid) {
  NanScope();
  

  const git_oid * result = git_tree_entry_id(
    ObjectWrap::Unwrap<GitTreeEntry>(args.This())->GetValue()
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
NAN_METHOD(GitTreeEntry::Type) {
  NanScope();
  

  git_otype result = git_tree_entry_type(
    ObjectWrap::Unwrap<GitTreeEntry>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Number>(result);
  NanReturnValue(to);
}

/**
 * @return {Number} result
 */
NAN_METHOD(GitTreeEntry::filemode) {
  NanScope();
  

  git_filemode_t result = git_tree_entry_filemode(
    ObjectWrap::Unwrap<GitTreeEntry>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Number>(result);
  NanReturnValue(to);
}

#include "../include/functions/copy.h"

/**
 * @param {Repository} repo
 * @param {Object} callback
 */
class GetObjectWorker : public NanAsyncWorker {
  public:
    GetObjectWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> entryReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("entry", entryReference);
    }
    ~GetObjectWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->object_out != NULL) {
    to = GitObject::New((void *)this->object_out);
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
      int result = git_tree_entry_to_object(&this->object_out, this->repo, this->entry);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_object * object_out;
    git_repository * repo;
    const git_tree_entry * entry;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitTreeEntry::GetObject) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Repository repo is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->repoReference = Persistent<Value>::New(args[0]);
  //convert: 
  git_repository * from_repo;
            from_repo = ObjectWrap::Unwrap<GitRepo>(args[0]->ToObject())->GetValue();
        //baton->repo = from_repo;
  //this->entryReference = Persistent<Value>::New(args.This());
  GitTreeEntry* entry = ObjectWrap::Unwrap<GitTreeEntry>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new GetObjectWorker(callback
      , args[1] //repo
      , args[2] //entry
  );

  NanReturnUndefined();
}

Persistent<Function> GitTreeEntry::constructor_template;
