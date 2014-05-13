/**
 * This code is auto-generated; unless you know what you're doing, do not modify!
 **/

#ifndef GITREMOTE_H
#define GITREMOTE_H

#include <v8.h>
#include <node.h>
#include <string>

#include "git2.h"

using namespace node;
using namespace v8;

class GitRemote : public ObjectWrap {
  public:

    static Persistent<Function> constructor_template;
    static void Initialize (Handle<v8::Object> target);

    git_remote *GetValue();

    static Handle<Value> New(void *raw);

  private:
    GitRemote(git_remote *raw);
    ~GitRemote();

    static NAN_METHOD(New);


    static NAN_METHOD(Name);

    static NAN_METHOD(Url);

    static NAN_METHOD(PushUrl);

    static NAN_METHOD(SetUrl);

    static NAN_METHOD(SetPushUrl);

    static NAN_METHOD(Connect);

    static NAN_METHOD(Download);

    static NAN_METHOD(Connected);

    static NAN_METHOD(Stop);

    static NAN_METHOD(Disconnect);

    static NAN_METHOD(UpdateTips);

    static NAN_METHOD(ValidUrl);

    static NAN_METHOD(SupportedUrl);

    static NAN_METHOD(CheckCert);

    static NAN_METHOD(UpdateFetchhead);

    static NAN_METHOD(SetUpdateFetchhead);

    static NAN_METHOD(IsValidName);

    git_remote *raw;
};

#endif
