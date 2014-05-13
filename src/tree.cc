/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/tree.h"
#include "../include/repo.h"
#include "../include/oid.h"
#include "../include/tree_entry.h"
#include "../include/diff_list.h"
#include "../include/diff_options.h"
#include "../include/tree_builder.h"
#include "../include/index.h"

using namespace v8;
using namespace node;

GitTree::GitTree(git_tree *raw) {
  this->raw = raw;
}

GitTree::~GitTree() {
  git_tree_free(this->raw);
}

void GitTree::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Tree"));

  NODE_SET_PROTOTYPE_METHOD(tpl, "oid", Oid);
  NODE_SET_PROTOTYPE_METHOD(tpl, "size", Size);
  NODE_SET_PROTOTYPE_METHOD(tpl, "entryByName", EntryByName);
  NODE_SET_PROTOTYPE_METHOD(tpl, "entryByIndex", EntryByIndex);
  NODE_SET_PROTOTYPE_METHOD(tpl, "entryByOid", EntryByOid);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getEntry", GetEntry);
  NODE_SET_PROTOTYPE_METHOD(tpl, "builder", Builder);
  NODE_SET_PROTOTYPE_METHOD(tpl, "diffTree", DiffTree);
  NODE_SET_PROTOTYPE_METHOD(tpl, "diffIndex", DiffIndex);
  NODE_SET_PROTOTYPE_METHOD(tpl, "diffWorkDir", DiffWorkDir);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Tree"), _constructor_template);
}

NAN_METHOD(GitTree::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_tree is required.");
  }

  //GitTree* object = new GitTree((git_tree *) External::Unwrap(args[0]));
  GitTree* object = ObjectWrap::Unwrap<GitTree>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitTree::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitTree::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitTree::constructor_template->NewInstance(1, argv));
}

git_tree *GitTree::GetValue() {
  return this->raw;
}


/**
 * @return {Oid} result
 */
NAN_METHOD(GitTree::Oid) {
  NanScope();
  

  const git_oid * result = git_tree_id(
    ObjectWrap::Unwrap<GitTree>(args.This())->GetValue()
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
NAN_METHOD(GitTree::Size) {
  NanScope();
  

  size_t result = git_tree_entrycount(
    ObjectWrap::Unwrap<GitTree>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<Uint32>(result);
  NanReturnValue(to);
}

/**
 * @param {String} filename
 * @return {TreeEntry} result
 */
NAN_METHOD(GitTree::EntryByName) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String filename is required.");
  }


  const char * from_filename;
            //String::Utf8Value filename(args[0]->ToString());
      //from_filename = strdup(*filename);
      from_filename = strdup(NanCString(args[0]->ToString(), NULL));
      
  const git_tree_entry * result = git_tree_entry_byname(
    ObjectWrap::Unwrap<GitTree>(args.This())->GetValue()
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
 * @param {Number} idx
 * @return {TreeEntry} result
 */
NAN_METHOD(GitTree::EntryByIndex) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsUint32()) {
    NanThrowError("Number idx is required.");
  }


  size_t from_idx;
            from_idx = (size_t)   args[0]->ToUint32()->Value();
      
  const git_tree_entry * result = git_tree_entry_byindex(
    ObjectWrap::Unwrap<GitTree>(args.This())->GetValue()
    , from_idx
  );

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
 * @param {Oid} oid
 * @return {TreeEntry} result
 */
NAN_METHOD(GitTree::EntryByOid) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid oid is required.");
  }


  const git_oid * from_oid;
            from_oid = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
      
  const git_tree_entry * result = git_tree_entry_byoid(
    ObjectWrap::Unwrap<GitTree>(args.This())->GetValue()
    , from_oid
  );

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

#include "../include/functions/copy.h"

/**
 * @param {String} path
 * @param {TreeEntry} callback
 */
class GetEntryWorker : public NanAsyncWorker {
  public:
    GetEntryWorker(NanCallback *callback
      , Local<Object> rootReference
      , Local<Object> pathReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("root", rootReference);
      SaveToPersistent("path", pathReference);
    }
    ~GetEntryWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitTreeEntry::New((void *)this->out);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {

  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
  free((void *)this->path);  //delete baton;
      // normal callback...
      //NanScope();

      //Local<Value> argv[] = {
      //  NanNew(NanNull()),
      //  NanNewBufferHandle((char*)resultdata, resultsize)
      //};

      //callback->Call(2, argv);
    }

    void Execute() {
      int result = git_tree_entry_bypath(&this->out, this->root, this->path);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_tree_entry * out;
    git_tree * root;
    const char * path;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitTree::GetEntry) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->rootReference = Persistent<Value>::New(args.This());
  GitTree* root = ObjectWrap::Unwrap<GitTree>(args.This())->GetValue();
  //baton->pathReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->path = from_path;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new GetEntryWorker(callback
      , args[1] //root
      , args[2] //path
  );

  NanReturnUndefined();
}

/**
 * @return {TreeBuilder} out
 */
