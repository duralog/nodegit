/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/tree_builder.h"
#include "../include/repo.h"
#include "../include/oid.h"
#include "../include/tree_entry.h"
#include "../include/tree.h"
#include "../include/diff_list.h"
#include "../include/diff_options.h"
#include "../include/index.h"

using namespace v8;
using namespace node;

GitTreeBuilder::GitTreeBuilder(git_treebuilder *raw) {
  this->raw = raw;
}

GitTreeBuilder::~GitTreeBuilder() {
  git_treebuilder_free(this->raw);
}

void GitTreeBuilder::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("TreeBuilder"));

  NODE_SET_METHOD(tpl, "create", Create);
  NODE_SET_PROTOTYPE_METHOD(tpl, "clear", Clear);
  NODE_SET_METHOD(tpl, "size", Size);
  NODE_SET_PROTOTYPE_METHOD(tpl, "get", Get);
  NODE_SET_PROTOTYPE_METHOD(tpl, "insert", Insert);
  NODE_SET_PROTOTYPE_METHOD(tpl, "gitTreebuilderRemove", GitTreebuilderRemove);
  NODE_SET_PROTOTYPE_METHOD(tpl, "write", Write);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("TreeBuilder"), _constructor_template);
}

NAN_METHOD(GitTreeBuilder::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_treebuilder is required.");
  }

  //GitTreeBuilder* object = new GitTreeBuilder((git_treebuilder *) External::Unwrap(args[0]));
  GitTreeBuilder* object = ObjectWrap::Unwrap<GitTreeBuilder>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitTreeBuilder::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitTreeBuilder::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitTreeBuilder::constructor_template->NewInstance(1, argv));
}

git_treebuilder *GitTreeBuilder::GetValue() {
  return this->raw;
}


/**
 * @param {Tree} source
 * @return {TreeBuilder} out
 */
NAN_METHOD(GitTreeBuilder::Create) {
  NanScope();
  
  git_treebuilder * out = 0;

  const git_tree * from_source;
      if (args[0]->IsObject()) {
            from_source = ObjectWrap::Unwrap<GitTree>(args[0]->ToObject())->GetValue();
          } else {
      from_source = 0;
    }
  
  int result = git_treebuilder_create(
    &out
    , from_source
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
    to = GitTreeBuilder::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {TreeBuilder} bld
 */
NAN_METHOD(GitTreeBuilder::Clear) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("TreeBuilder bld is required.");
  }


  git_treebuilder * from_bld;
            from_bld = ObjectWrap::Unwrap<GitTreeBuilder>(args[0]->ToObject())->GetValue();
      
  git_treebuilder_clear(
    from_bld
  );

  NanReturnUndefined();
}

/**
 * @return {Number} result
 */
NAN_METHOD(GitTreeBuilder::Size) {
  NanScope();
  

  unsigned int result = git_treebuilder_entrycount(
    ObjectWrap::Unwrap<GitTreeBuilder>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Uint32>(result);
  NanReturnValue(to);
}

/**
 * @param {String} filename
 * @return {TreeEntry} result
 */
NAN_METHOD(GitTreeBuilder::Get) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String filename is required.");
  }


  const char * from_filename;
            //String::Utf8Value filename(args[0]->ToString());
      //from_filename = strdup(*filename);
      from_filename = strdup(NanCString(args[0]->ToString(), NULL));
      
  const git_tree_entry * result = git_treebuilder_get(
    ObjectWrap::Unwrap<GitTreeBuilder>(args.This())->GetValue()
    , from_filename
  );
  free((void *)from_filename);

  Handle<Value> to;
    if (result != NULL) {
    result = (const git_tree_entry * )git_tree_entry_dup(result);
  }
  if (result != NULL) {
    to = GitTreeEntry::New((void *)result);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {String} filename
 * @param {Oid} id
 * @param {Number} filemode
 * @return {TreeEntry} out
 */
NAN_METHOD(GitTreeBuilder::Insert) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String filename is required.");
  }
  if (args.Length() == 1 || !args[1]->IsObject()) {
    NanThrowError("Oid id is required.");
  }
  if (args.Length() == 2 || !args[2]->IsNumber()) {
    NanThrowError("Number filemode is required.");
  }

  const git_tree_entry * out = 0;

  const char * from_filename;
            //String::Utf8Value filename(args[0]->ToString());
      //from_filename = strdup(*filename);
      from_filename = strdup(NanCString(args[0]->ToString(), NULL));
      
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[1]->ToObject())->GetValue();
      
  git_filemode_t from_filemode;
            from_filemode = (git_filemode_t) (int)  args[2]->ToNumber()->Value();
      
  int result = git_treebuilder_insert(
    &out
    , ObjectWrap::Unwrap<GitTreeBuilder>(args.This())->GetValue()
    , from_filename
    , from_id
    , from_filemode
  );
  free((void *)from_filename);
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
    out = (const git_tree_entry * )git_tree_entry_dup(out);
  }
  if (out != NULL) {
    to = GitTreeEntry::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {String} filename
 */
NAN_METHOD(GitTreeBuilder::GitTreebuilderRemove) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String filename is required.");
  }


  const char * from_filename;
            //String::Utf8Value filename(args[0]->ToString());
      //from_filename = strdup(*filename);
      from_filename = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_treebuilder_remove(
    ObjectWrap::Unwrap<GitTreeBuilder>(args.This())->GetValue()
    , from_filename
  );
  free((void *)from_filename);
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
 * @param {Repository} repo
 * @param {Oid} callback
 */
class WriteWorker : public NanAsyncWorker {
  public:
    WriteWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> bldReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("bld", bldReference);
    }
    ~WriteWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->id != NULL) {
    to = GitOid::New((void *)this->id);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {
    free(this->id );
    
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
      this->id = (git_oid *)malloc(sizeof(git_oid ));
      int result = git_treebuilder_write(this->id, this->repo, this->bld);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * id;
    git_repository * repo;
    git_treebuilder * bld;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitTreeBuilder::Write) {
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
  //this->bldReference = Persistent<Value>::New(args.This());
  GitTreeBuilder* bld = ObjectWrap::Unwrap<GitTreeBuilder>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new WriteWorker(callback
      , args[1] //repo
      , args[2] //bld
  );

  NanReturnUndefined();
}

Persistent<Function> GitTreeBuilder::constructor_template;
