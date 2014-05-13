/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITODB_H
#define GITODB_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitOdb : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_odb *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitOdb(git_odb *raw);
    ~GitOdb();

    static NAN_METHOD(New);


    static NAN_METHOD(Create);

    static NAN_METHOD(Open);

    static NAN_METHOD(AddDiskAlternate);

    static NAN_METHOD(Read);

    static NAN_METHOD(ReadPrefix);

    static NAN_METHOD(ReadHeader);

    static NAN_METHOD(Exists);

    static NAN_METHOD(Refresh);

    static NAN_METHOD(Write);

    static NAN_METHOD(Hash);

    static NAN_METHOD(Hashfile);

    git_odb *raw;
};

#endif
