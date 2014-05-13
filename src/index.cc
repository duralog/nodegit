/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/index.h"
#include "../include/oid.h"
#include "../include/repo.h"
#include "../include/tree.h"
#include "../include/diff_list.h"
#include "../include/diff_options.h"
#include "../include/index_entry.h"

using namespace v8;
using namespace node;

GitIndex::GitIndex(git_index *raw) {
  this->raw = raw;
}

GitIndex::~GitIndex() {
  git_index_free(this->raw);
}

void GitIndex::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Index"));

  NODE_SET_METHOD(tpl, "open", Open);
  NODE_SET_PROTOTYPE_METHOD(tpl, "read", Read);
  NODE_SET_PROTOTYPE_METHOD(tpl, "write", Write);
  NODE_SET_PROTOTYPE_METHOD(tpl, "readTree", ReadTree);
  NODE_SET_PROTOTYPE_METHOD(tpl, "writeTree", WriteTree);
  NODE_SET_PROTOTYPE_METHOD(tpl, "size", Size);
  NODE_SET_PROTOTYPE_METHOD(tpl, "clear", Clear);
  NODE_SET_PROTOTYPE_METHOD(tpl, "entry", Entry);
  NODE_SET_PROTOTYPE_METHOD(tpl, "remove", Remove);
  NODE_SET_PROTOTYPE_METHOD(tpl, "removeDirectory", RemoveDirectory);
  NODE_SET_PROTOTYPE_METHOD(tpl, "addByPath", AddBypath);
  NODE_SET_PROTOTYPE_METHOD(tpl, "removeByPath", RemoveBypath);
  NODE_SET_PROTOTYPE_METHOD(tpl, "find", Find);
  NODE_SET_PROTOTYPE_METHOD(tpl, "conflictRemove", ConflictRemove);
  NODE_SET_PROTOTYPE_METHOD(tpl, "conflictCleanup", ConflictCleanup);
  NODE_SET_PROTOTYPE_METHOD(tpl, "hasConflicts", HasConflicts);
  NODE_SET_METHOD(tpl, "indexToWorkdir", IndexToWorkdir);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Index"), _constructor_template);
}

NAN_METHOD(GitIndex::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_index is required.");
  }

  //GitIndex* object = new GitIndex((git_index *) External::Unwrap(args[0]));
  GitIndex* object = ObjectWrap::Unwrap<GitIndex>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitIndex::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitIndex::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitIndex::constructor_template->NewInstance(1, argv));
}

git_index *GitIndex::GetValue() {
  return this->raw;
}


#include "../include/functions/copy.h"

/**
 * @param {String} index_path
 * @param {Index} callback
 */
class OpenWorker : public NanAsyncWorker {
  public:
    OpenWorker(NanCallback *callback
      , Local<Object> index_pathReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("index_path", index_pathReference);
    }
    ~OpenWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitIndex::New((void *)this->out);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {

  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
  free((void *)this->index_path);  //delete baton;
      // normal callback...
      //NanScope();

      //Local<Value> argv[] = {
      //  NanNew(NanNull()),
      //  NanNewBufferHandle((char*)resultdata, resultsize)
      //};

      //callback->Call(2, argv);
    }

