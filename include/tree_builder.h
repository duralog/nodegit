/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITTREEBUILDER_H
#define GITTREEBUILDER_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitTreeBuilder : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_treebuilder *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitTreeBuilder(git_treebuilder *raw);
    ~GitTreeBuilder();

    static NAN_METHOD(New);


    static NAN_METHOD(Create);

    static NAN_METHOD(Clear);

    static NAN_METHOD(Size);

    static NAN_METHOD(Get);

    static NAN_METHOD(Insert);

    static NAN_METHOD(GitTreebuilderRemove);

    static NAN_METHOD(Write);

    git_treebuilder *raw;
};

#endif
