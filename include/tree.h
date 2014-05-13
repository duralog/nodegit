/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITTREE_H
#define GITTREE_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitTree : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_tree *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitTree(git_tree *raw);
    ~GitTree();

    static NAN_METHOD(New);


    static NAN_METHOD(Oid);

    static NAN_METHOD(Size);

    static NAN_METHOD(EntryByName);

    static NAN_METHOD(EntryByIndex);

    static NAN_METHOD(EntryByOid);

    static NAN_METHOD(GetEntry);

    static NAN_METHOD(Builder);

    static NAN_METHOD(DiffTree);

    static NAN_METHOD(DiffIndex);

    static NAN_METHOD(DiffWorkDir);

    git_tree *raw;
};

#endif