    void Execute() {
      int result = git_index_open(&this->out, this->index_path);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_index * out;
    const char * index_path;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitIndex::Open) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String index_path is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->index_pathReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_index_path;
            //String::Utf8Value index_path(args[0]->ToString());
      //from_index_path = strdup(*index_path);
      from_index_path = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->index_path = from_index_path;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new OpenWorker(callback
      , args[1] //index_path
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class ReadWorker : public NanAsyncWorker {
  public:
    ReadWorker(NanCallback *callback
      , Local<Object> indexReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("index", indexReference);
    }
    ~ReadWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitIndex::Read) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->indexReference = Persistent<Value>::New(args.This());
  GitIndex* index = ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new ReadWorker(callback
      , args[0] //index
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class WriteWorker : public NanAsyncWorker {
  public:
    WriteWorker(NanCallback *callback
      , Local<Object> indexReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("index", indexReference);
    }
    ~WriteWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitIndex::Write) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->indexReference = Persistent<Value>::New(args.This());
  GitIndex* index = ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new WriteWorker(callback
      , args[0] //index
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Tree} tree
 */
class ReadTreeWorker : public NanAsyncWorker {
  public:
    ReadTreeWorker(NanCallback *callback
      , Local<Object> indexReference
      , Local<Object> treeReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("index", indexReference);
      SaveToPersistent("tree", treeReference);
    }
    ~ReadTreeWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitIndex::ReadTree) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Tree tree is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->indexReference = Persistent<Value>::New(args.This());
  GitIndex* index = ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue();
  //baton->treeReference = Persistent<Value>::New(args[0]);
  //convert: 
  const git_tree * from_tree;
            from_tree = ObjectWrap::Unwrap<GitTree>(args[0]->ToObject())->GetValue();
        //baton->tree = from_tree;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new ReadTreeWorker(callback
      , args[0] //index
      , args[1] //tree
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Oid} callback
 */
class WriteTreeWorker : public NanAsyncWorker {
  public:
    WriteTreeWorker(NanCallback *callback
      , Local<Object> indexReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("index", indexReference);
    }
    ~WriteTreeWorker() {}

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
      int result = git_index_write_tree(this->out, this->index);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * out;
    git_index * index;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitIndex::WriteTree) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->indexReference = Persistent<Value>::New(args.This());
  GitIndex* index = ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new WriteTreeWorker(callback
      , args[1] //index
  );

  NanReturnUndefined();
}

/**
 * @return {Number} result
 */
NAN_METHOD(GitIndex::Size) {
  NanScope();
  

  size_t result = git_index_entrycount(
    ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Uint32>(result);
  NanReturnValue(to);
}

/**
 */
NAN_METHOD(GitIndex::Clear) {
  NanScope();
  

  git_index_clear(
    ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
  );

  NanReturnUndefined();
}

/**
 * @param {Number} n
 * @return {IndexEntry} result
 */
NAN_METHOD(GitIndex::Entry) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsUint32()) {
    NanThrowError("Number n is required.");
  }


  size_t from_n;
            from_n = (size_t)   args[0]->ToUint32()->Value();
      
  const git_index_entry * result = git_index_get_byindex(
    ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
    , from_n
  );

  Handle<Value> to;
    if (result != NULL) {
    result = (const git_index_entry * )git_index_entry_dup(result);
  }
  if (result != NULL) {
    to = GitIndexEntry::New((void *)result);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {String} path
 * @param {Number} stage
 */
NAN_METHOD(GitIndex::Remove) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }
  if (args.Length() == 1 || !args[1]->IsInt32()) {
    NanThrowError("Number stage is required.");
  }


  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
      
  int from_stage;
            from_stage = (int)   args[1]->ToInt32()->Value();
      
  int result = git_index_remove(
    ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
    , from_path
    , from_stage
  );
  free((void *)from_path);
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
 * @param {String} dir
 * @param {Number} stage
 */
NAN_METHOD(GitIndex::RemoveDirectory) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String dir is required.");
  }
  if (args.Length() == 1 || !args[1]->IsInt32()) {
    NanThrowError("Number stage is required.");
  }


  const char * from_dir;
            //String::Utf8Value dir(args[0]->ToString());
      //from_dir = strdup(*dir);
      from_dir = strdup(NanCString(args[0]->ToString(), NULL));
      
  int from_stage;
            from_stage = (int)   args[1]->ToInt32()->Value();
      
  int result = git_index_remove_directory(
    ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
    , from_dir
    , from_stage
  );
  free((void *)from_dir);
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
 * @param {String} path
 */
