/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITREPO_H
#define GITREPO_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitRepo : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_repository *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitRepo(git_repository *raw);
    ~GitRepo();

    static NAN_METHOD(New);


    static NAN_METHOD(Open);

    static NAN_METHOD(Init);

    static NAN_METHOD(Path);

    static NAN_METHOD(Workdir);

    static NAN_METHOD(Odb);

    static NAN_METHOD(openIndex);

    static NAN_METHOD(GetBlob);

    static NAN_METHOD(GetCommit);

    static NAN_METHOD(CreateCommit);

    static NAN_METHOD(GetObject);

    static NAN_METHOD(GetReference);

    static NAN_METHOD(CreateSymbolicReference);

    static NAN_METHOD(CreateReference);

    static NAN_METHOD(AddRemote);

    static NAN_METHOD(CreateRevWalk);

    static NAN_METHOD(GetSubmodule);

    static NAN_METHOD(AddSubmodule);

    static NAN_METHOD(GetTag);

    static NAN_METHOD(CreateTag);

    static NAN_METHOD(CreateLightweightTag);

    static NAN_METHOD(GetTree);

    static NAN_METHOD(ReloadSubmodules);

    static NAN_METHOD(Delete);

    static NAN_METHOD(GetReferences);

    static NAN_METHOD(CreateBlobFromBuffer);

    static NAN_METHOD(CreateBlobFromFile);

    static NAN_METHOD(GetRemotes);

    static NAN_METHOD(Clone);

    static NAN_METHOD(GetRemote);

    git_repository *raw;
};

#endif
