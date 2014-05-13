/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/repo.h"
#include "../include/oid.h"
#include "../include/commit.h"
#include "../include/blob.h"
#include "../include/object.h"
#include "../include/reference.h"
#include "../include/submodule.h"
#include "../include/refdb.h"
#include "../include/revwalk.h"
#include "../include/tag.h"
#include "../include/signature.h"
#include "../include/tree.h"
#include "../include/odb.h"
#include "../include/index.h"
#include "../include/remote.h"
#include "../include/clone_options.h"
#include "node_buffer.h"

using namespace v8;
using namespace node;

GitRepo::GitRepo(git_repository *raw) {
  this->raw = raw;
}

GitRepo::~GitRepo() {
  git_repository_free(this->raw);
}

void GitRepo::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Repo"));

  NODE_SET_METHOD(tpl, "open", Open);
  NODE_SET_METHOD(tpl, "init", Init);
  NODE_SET_PROTOTYPE_METHOD(tpl, "path", Path);
  NODE_SET_PROTOTYPE_METHOD(tpl, "workdir", Workdir);
  NODE_SET_PROTOTYPE_METHOD(tpl, "odb", Odb);
  NODE_SET_PROTOTYPE_METHOD(tpl, "openIndex", openIndex);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getBlob", GetBlob);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getCommit", GetCommit);
  NODE_SET_PROTOTYPE_METHOD(tpl, "createCommit", CreateCommit);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getObject", GetObject);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getReference", GetReference);
  NODE_SET_PROTOTYPE_METHOD(tpl, "createSymbolicReference", CreateSymbolicReference);
  NODE_SET_PROTOTYPE_METHOD(tpl, "createReference", CreateReference);
  NODE_SET_PROTOTYPE_METHOD(tpl, "addRemote", AddRemote);
  NODE_SET_PROTOTYPE_METHOD(tpl, "createRevWalk", CreateRevWalk);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getSubmodule", GetSubmodule);
  NODE_SET_PROTOTYPE_METHOD(tpl, "addSubmodule", AddSubmodule);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getTag", GetTag);
  NODE_SET_PROTOTYPE_METHOD(tpl, "createTag", CreateTag);
  NODE_SET_METHOD(tpl, "createLightweightTag", CreateLightweightTag);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getTree", GetTree);
  NODE_SET_METHOD(tpl, "reloadSubmodules", ReloadSubmodules);
  NODE_SET_PROTOTYPE_METHOD(tpl, "delete", Delete);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getReferences", GetReferences);
  NODE_SET_PROTOTYPE_METHOD(tpl, "createBlobFromBuffer", CreateBlobFromBuffer);
  NODE_SET_PROTOTYPE_METHOD(tpl, "createBlobFromFile", CreateBlobFromFile);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getRemotes", GetRemotes);
  NODE_SET_METHOD(tpl, "clone", Clone);
  NODE_SET_PROTOTYPE_METHOD(tpl, "getRemote", GetRemote);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Repo"), _constructor_template);
}

NAN_METHOD(GitRepo::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_repository is required.");
  }

  //GitRepo* object = new GitRepo((git_repository *) External::Unwrap(args[0]));
  GitRepo* object = ObjectWrap::Unwrap<GitRepo>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitRepo::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitRepo::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitRepo::constructor_template->NewInstance(1, argv));
}

git_repository *GitRepo::GetValue() {
  return this->raw;
}


#include "../include/functions/copy.h"

/**
 * @param {String} path
 * @param {Repository} callback
 */
class OpenWorker : public NanAsyncWorker {
  public:
    OpenWorker(NanCallback *callback
      , Local<Object> pathReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("path", pathReference);
    }
    ~OpenWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitRepo::New((void *)this->out);
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
      int result = git_repository_open(&this->out, this->path);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_repository * out;
    const char * path;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::Open) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->pathReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->path = from_path;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new OpenWorker(callback
      , args[1] //path
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} path
 * @param {Boolean} is_bare
 * @param {Repository} callback
 */
