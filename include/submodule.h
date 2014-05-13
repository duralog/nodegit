/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITSUBMODULE_H
#define GITSUBMODULE_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitSubmodule : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_submodule *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitSubmodule(git_submodule *raw);
    ~GitSubmodule();

    static NAN_METHOD(New);


    static NAN_METHOD(AddFinalize);

    static NAN_METHOD(AddToIndex);

    static NAN_METHOD(Save);

    static NAN_METHOD(Name);

    static NAN_METHOD(Path);

    static NAN_METHOD(Url);

    static NAN_METHOD(SetUrl);

    static NAN_METHOD(IndexId);

    static NAN_METHOD(HeadId);

    static NAN_METHOD(Init);

    static NAN_METHOD(Sync);

    static NAN_METHOD(Open);

    static NAN_METHOD(Reload);

    static NAN_METHOD(Status);

    git_submodule *raw;
};

#endif
