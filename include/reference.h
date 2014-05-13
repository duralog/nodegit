/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITREFERENCE_H
#define GITREFERENCE_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitReference : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_reference *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitReference(git_reference *raw);
    ~GitReference();

    static NAN_METHOD(New);


    static NAN_METHOD(OidForName);

    static NAN_METHOD(Target);

    static NAN_METHOD(SymbolicTarget);

    static NAN_METHOD(Type);

    static NAN_METHOD(Name);

    static NAN_METHOD(Resolve);

    static NAN_METHOD(SetSymbolicTarget);

    static NAN_METHOD(setTarget);

    static NAN_METHOD(Rename);

    static NAN_METHOD(Delete);

    static NAN_METHOD(IsBranch);

    static NAN_METHOD(IsRemote);

    static NAN_METHOD(Peel);

    static NAN_METHOD(IsValidName);

    git_reference *raw;
};

#endif