class InitWorker : public NanAsyncWorker {
  public:
    InitWorker(NanCallback *callback
      , Local<Object> pathReference
      , Local<Object> is_bareReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("path", pathReference);
      SaveToPersistent("is_bare", is_bareReference);
    }
    ~InitWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitRepo::New((void *)this->out);
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
      int result = git_repository_init(&this->out, this->path, this->is_bare);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_repository * out;
    const char * path;
    unsigned is_bare;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::Init) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }
  if (args.Length() == 1 || !args[1]->IsBoolean()) {
    NanThrowError("Boolean is_bare is required.");
  }

  if (args.Length() == 2 || !args[2]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->pathReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->path = from_path;
  //baton->is_bareReference = Persistent<Value>::New(args[1]);
  //convert: 
  unsigned from_is_bare;
            from_is_bare = (unsigned)   args[1]->ToBoolean()->Value();
        //baton->is_bare = from_is_bare;
  NanCallback *callback = new NanCallback(args[2].As<v8::Function>());
  NanAsyncQueueWorker(new InitWorker(callback
      , args[1] //path
      , args[2] //is_bare
  );

  NanReturnUndefined();
}

/**
 * @return {String} result
 */
NAN_METHOD(GitRepo::Path) {
  NanScope();
  

  const char * result = git_repository_path(
    ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @return {String} result
 */
NAN_METHOD(GitRepo::Workdir) {
  NanScope();
  

  const char * result = git_repository_workdir(
    ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue()
  );

  Handle<Value> to;
    to = NanNew<String>(result);
  NanReturnValue(to);
}

/**
 * @return {Odb} out
 */
NAN_METHOD(GitRepo::Odb) {
  NanScope();
  
  git_odb * out = 0;

  int result = git_repository_odb(
    &out
    , ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue()
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
    to = GitOdb::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

#include "../include/functions/copy.h"

/**
 * @param {Index} callback
 */
class openIndexWorker : public NanAsyncWorker {
  public:
    openIndexWorker(NanCallback *callback
      , Local<Object> repoReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
    }
    ~openIndexWorker() {}

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
      int result = git_repository_index(&this->out, this->repo);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_index * out;
    git_repository * repo;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::openIndex) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new openIndexWorker(callback
      , args[1] //repo
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Oid} id
 * @param {Blob} callback
 */
class GetBlobWorker : public NanAsyncWorker {
  public:
    GetBlobWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> idReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("id", idReference);
    }
    ~GetBlobWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->blob != NULL) {
    to = GitBlob::New((void *)this->blob);
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
      int result = git_blob_lookup(&this->blob, this->repo, this->id);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_blob * blob;
    git_repository * repo;
    const git_oid * id;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::GetBlob) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid id is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->idReference = Persistent<Value>::New(args[0]);
  //convert: 
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
        //baton->id = from_id;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new GetBlobWorker(callback
      , args[1] //repo
      , args[2] //id
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Oid} id
 * @param {Commit} callback
 */
class GetCommitWorker : public NanAsyncWorker {
  public:
    GetCommitWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> idReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("id", idReference);
    }
    ~GetCommitWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->commit != NULL) {
    to = GitCommit::New((void *)this->commit);
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
      int result = git_commit_lookup(&this->commit, this->repo, this->id);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_commit * commit;
    git_repository * repo;
    const git_oid * id;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::GetCommit) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid id is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->idReference = Persistent<Value>::New(args[0]);
  //convert: 
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
        //baton->id = from_id;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new GetCommitWorker(callback
      , args[1] //repo
      , args[2] //id
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} update_ref
 * @param {Signature} author
 * @param {Signature} committer
 * @param {String} message_encoding
 * @param {String} message
 * @param {Tree} tree
 * @param {Number} parent_count
 * @param {Array} parents
 * @param {Oid} callback
 */
class CreateCommitWorker : public NanAsyncWorker {
  public:
    CreateCommitWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> update_refReference
      , Local<Object> authorReference
      , Local<Object> committerReference
      , Local<Object> message_encodingReference
      , Local<Object> messageReference
      , Local<Object> treeReference
      , Local<Object> parent_countReference
      , Local<Object> parentsReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("update_ref", update_refReference);
      SaveToPersistent("author", authorReference);
      SaveToPersistent("committer", committerReference);
      SaveToPersistent("message_encoding", message_encodingReference);
      SaveToPersistent("message", messageReference);
      SaveToPersistent("tree", treeReference);
      SaveToPersistent("parent_count", parent_countReference);
      SaveToPersistent("parents", parentsReference);
    }
    ~CreateCommitWorker() {}

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
  free((void *)this->update_ref);  free((void *)this->message_encoding);  free((void *)this->message);  free((void *)this->parents);  //delete baton;
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
      int result = git_commit_create(this->id, this->repo, this->update_ref, this->author, this->committer, this->message_encoding, this->message, this->tree, this->parent_count, this->parents);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * id;
    git_repository * repo;
    const char * update_ref;
    const git_signature * author;
    const git_signature * committer;
    const char * message_encoding;
    const char * message;
    const git_tree * tree;
    int parent_count;
    const git_commit ** parents;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::CreateCommit) {
  NanScope();
  if (args.Length() == 1 || !args[1]->IsObject()) {
    NanThrowError("Signature author is required.");
  }
  if (args.Length() == 2 || !args[2]->IsObject()) {
    NanThrowError("Signature committer is required.");
  }
  if (args.Length() == 4 || !args[4]->IsString()) {
    NanThrowError("String message is required.");
  }
  if (args.Length() == 5 || !args[5]->IsObject()) {
    NanThrowError("Tree tree is required.");
  }
  if (args.Length() == 6 || !args[6]->IsInt32()) {
    NanThrowError("Number parent_count is required.");
  }
  if (args.Length() == 7 || !args[7]->IsObject()) {
    NanThrowError("Array parents is required.");
  }

  if (args.Length() == 8 || !args[8]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->update_refReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_update_ref;
      if (args[0]->IsString()) {
            //String::Utf8Value update_ref(args[0]->ToString());
      //from_update_ref = strdup(*update_ref);
      from_update_ref = strdup(NanCString(args[0]->ToString(), NULL));
          } else {
      from_update_ref = 0;
    }
    //baton->update_ref = from_update_ref;
  //baton->authorReference = Persistent<Value>::New(args[1]);
  //convert: 
  const git_signature * from_author;
            from_author = ObjectWrap::Unwrap<GitSignature>(args[1]->ToObject())->GetValue();
        //baton->author = from_author;
  //baton->committerReference = Persistent<Value>::New(args[2]);
  //convert: 
  const git_signature * from_committer;
            from_committer = ObjectWrap::Unwrap<GitSignature>(args[2]->ToObject())->GetValue();
        //baton->committer = from_committer;
  //baton->message_encodingReference = Persistent<Value>::New(args[3]);
  //convert: 
  const char * from_message_encoding;
      if (args[3]->IsString()) {
            //String::Utf8Value message_encoding(args[3]->ToString());
      //from_message_encoding = strdup(*message_encoding);
      from_message_encoding = strdup(NanCString(args[3]->ToString(), NULL));
          } else {
      from_message_encoding = 0;
    }
    //baton->message_encoding = from_message_encoding;
  //baton->messageReference = Persistent<Value>::New(args[4]);
  //convert: 
  const char * from_message;
            //String::Utf8Value message(args[4]->ToString());
      //from_message = strdup(*message);
      from_message = strdup(NanCString(args[4]->ToString(), NULL));
        //baton->message = from_message;
  //baton->treeReference = Persistent<Value>::New(args[5]);
  //convert: 
  const git_tree * from_tree;
            from_tree = ObjectWrap::Unwrap<GitTree>(args[5]->ToObject())->GetValue();
        //baton->tree = from_tree;
  //baton->parent_countReference = Persistent<Value>::New(args[6]);
  //convert: 
  int from_parent_count;
            from_parent_count = (int)   args[6]->ToInt32()->Value();
        //baton->parent_count = from_parent_count;
  //baton->parentsReference = Persistent<Value>::New(args[7]);
  //convert: 
  const git_commit ** from_parents;
            Array *tmp_parents = Array::Cast(*args[7]);
      from_parents = (const git_commit **)malloc(tmp_parents->Length() * sizeof(const git_commit *));
      for (unsigned int i = 0; i < tmp_parents->Length(); i++) {
    
        from_parents[i] = ObjectWrap::Unwrap<GitCommit>(tmp_parents->Get(Number::New(static_cast<double>(i)))->ToObject())->GetValue();
      }
        //baton->parents = from_parents;
  NanCallback *callback = new NanCallback(args[8].As<v8::Function>());
  NanAsyncQueueWorker(new CreateCommitWorker(callback
      , args[1] //repo
      , args[2] //update_ref
      , args[3] //author
      , args[4] //committer
      , args[5] //message_encoding
      , args[6] //message
      , args[7] //tree
      , args[8] //parent_count
      , args[9] //parents
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Oid} id
 * @param {Number} type
 * @param {Object} callback
 */
class GetObjectWorker : public NanAsyncWorker {
  public:
    GetObjectWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> idReference
      , Local<Object> typeReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("id", idReference);
      SaveToPersistent("type", typeReference);
    }
    ~GetObjectWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->object != NULL) {
    to = GitObject::New((void *)this->object);
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
      int result = git_object_lookup(&this->object, this->repo, this->id, this->type);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_object * object;
    git_repository * repo;
    const git_oid * id;
    git_otype type;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::GetObject) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid id is required.");
  }
  if (args.Length() == 1 || !args[1]->IsInt32()) {
    NanThrowError("Number type is required.");
  }

  if (args.Length() == 2 || !args[2]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->idReference = Persistent<Value>::New(args[0]);
  //convert: 
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
        //baton->id = from_id;
  //baton->typeReference = Persistent<Value>::New(args[1]);
  //convert: 
  git_otype from_type;
            from_type = (git_otype)   args[1]->ToInt32()->Value();
        //baton->type = from_type;
  NanCallback *callback = new NanCallback(args[2].As<v8::Function>());
  NanAsyncQueueWorker(new GetObjectWorker(callback
      , args[1] //repo
      , args[2] //id
      , args[3] //type
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} name
 * @param {Reference} callback
 */
class GetReferenceWorker : public NanAsyncWorker {
  public:
    GetReferenceWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> nameReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("name", nameReference);
    }
    ~GetReferenceWorker() {}

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
      int result = git_reference_lookup(&this->out, this->repo, this->name);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_reference * out;
    git_repository * repo;
    const char * name;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::GetReference) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String name is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->nameReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_name;
            //String::Utf8Value name(args[0]->ToString());
      //from_name = strdup(*name);
      from_name = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->name = from_name;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new GetReferenceWorker(callback
      , args[1] //repo
      , args[2] //name
  );

  NanReturnUndefined();
}

/**
 * @param {String} name
 * @param {String} target
 * @param {Number} force
 * @return {Reference} out
 */
NAN_METHOD(GitRepo::CreateSymbolicReference) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String name is required.");
  }
  if (args.Length() == 1 || !args[1]->IsString()) {
    NanThrowError("String target is required.");
  }
  if (args.Length() == 2 || !args[2]->IsInt32()) {
    NanThrowError("Number force is required.");
  }

  git_reference * out = 0;

  const char * from_name;
            //String::Utf8Value name(args[0]->ToString());
      //from_name = strdup(*name);
      from_name = strdup(NanCString(args[0]->ToString(), NULL));
      
  const char * from_target;
            //String::Utf8Value target(args[1]->ToString());
      //from_target = strdup(*target);
      from_target = strdup(NanCString(args[1]->ToString(), NULL));
      
  int from_force;
            from_force = (int)   args[2]->ToInt32()->Value();
      
  int result = git_reference_symbolic_create(
    &out
    , ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue()
    , from_name
    , from_target
    , from_force
  );
  free((void *)from_name);
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
 * @param {String} name
 * @param {Oid} id
 * @param {Number} force
 * @return {Reference} out
 */
