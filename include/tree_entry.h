/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITTREEENTRY_H
#define GITTREEENTRY_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitTreeEntry : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_tree_entry *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitTreeEntry(git_tree_entry *raw);
    ~GitTreeEntry();

    static NAN_METHOD(New);


    static NAN_METHOD(Name);

    static NAN_METHOD(Oid);

    static NAN_METHOD(Type);

    static NAN_METHOD(filemode);

    static NAN_METHOD(GetObject);

    git_tree_entry *raw;
};

#endif