NAN_METHOD(GitTree::Builder) {
  NanScope();
  
  git_treebuilder * out = 0;

  int result = git_treebuilder_create(
    &out
    , ObjectWrap::Unwrap<GitTree>(args.This())->GetValue()
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

#include "../include/functions/copy.h"

/**
 * @param {Repository} repo
 * @param {Tree} new_tree
 * @param {DiffOptions} opts
 * @param {DiffList} callback
 */
class DiffTreeWorker : public NanAsyncWorker {
  public:
    DiffTreeWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> old_treeReference
      , Local<Object> new_treeReference
      , Local<Object> optsReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("old_tree", old_treeReference);
      SaveToPersistent("new_tree", new_treeReference);
      SaveToPersistent("opts", optsReference);
    }
    ~DiffTreeWorker() {}

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
      int result = git_diff_tree_to_tree(&this->diff, this->repo, this->old_tree, this->new_tree, this->opts);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_diff_list * diff;
    git_repository * repo;
    git_tree * old_tree;
    git_tree * new_tree;
    const git_diff_options * opts;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitTree::DiffTree) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Repository repo is required.");
  }
  if (args.Length() == 1 || !args[1]->IsObject()) {
    NanThrowError("Tree new_tree is required.");
  }

  if (args.Length() == 3 || !args[3]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->repoReference = Persistent<Value>::New(args[0]);
  //convert: 
  git_repository * from_repo;
            from_repo = ObjectWrap::Unwrap<GitRepo>(args[0]->ToObject())->GetValue();
        //baton->repo = from_repo;
  //this->old_treeReference = Persistent<Value>::New(args.This());
  GitTree* old_tree = ObjectWrap::Unwrap<GitTree>(args.This())->GetValue();
  //baton->new_treeReference = Persistent<Value>::New(args[1]);
  //convert: 
  git_tree * from_new_tree;
            from_new_tree = ObjectWrap::Unwrap<GitTree>(args[1]->ToObject())->GetValue();
        //baton->new_tree = from_new_tree;
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
  NanAsyncQueueWorker(new DiffTreeWorker(callback
      , args[1] //repo
      , args[2] //old_tree
      , args[3] //new_tree
      , args[4] //opts
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Repository} repo
 * @param {Index} index
 * @param {DiffOptions} opts
 * @param {DiffList} callback
 */
class DiffIndexWorker : public NanAsyncWorker {
  public:
    DiffIndexWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> old_treeReference
      , Local<Object> indexReference
      , Local<Object> optsReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("old_tree", old_treeReference);
      SaveToPersistent("index", indexReference);
      SaveToPersistent("opts", optsReference);
    }
    ~DiffIndexWorker() {}

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
      int result = git_diff_tree_to_index(&this->diff, this->repo, this->old_tree, this->index, this->opts);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_diff_list * diff;
    git_repository * repo;
    git_tree * old_tree;
    git_index * index;
    const git_diff_options * opts;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitTree::DiffIndex) {
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
  //this->old_treeReference = Persistent<Value>::New(args.This());
  GitTree* old_tree = ObjectWrap::Unwrap<GitTree>(args.This())->GetValue();
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
  NanAsyncQueueWorker(new DiffIndexWorker(callback
      , args[1] //repo
      , args[2] //old_tree
      , args[3] //index
      , args[4] //opts
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Repository} repo
 * @param {DiffOptions} opts
 * @param {DiffList} callback
 */
class DiffWorkDirWorker : public NanAsyncWorker {
  public:
    DiffWorkDirWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> old_treeReference
      , Local<Object> optsReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("old_tree", old_treeReference);
      SaveToPersistent("opts", optsReference);
    }
    ~DiffWorkDirWorker() {}

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
      int result = git_diff_tree_to_workdir(&this->diff, this->repo, this->old_tree, this->opts);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_diff_list * diff;
    git_repository * repo;
    git_tree * old_tree;
    const git_diff_options * opts;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitTree::DiffWorkDir) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Repository repo is required.");
  }

  if (args.Length() == 2 || !args[2]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->repoReference = Persistent<Value>::New(args[0]);
  //convert: 
  git_repository * from_repo;
            from_repo = ObjectWrap::Unwrap<GitRepo>(args[0]->ToObject())->GetValue();
        //baton->repo = from_repo;
  //this->old_treeReference = Persistent<Value>::New(args.This());
  GitTree* old_tree = ObjectWrap::Unwrap<GitTree>(args.This())->GetValue();
  //baton->optsReference = Persistent<Value>::New(args[1]);
  //convert: 
  const git_diff_options * from_opts;
      if (args[1]->IsObject()) {
            from_opts = ObjectWrap::Unwrap<GitDiffOptions>(args[1]->ToObject())->GetValue();
          } else {
      from_opts = 0;
    }
    //baton->opts = from_opts;
  NanCallback *callback = new NanCallback(args[2].As<v8::Function>());
  NanAsyncQueueWorker(new DiffWorkDirWorker(callback
      , args[1] //repo
      , args[2] //old_tree
      , args[3] //opts
  );

  NanReturnUndefined();
}

Persistent<Function> GitTree::constructor_template;
