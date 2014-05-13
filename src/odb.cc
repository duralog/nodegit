/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/
#include <nan.h>
#include <string.h>

#include "git2.h"

#include "../include/functions/copy.h"

#include "../include/odb.h"
#include "../include/oid.h"
#include "../include/odb_object.h"
#include "node_buffer.h"

using namespace v8;
using namespace node;

GitOdb::GitOdb(git_odb *raw) {
  this->raw = raw;
}

GitOdb::~GitOdb() {
  git_odb_free(this->raw);
}

void GitOdb::Initialize(Handle<v8::Object> target) {
  NanScope();

  Local<FunctionTemplate> tpl = NanNew<FunctionTemplate>(New);

  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  tpl->SetClassName(NanSymbol("Odb"));

  NODE_SET_METHOD(tpl, "create()", Create);
  NODE_SET_METHOD(tpl, "open", Open);
  NODE_SET_PROTOTYPE_METHOD(tpl, "addDiskAlternate", AddDiskAlternate);
  NODE_SET_PROTOTYPE_METHOD(tpl, "read", Read);
  NODE_SET_METHOD(tpl, "readPrefix", ReadPrefix);
  NODE_SET_METHOD(tpl, "readHeader", ReadHeader);
  NODE_SET_PROTOTYPE_METHOD(tpl, "exists", Exists);
  NODE_SET_PROTOTYPE_METHOD(tpl, "refresh", Refresh);
  NODE_SET_PROTOTYPE_METHOD(tpl, "write", Write);
  NODE_SET_METHOD(tpl, "hash", Hash);
  NODE_SET_METHOD(tpl, "hashfile", Hashfile);


  //constructor_template = Persistent<Function>::New(tpl->GetFunction());
  Local<Function> _constructor_template = tpl->GetFunction();
  NanAssignPersistent(constructor_template, _constructor_template);
  target->Set(NanSymbol("Odb"), _constructor_template);
}

NAN_METHOD(GitOdb::New) {
  NanScope();

  if (args.Length() == 0 || !args[0]->IsExternal()) {
    NanThrowError("git_odb is required.");
  }

  //GitOdb* object = new GitOdb((git_odb *) External::Unwrap(args[0]));
  GitOdb* object = ObjectWrap::Unwrap<GitOdb>(args[0]->ToObject());
  object->Wrap(args.This());

  NanReturnValue(args.This());
}

Handle<Value> GitOdb::New(void *raw) {
  NanEscapableScope();
  Handle<Value> argv[1] = { NanNew<External>((void *)raw) };
  return NanEscapeScope(NanNew<Function>(GitOdb::constructor_template)->NewInstance(1, argv));
  //return scope.Close(GitOdb::constructor_template->NewInstance(1, argv));
}

git_odb *GitOdb::GetValue() {
  return this->raw;
}


/**
 * @return {Odb} out
 */