NAN_METHOD(GitRepo::CreateReference) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String name is required.");
  }
  if (args.Length() == 1 || !args[1]->IsObject()) {
    NanThrowError("Oid id is required.");
  }
  if (args.Length() == 2 || !args[2]->IsInt32()) {
    NanThrowError("Number force is required.");
  }

  git_reference * out = 0;

  const char * from_name;
            //String::Utf8Value name(args[0]->ToString());
      //from_name = strdup(*name);
      from_name = strdup(NanCString(args[0]->ToString(), NULL));
      
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[1]->ToObject())->GetValue();
      
  int from_force;
            from_force = (int)   args[2]->ToInt32()->Value();
      
  int result = git_reference_create(
    &out
    , ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue()
    , from_name
    , from_id
    , from_force
  );
  free((void *)from_name);
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
 * @param {String} name
 * @param {String} url
 * @param {Remote} callback
 */
class AddRemoteWorker : public NanAsyncWorker {
  public:
    AddRemoteWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> nameReference
      , Local<Object> urlReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("name", nameReference);
      SaveToPersistent("url", urlReference);
    }
    ~AddRemoteWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitRemote::New((void *)this->out);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {

  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
  free((void *)this->name);  free((void *)this->url);  //delete baton;
      // normal callback...
      //NanScope();

      //Local<Value> argv[] = {
      //  NanNew(NanNull()),
      //  NanNewBufferHandle((char*)resultdata, resultsize)
      //};

      //callback->Call(2, argv);
    }

    void Execute() {
      int result = git_remote_create(&this->out, this->repo, this->name, this->url);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_remote * out;
    git_repository * repo;
    const char * name;
    const char * url;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::AddRemote) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String name is required.");
  }
  if (args.Length() == 1 || !args[1]->IsString()) {
    NanThrowError("String url is required.");
  }

  if (args.Length() == 2 || !args[2]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->nameReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_name;
            //String::Utf8Value name(args[0]->ToString());
      //from_name = strdup(*name);
      from_name = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->name = from_name;
  //baton->urlReference = Persistent<Value>::New(args[1]);
  //convert: 
  const char * from_url;
            //String::Utf8Value url(args[1]->ToString());
      //from_url = strdup(*url);
      from_url = strdup(NanCString(args[1]->ToString(), NULL));
        //baton->url = from_url;
  NanCallback *callback = new NanCallback(args[2].As<v8::Function>());
  NanAsyncQueueWorker(new AddRemoteWorker(callback
      , args[1] //repo
      , args[2] //name
      , args[3] //url
  );

  NanReturnUndefined();
}

/**
 * @return {RevWalk} out
 */
NAN_METHOD(GitRepo::CreateRevWalk) {
  NanScope();
  
  git_revwalk * out = 0;

  int result = git_revwalk_new(
    &out
    , ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue()
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
    to = GitRevWalk::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {String} name
 * @return {Submodule} submodule
 */
NAN_METHOD(GitRepo::GetSubmodule) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String name is required.");
  }

  git_submodule * submodule = 0;

  const char * from_name;
            //String::Utf8Value name(args[0]->ToString());
      //from_name = strdup(*name);
      from_name = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_submodule_lookup(
    &submodule
    , ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue()
    , from_name
  );
  free((void *)from_name);
  if (result != GIT_OK) {
    const git_error* err;
    if ((err = giterr_last()) != NULL) {
      NanThrowError(err->message);
    } else {
      NanThrowError("Unknown Error");
    }
  }

  Handle<Value> to;
    if (submodule != NULL) {
    to = GitSubmodule::New((void *)submodule);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {String} url
 * @param {String} path
 * @param {Number} use_gitlink
 * @return {Submodule} submodule
 */
NAN_METHOD(GitRepo::AddSubmodule) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String url is required.");
  }
  if (args.Length() == 1 || !args[1]->IsString()) {
    NanThrowError("String path is required.");
  }
  if (args.Length() == 2 || !args[2]->IsInt32()) {
    NanThrowError("Number use_gitlink is required.");
  }

  git_submodule * submodule = 0;

  const char * from_url;
            //String::Utf8Value url(args[0]->ToString());
      //from_url = strdup(*url);
      from_url = strdup(NanCString(args[0]->ToString(), NULL));
      
  const char * from_path;
            //String::Utf8Value path(args[1]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[1]->ToString(), NULL));
      
  int from_use_gitlink;
            from_use_gitlink = (int)   args[2]->ToInt32()->Value();
      
  int result = git_submodule_add_setup(
    &submodule
    , ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue()
    , from_url
    , from_path
    , from_use_gitlink
  );
  free((void *)from_url);
  free((void *)from_path);
  if (result != GIT_OK) {
    const git_error* err;
    if ((err = giterr_last()) != NULL) {
      NanThrowError(err->message);
    } else {
      NanThrowError("Unknown Error");
    }
  }

  Handle<Value> to;
    if (submodule != NULL) {
    to = GitSubmodule::New((void *)submodule);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

#include "../include/functions/copy.h"

/**
 * @param {Oid} id
 * @param {Tag} callback
 */
class GetTagWorker : public NanAsyncWorker {
  public:
    GetTagWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> idReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("id", idReference);
    }
    ~GetTagWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitTag::New((void *)this->out);
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
      int result = git_tag_lookup(&this->out, this->repo, this->id);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_tag * out;
    git_repository * repo;
    const git_oid * id;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::GetTag) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid id is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->idReference = Persistent<Value>::New(args[0]);
  //convert: 
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
        //baton->id = from_id;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new GetTagWorker(callback
      , args[1] //repo
      , args[2] //id
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} tag_name
 * @param {Object} target
 * @param {Signature} tagger
 * @param {String} message
 * @param {Number} force
 * @param {Oid} callback
 */
class CreateTagWorker : public NanAsyncWorker {
  public:
    CreateTagWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> tag_nameReference
      , Local<Object> targetReference
      , Local<Object> taggerReference
      , Local<Object> messageReference
      , Local<Object> forceReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("tag_name", tag_nameReference);
      SaveToPersistent("target", targetReference);
      SaveToPersistent("tagger", taggerReference);
      SaveToPersistent("message", messageReference);
      SaveToPersistent("force", forceReference);
    }
    ~CreateTagWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->oid != NULL) {
    to = GitOid::New((void *)this->oid);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {
    free(this->oid );
    
  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
  free((void *)this->tag_name);  free((void *)this->message);  //delete baton;
      // normal callback...
      //NanScope();

      //Local<Value> argv[] = {
      //  NanNew(NanNull()),
      //  NanNewBufferHandle((char*)resultdata, resultsize)
      //};

      //callback->Call(2, argv);
    }

    void Execute() {
      this->oid = (git_oid *)malloc(sizeof(git_oid ));
      int result = git_tag_create(this->oid, this->repo, this->tag_name, this->target, this->tagger, this->message, this->force);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * oid;
    git_repository * repo;
    const char * tag_name;
    const git_object * target;
    const git_signature * tagger;
    const char * message;
    int force;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::CreateTag) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String tag_name is required.");
  }
  if (args.Length() == 1 || !args[1]->IsObject()) {
    NanThrowError("Object target is required.");
  }
  if (args.Length() == 2 || !args[2]->IsObject()) {
    NanThrowError("Signature tagger is required.");
  }
  if (args.Length() == 3 || !args[3]->IsString()) {
    NanThrowError("String message is required.");
  }
  if (args.Length() == 4 || !args[4]->IsInt32()) {
    NanThrowError("Number force is required.");
  }

  if (args.Length() == 5 || !args[5]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->tag_nameReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_tag_name;
            //String::Utf8Value tag_name(args[0]->ToString());
      //from_tag_name = strdup(*tag_name);
      from_tag_name = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->tag_name = from_tag_name;
  //baton->targetReference = Persistent<Value>::New(args[1]);
  //convert: 
  const git_object * from_target;
            from_target = ObjectWrap::Unwrap<GitObject>(args[1]->ToObject())->GetValue();
        //baton->target = from_target;
  //baton->taggerReference = Persistent<Value>::New(args[2]);
  //convert: 
  const git_signature * from_tagger;
            from_tagger = ObjectWrap::Unwrap<GitSignature>(args[2]->ToObject())->GetValue();
        //baton->tagger = from_tagger;
  //baton->messageReference = Persistent<Value>::New(args[3]);
  //convert: 
  const char * from_message;
            //String::Utf8Value message(args[3]->ToString());
      //from_message = strdup(*message);
      from_message = strdup(NanCString(args[3]->ToString(), NULL));
        //baton->message = from_message;
  //baton->forceReference = Persistent<Value>::New(args[4]);
  //convert: 
  int from_force;
            from_force = (int)   args[4]->ToInt32()->Value();
        //baton->force = from_force;
  NanCallback *callback = new NanCallback(args[5].As<v8::Function>());
  NanAsyncQueueWorker(new CreateTagWorker(callback
      , args[1] //repo
      , args[2] //tag_name
      , args[3] //target
      , args[4] //tagger
      , args[5] //message
      , args[6] //force
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} tag_name
 * @param {Object} target
 * @param {Number} force
 * @param {Oid} callback
 */
class CreateLightweightTagWorker : public NanAsyncWorker {
  public:
    CreateLightweightTagWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> tag_nameReference
      , Local<Object> targetReference
      , Local<Object> forceReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("tag_name", tag_nameReference);
      SaveToPersistent("target", targetReference);
      SaveToPersistent("force", forceReference);
    }
    ~CreateLightweightTagWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->oid != NULL) {
    to = GitOid::New((void *)this->oid);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {
    free(this->oid );
    
  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
  free((void *)this->tag_name);  //delete baton;
      // normal callback...
      //NanScope();

      //Local<Value> argv[] = {
      //  NanNew(NanNull()),
      //  NanNewBufferHandle((char*)resultdata, resultsize)
      //};

      //callback->Call(2, argv);
    }

    void Execute() {
      this->oid = (git_oid *)malloc(sizeof(git_oid ));
      int result = git_tag_create_lightweight(this->oid, this->repo, this->tag_name, this->target, this->force);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * oid;
    git_repository * repo;
    const char * tag_name;
    const git_object * target;
    int force;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::CreateLightweightTag) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String tag_name is required.");
  }
  if (args.Length() == 1 || !args[1]->IsObject()) {
    NanThrowError("Object target is required.");
  }
  if (args.Length() == 2 || !args[2]->IsInt32()) {
    NanThrowError("Number force is required.");
  }

  if (args.Length() == 3 || !args[3]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->tag_nameReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_tag_name;
            //String::Utf8Value tag_name(args[0]->ToString());
      //from_tag_name = strdup(*tag_name);
      from_tag_name = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->tag_name = from_tag_name;
  //baton->targetReference = Persistent<Value>::New(args[1]);
  //convert: 
  const git_object * from_target;
            from_target = ObjectWrap::Unwrap<GitObject>(args[1]->ToObject())->GetValue();
        //baton->target = from_target;
  //baton->forceReference = Persistent<Value>::New(args[2]);
  //convert: 
  int from_force;
            from_force = (int)   args[2]->ToInt32()->Value();
        //baton->force = from_force;
  NanCallback *callback = new NanCallback(args[3].As<v8::Function>());
  NanAsyncQueueWorker(new CreateLightweightTagWorker(callback
      , args[1] //repo
      , args[2] //tag_name
      , args[3] //target
      , args[4] //force
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Oid} id
 * @param {Tree} callback
 */
class GetTreeWorker : public NanAsyncWorker {
  public:
    GetTreeWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> idReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("id", idReference);
    }
    ~GetTreeWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitTree::New((void *)this->out);
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
      int result = git_tree_lookup(&this->out, this->repo, this->id);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_tree * out;
    git_repository * repo;
    const git_oid * id;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::GetTree) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid id is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->idReference = Persistent<Value>::New(args[0]);
  //convert: 
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
        //baton->id = from_id;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new GetTreeWorker(callback
      , args[1] //repo
      , args[2] //id
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 */
class ReloadSubmodulesWorker : public NanAsyncWorker {
  public:
    ReloadSubmodulesWorker(NanCallback *callback
      , Local<Object> repoReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
    }
    ~ReloadSubmodulesWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRepo::ReloadSubmodules) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new ReloadSubmodulesWorker(callback
      , args[0] //repo
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} tag_name
 */
class DeleteWorker : public NanAsyncWorker {
  public:
    DeleteWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> tag_nameReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("tag_name", tag_nameReference);
    }
    ~DeleteWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
        callback->Call(0, NULL);


NAN_METHOD(GitRepo::Delete) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String tag_name is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->tag_nameReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_tag_name;
            //String::Utf8Value tag_name(args[0]->ToString());
      //from_tag_name = strdup(*tag_name);
      from_tag_name = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->tag_name = from_tag_name;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new DeleteWorker(callback
      , args[0] //repo
      , args[1] //tag_name
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Number} list_flags
 * @param {Array} callback
 */
class GetReferencesWorker : public NanAsyncWorker {
  public:
    GetReferencesWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> list_flagsReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("list_flags", list_flagsReference);
    }
    ~GetReferencesWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
      
  Local<Array> tmpArray = Array::New(this->array->count);
  for (unsigned int i = 0; i < this->array->count; i++) {
    tmpArray->Set(Number::New(i), NanNew<String>(this->array->strings[i]));
  }
  to = tmpArray;
      Handle<Value> result = to;
  } else {
    free(this->array );
    
  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
    git_strarray_free(this->array);
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
      this->array = (git_strarray *)malloc(sizeof(git_strarray ));
      int result = git_reference_list(this->array, this->repo, this->list_flags);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_strarray * array;
    git_repository * repo;
    unsigned int list_flags;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::GetReferences) {
  NanScope();

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->list_flagsReference = Persistent<Value>::New(args[0]);
  //convert: 
  unsigned int from_list_flags;
      if (args[0]->IsUint32()) {
            from_list_flags = (unsigned int)   args[0]->ToUint32()->Value();
          } else {
      from_list_flags = 0;
    }
    //baton->list_flags = from_list_flags;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new GetReferencesWorker(callback
      , args[1] //repo
      , args[2] //list_flags
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Buffer} buffer
 * @param {Number} len
 * @param {Oid} callback
 */
class CreateBlobFromBufferWorker : public NanAsyncWorker {
  public:
    CreateBlobFromBufferWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> bufferReference
      , Local<Object> lenReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("buffer", bufferReference);
      SaveToPersistent("len", lenReference);
    }
    ~CreateBlobFromBufferWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->oid != NULL) {
    to = GitOid::New((void *)this->oid);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {
    free(this->oid );
    
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
      this->oid = (git_oid *)malloc(sizeof(git_oid ));
      int result = git_blob_create_frombuffer(this->oid, this->repo, this->buffer, this->len);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * oid;
    git_repository * repo;
    const void * buffer;
    size_t len;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::CreateBlobFromBuffer) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Buffer buffer is required.");
  }
  if (args.Length() == 1 || !args[1]->IsNumber()) {
    NanThrowError("Number len is required.");
  }

  if (args.Length() == 2 || !args[2]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->bufferReference = Persistent<Value>::New(args[0]);
  //convert: 
  const void * from_buffer;
            from_buffer = Buffer::Data(args[0]->ToObject());
        //baton->buffer = from_buffer;
  //baton->lenReference = Persistent<Value>::New(args[1]);
  //convert: 
  size_t from_len;
            from_len = (size_t)   args[1]->ToNumber()->Value();
        //baton->len = from_len;
  NanCallback *callback = new NanCallback(args[2].As<v8::Function>());
  NanAsyncQueueWorker(new CreateBlobFromBufferWorker(callback
      , args[1] //repo
      , args[2] //buffer
      , args[3] //len
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} path
 * @param {Oid} callback
 */
class CreateBlobFromFileWorker : public NanAsyncWorker {
  public:
    CreateBlobFromFileWorker(NanCallback *callback
      , Local<Object> repoReference
      , Local<Object> pathReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
      SaveToPersistent("path", pathReference);
    }
    ~CreateBlobFromFileWorker() {}

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
      this->id = (git_oid *)malloc(sizeof(git_oid ));
      int result = git_blob_create_fromdisk(this->id, this->repo, this->path);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * id;
    git_repository * repo;
    const char * path;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::CreateBlobFromFile) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  //baton->pathReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->path = from_path;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new CreateBlobFromFileWorker(callback
      , args[1] //repo
      , args[2] //path
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {Array} callback
 */
class GetRemotesWorker : public NanAsyncWorker {
  public:
    GetRemotesWorker(NanCallback *callback
      , Local<Object> repoReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("repo", repoReference);
    }
    ~GetRemotesWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
      
  Local<Array> tmpArray = Array::New(this->out->count);
  for (unsigned int i = 0; i < this->out->count; i++) {
    tmpArray->Set(Number::New(i), NanNew<String>(this->out->strings[i]));
  }
  to = tmpArray;
      Handle<Value> result = to;
  } else {
    free(this->out );
    
  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
    git_strarray_free(this->out);
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
      this->out = (git_strarray *)malloc(sizeof(git_strarray ));
      int result = git_remote_list(this->out, this->repo);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_strarray * out;
    git_repository * repo;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::GetRemotes) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->repoReference = Persistent<Value>::New(args.This());
  GitRepo* repo = ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue();
  NanCallback *callback = new NanCallback(args[0].As<v8::Function>());
  NanAsyncQueueWorker(new GetRemotesWorker(callback
      , args[1] //repo
  );

  NanReturnUndefined();
}

#include "../include/functions/copy.h"

/**
 * @param {String} url
 * @param {String} local_path
 * @param {CloneOptions} options
 * @param {Repository} callback
 */
class CloneWorker : public NanAsyncWorker {
  public:
    CloneWorker(NanCallback *callback
      , Local<Object> urlReference
      , Local<Object> local_pathReference
      , Local<Object> optionsReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("url", urlReference);
      SaveToPersistent("local_path", local_pathReference);
      SaveToPersistent("options", optionsReference);
    }
    ~CloneWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitRepo::New((void *)this->out);
  } else {
    to = NanNew(NanNull());
  }
      Handle<Value> result = to;
  } else {

  }

  if (try_catch.HasCaught()) {
    node::FatalException(try_catch);
  }
  free((void *)this->url);  free((void *)this->local_path);  //delete baton;
      // normal callback...
      //NanScope();

      //Local<Value> argv[] = {
      //  NanNew(NanNull()),
      //  NanNewBufferHandle((char*)resultdata, resultsize)
      //};

      //callback->Call(2, argv);
    }

    void Execute() {
      int result = git_clone(&this->out, this->url, this->local_path, this->options);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_repository * out;
    const char * url;
    const char * local_path;
    const git_clone_options * options;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitRepo::Clone) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String url is required.");
  }
  if (args.Length() == 1 || !args[1]->IsString()) {
    NanThrowError("String local_path is required.");
  }

  if (args.Length() == 3 || !args[3]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //baton->urlReference = Persistent<Value>::New(args[0]);
  //convert: 
  const char * from_url;
            //String::Utf8Value url(args[0]->ToString());
      //from_url = strdup(*url);
      from_url = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->url = from_url;
  //baton->local_pathReference = Persistent<Value>::New(args[1]);
  //convert: 
  const char * from_local_path;
            //String::Utf8Value local_path(args[1]->ToString());
      //from_local_path = strdup(*local_path);
      from_local_path = strdup(NanCString(args[1]->ToString(), NULL));
        //baton->local_path = from_local_path;
  //baton->optionsReference = Persistent<Value>::New(args[2]);
  //convert: 
  const git_clone_options * from_options;
      if (args[2]->IsObject()) {
            from_options = ObjectWrap::Unwrap<GitCloneOptions>(args[2]->ToObject())->GetValue();
          } else {
      from_options = 0;
    }
    //baton->options = from_options;
  NanCallback *callback = new NanCallback(args[3].As<v8::Function>());
  NanAsyncQueueWorker(new CloneWorker(callback
      , args[1] //url
      , args[2] //local_path
      , args[3] //options
  );

  NanReturnUndefined();
}

/**
 * @param {String} name
 * @return {Remote} out
 */
NAN_METHOD(GitRepo::GetRemote) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String name is required.");
  }

  git_remote * out = 0;

  const char * from_name;
            //String::Utf8Value name(args[0]->ToString());
      //from_name = strdup(*name);
      from_name = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_remote_load(
    &out
    , ObjectWrap::Unwrap<GitRepo>(args.This())->GetValue()
    , from_name
  );
  free((void *)from_name);
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
    to = GitRemote::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

Persistent<Function> GitRepo::constructor_template;
