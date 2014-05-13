/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITINDEX_H
#define GITINDEX_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitIndex : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_index *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitIndex(git_index *raw);
    ~GitIndex();

    static NAN_METHOD(New);


    static NAN_METHOD(Open);

    static NAN_METHOD(Read);

    static NAN_METHOD(Write);

    static NAN_METHOD(ReadTree);

    static NAN_METHOD(WriteTree);

    static NAN_METHOD(Size);

    static NAN_METHOD(Clear);

    static NAN_METHOD(Entry);

    static NAN_METHOD(Remove);

    static NAN_METHOD(RemoveDirectory);

    static NAN_METHOD(AddBypath);

    static NAN_METHOD(RemoveBypath);

    static NAN_METHOD(Find);

    static NAN_METHOD(ConflictRemove);

    static NAN_METHOD(ConflictCleanup);

    static NAN_METHOD(HasConflicts);

    static NAN_METHOD(IndexToWorkdir);

    git_index *raw;
};

#endif