NAN_METHOD(GitOdb::Create) {
  NanScope();
  
  git_odb * out = 0;

  int result = git_odb_new(
    &out
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

/**
 * @param {String} objects_dir
 * @return {Odb} out
 */
NAN_METHOD(GitOdb::Open) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String objects_dir is required.");
  }

  git_odb * out = 0;

  const char * from_objects_dir;
            //String::Utf8Value objects_dir(args[0]->ToString());
      //from_objects_dir = strdup(*objects_dir);
      from_objects_dir = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_odb_open(
    &out
    , from_objects_dir
  );
  free((void *)from_objects_dir);
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

/**
 * @param {String} path
 */
NAN_METHOD(GitOdb::AddDiskAlternate) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }


  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
      
  int result = git_odb_add_disk_alternate(
    ObjectWrap::Unwrap<GitOdb>(args.This())->GetValue()
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

#include "../include/functions/copy.h"

/**
 * @param {Oid} id
 * @param {OdbObject} callback
 */
class ReadWorker : public NanAsyncWorker {
  public:
    ReadWorker(NanCallback *callback
      , Local<Object> dbReference
      , Local<Object> idReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("db", dbReference);
      SaveToPersistent("id", idReference);
    }
    ~ReadWorker() {}

    void HandleOKCallback() {
      TryCatch try_catch;
      if(this->error_code == GIT_OK) {
      Handle<Value> to;
        if (this->out != NULL) {
    to = GitOdbObject::New((void *)this->out);
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
      int result = git_odb_read(&this->out, this->db, this->id);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_odb_object * out;
    git_odb * db;
    const git_oid * id;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitOdb::Read) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid id is required.");
  }

  if (args.Length() == 1 || !args[1]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->dbReference = Persistent<Value>::New(args.This());
  GitOdb* db = ObjectWrap::Unwrap<GitOdb>(args.This())->GetValue();
  //baton->idReference = Persistent<Value>::New(args[0]);
  //convert: 
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
        //baton->id = from_id;
  NanCallback *callback = new NanCallback(args[1].As<v8::Function>());
  NanAsyncQueueWorker(new ReadWorker(callback
      , args[1] //db
      , args[2] //id
  );

  NanReturnUndefined();
}

/**
 * @param {Odb} db
 * @param {Oid} short_id
 * @param {Number} len
 * @return {OdbObject} out
 */
NAN_METHOD(GitOdb::ReadPrefix) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Odb db is required.");
  }
  if (args.Length() == 1 || !args[1]->IsObject()) {
    NanThrowError("Oid short_id is required.");
  }
  if (args.Length() == 2 || !args[2]->IsUint32()) {
    NanThrowError("Number len is required.");
  }

  git_odb_object * out = 0;

  git_odb * from_db;
            from_db = ObjectWrap::Unwrap<GitOdb>(args[0]->ToObject())->GetValue();
      
  const git_oid * from_short_id;
            from_short_id = ObjectWrap::Unwrap<GitOid>(args[1]->ToObject())->GetValue();
      
  size_t from_len;
            from_len = (size_t)   args[2]->ToUint32()->Value();
      
  int result = git_odb_read_prefix(
    &out
    , from_db
    , from_short_id
    , from_len
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
    to = GitOdbObject::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {Odb} db
 * @param {Oid} id
 * @return {Number} len_out
 * @return {Number} type_out
 */
NAN_METHOD(GitOdb::ReadHeader) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Odb db is required.");
  }
  if (args.Length() == 1 || !args[1]->IsObject()) {
    NanThrowError("Oid id is required.");
  }

  size_t len_out = 0;
  git_otype type_out = GIT_OBJ_ANY;

  git_odb * from_db;
            from_db = ObjectWrap::Unwrap<GitOdb>(args[0]->ToObject())->GetValue();
      
  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[1]->ToObject())->GetValue();
      
  int result = git_odb_read_header(
    &len_out
    , &type_out
    , from_db
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

  Handle<Object> toReturn = NanNew<Object>();
  Handle<Value> to;
      to = NanNew<Uint32>(len_out);
    toReturn->Set(NanSymbol("len_out"), to);

      to = NanNew<Int32>(type_out);
    toReturn->Set(NanSymbol("type_out"), to);

  NanReturnValue(toReturn);
}

/**
 * @param {Oid} id
 */
NAN_METHOD(GitOdb::Exists) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Oid id is required.");
  }


  const git_oid * from_id;
            from_id = ObjectWrap::Unwrap<GitOid>(args[0]->ToObject())->GetValue();
      
  int result = git_odb_exists(
    ObjectWrap::Unwrap<GitOdb>(args.This())->GetValue()
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

  NanReturnUndefined();
}

/**
 */
NAN_METHOD(GitOdb::Refresh) {
  NanScope();
  

  int result = git_odb_refresh(
    ObjectWrap::Unwrap<GitOdb>(args.This())->GetValue()
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

#include "../include/functions/copy.h"

/**
 * @param {String} data
 * @param {Number} len
 * @param {Number} type
 * @param {Oid} callback
 */
class WriteWorker : public NanAsyncWorker {
  public:
    WriteWorker(NanCallback *callback
      , Local<Object> odbReference
      , Local<Object> dataReference
      , Local<Object> lenReference
      , Local<Object> typeReference
    ) : NanAsyncWorker(callback), error_code(GIT_OK) {
      SaveToPersistent("odb", odbReference);
      SaveToPersistent("data", dataReference);
      SaveToPersistent("len", lenReference);
      SaveToPersistent("type", typeReference);
    }
    ~WriteWorker() {}

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
  free((void *)this->data);  //delete baton;
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
      int result = git_odb_write(this->out, this->odb, this->data, this->len, this->type);
      this->error_code = result;
      const git_error* err;
      if (result != GIT_OK && (err = giterr_last()) != NULL) {
        SetErrorMessage(err->message);
      }
    }

  private:
    git_oid * out;
    git_odb * odb;
    const void * data;
    size_t len;
    git_otype type;
    int error_code;
    //const git_error* error;
};



NAN_METHOD(GitOdb::Write) {
  NanScope();
  if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String data is required.");
  }
  if (args.Length() == 1 || !args[1]->IsUint32()) {
    NanThrowError("Number len is required.");
  }
  if (args.Length() == 2 || !args[2]->IsInt32()) {
    NanThrowError("Number type is required.");
  }

  if (args.Length() == 3 || !args[3]->IsFunction()) {
    NanThrowError("Callback is required and must be a Function.");
  }
  //this->odbReference = Persistent<Value>::New(args.This());
  GitOdb* odb = ObjectWrap::Unwrap<GitOdb>(args.This())->GetValue();
  //baton->dataReference = Persistent<Value>::New(args[0]);
  //convert: 
  const void * from_data;
            //String::Utf8Value data(args[0]->ToString());
      //from_data = strdup(*data);
      from_data = strdup(NanCString(args[0]->ToString(), NULL));
        //baton->data = from_data;
  //baton->lenReference = Persistent<Value>::New(args[1]);
  //convert: 
  size_t from_len;
            from_len = (size_t)   args[1]->ToUint32()->Value();
        //baton->len = from_len;
  //baton->typeReference = Persistent<Value>::New(args[2]);
  //convert: 
  git_otype from_type;
            from_type = (git_otype)   args[2]->ToInt32()->Value();
        //baton->type = from_type;
  NanCallback *callback = new NanCallback(args[3].As<v8::Function>());
  NanAsyncQueueWorker(new WriteWorker(callback
      , args[1] //odb
      , args[2] //data
      , args[3] //len
      , args[4] //type
  );

  NanReturnUndefined();
}

/**
 * @param {Buffer} data
 * @param {Number} len
 * @param {Number} type
 * @return {Oid} out
 */
NAN_METHOD(GitOdb::Hash) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsObject()) {
    NanThrowError("Buffer data is required.");
  }
  if (args.Length() == 1 || !args[1]->IsUint32()) {
    NanThrowError("Number len is required.");
  }
  if (args.Length() == 2 || !args[2]->IsInt32()) {
    NanThrowError("Number type is required.");
  }

  git_oid *out = (git_oid *)malloc(sizeof(git_oid));

  const void * from_data;
            from_data = Buffer::Data(args[0]->ToObject());
      
  size_t from_len;
            from_len = (size_t)   args[1]->ToUint32()->Value();
      
  git_otype from_type;
            from_type = (git_otype)   args[2]->ToInt32()->Value();
      
  int result = git_odb_hash(
    out
    , from_data
    , from_len
    , from_type
  );
  if (result != GIT_OK) {
    free(out);
    const git_error* err;
    if ((err = giterr_last()) != NULL) {
      NanThrowError(err->message);
    } else {
      NanThrowError("Unknown Error");
    }
  }

  Handle<Value> to;
    if (out != NULL) {
    to = GitOid::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

/**
 * @param {String} path
 * @param {Number} type
 * @return {Oid} out
 */
NAN_METHOD(GitOdb::Hashfile) {
  NanScope();
    if (args.Length() == 0 || !args[0]->IsString()) {
    NanThrowError("String path is required.");
  }
  if (args.Length() == 1 || !args[1]->IsInt32()) {
    NanThrowError("Number type is required.");
  }

  git_oid *out = (git_oid *)malloc(sizeof(git_oid));

  const char * from_path;
            //String::Utf8Value path(args[0]->ToString());
      //from_path = strdup(*path);
      from_path = strdup(NanCString(args[0]->ToString(), NULL));
      
  git_otype from_type;
            from_type = (git_otype)   args[1]->ToInt32()->Value();
      
  int result = git_odb_hashfile(
    out
    , from_path
    , from_type
  );
  free((void *)from_path);
  if (result != GIT_OK) {
    free(out);
    const git_error* err;
    if ((err = giterr_last()) != NULL) {
      NanThrowError(err->message);
    } else {
      NanThrowError("Unknown Error");
    }
  }

  Handle<Value> to;
    if (out != NULL) {
    to = GitOid::New((void *)out);
  } else {
    to = NanNew(NanNull());
  }
  NanReturnValue(to);
}

Persistent<Function> GitOdb::constructor_template;
