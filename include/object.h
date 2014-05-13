/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITOBJECT_H
#define GITOBJECT_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitObject : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_object *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitObject(git_object *raw);
    ~GitObject();

    static NAN_METHOD(New);


    static NAN_METHOD(Oid);

    static NAN_METHOD(Type);

    static NAN_METHOD(Peel);

    git_object *raw;
};

#endif