class AddBypathWorker : public NanAsyncWorker {
  public:
    AddBypathWorker(NanCallback *callback
      , Local<Object> indexReference
      , Local<Object> pathReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("index", indexReference);
      SaveToPersistent("path", pathReference);
    }
    ~AddBypathWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitIndex::AddBypath) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->indexReference = Persistent<Value>::New(args.This());
  GitIndex* index = ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue();
  //baton->pathReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->path = from_path;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new AddBypathWorker(callback
      , args[0] //index
      , args[1] //path
  );

  NanReturnUndefined();
}

/**
 * @param {String} path
 */
NAN_METHOD(GitIndex::RemoveBypath) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }


  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_index_remove_bypath(
    ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
    , from_path
  );
  free((void *)from_path);
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
 * @param {String} path
 * @return {Number} at_pos
 */
NAN_METHOD(GitIndex::Find) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }

  size_t at_pos = 0;

  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_index_find(
    &at_pos
    , ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
    , from_path
  );
  free((void *)from_path);

  Handle<Value> to;
    to = NanNew<Uint32>(at_pos);
  NanReturnValue(to);
}

/**
 * @param {String} path
 */
NAN_METHOD(GitIndex::ConflictRemove) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }


  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_index_conflict_remove(
    ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
    , from_path
  );
  free((void *)from_path);
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
NAN_METHOD(GitIndex::ConflictCleanup) {
  NanScope();
  

  git_index_conflict_cleanup(
    ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
  );

  NanReturnUndefined();
}

/**
 * @return {Number} result
 */
NAN_METHOD(GitIndex::HasConflicts) {
  NanScope();
  

  int result = git_index_has_conflicts(
    ObjectWrap::Unwrap<GitIndex>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Int32>(result);
  NanReturnValue(to);
}

#include "../include/functions/copy.h"

/**
 * @param {Repository} repo
 * @param {Index} index
 * @param {DiffOptions} opts
 * @param {DiffList} callback
 */
class IndexToWorkdirWorker : public NanAsyncWorker {
  public:
    IndexToWorkdirWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> indexReference
      , Local<Object> optsReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("index", indexReference);
      SaveToPersistent("opts", optsReference);
    }
    ~IndexToWorkdirWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->diff != NULL) {
    to = GitDiffList::New((void *)this->diff);
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
      int result = git_diff_index_to_workdir(&this->diff, this->repo, this->index, this->opts);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_diff_list * diff;
    git_repository * repo;
    git_index * index;
    const git_diff_options * opts;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitIndex::IndexToWorkdir) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Repository repo is required.");
  }

  if (args.Length() == 3 || !args[3]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->repoReference = Persistent<Value>::New(args[0]);
  //convert: 
  git_repository * from_repo;
            from_repo = ObjectWrap::Unwrap<GitRepo>(args[0]->ToObject())->GetValue();
        //baton->repo = from_repo;
  //baton->indexReference = Persistent<Value>::New(args[1]);
  //convert: 
  git_index * from_index;
      if (args[1]->IsObject()) {
            from_index = ObjectWrap::Unwrap<GitIndex>(args[1]->ToObject())->GetValue();
          } else {
      from_index = 0;
    }
    //baton->index = from_index;
  //baton->optsReference = Persistent<Value>::New(args[2]);
  //convert: 
  const git_diff_options * from_opts;
      if (args[2]->IsObject()) {
            from_opts = ObjectWrap::Unwrap<GitDiffOptions>(args[2]->ToObject())->GetValue();
          } else {
      from_opts = 0;
    }
    //baton->opts = from_opts;
  NanCallback *callback = new NanCallback(args[3].As<v8::Function>());
  NanAsyncQueueWorker(new IndexToWorkdirWorker(callback
      , args[1] //repo
      , args[2] //index
      , args[3] //opts
  );

  NanReturnUndefined();
}

Persistent<Function> GitIndex::constructor_template;
