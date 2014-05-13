/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITREVWALK_H
#define GITREVWALK_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitRevWalk : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_revwalk *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitRevWalk(git_revwalk *raw);
    ~GitRevWalk();

    static NAN_METHOD(New);


    static NAN_METHOD(Reset);

    static NAN_METHOD(Push);

    static NAN_METHOD(PushGlob);

    static NAN_METHOD(PushHead);

    static NAN_METHOD(Hide);

    static NAN_METHOD(HideGlob);

    static NAN_METHOD(HideHead);

    static NAN_METHOD(PushRef);

    static NAN_METHOD(HideRef);

    static NAN_METHOD(Next);

    static NAN_METHOD(Sorting);

    git_revwalk *raw;
};

#endif
