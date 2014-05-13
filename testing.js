function testing(locals, filters, escape, rethrow) {
var __stack = { lineno: 1, input: "/**\n * This code is auto-generated; unless you know what you're doing, do not modify!\n **/\n\n#ifndef <%- cppClassName.toUpperCase() %>_H\n#define <%- cppClassName.toUpperCase() %>_H\n\n#include <v8.h>\n#include <node.h>\n#include <string>\n\n#include \"git2.h\"\n\nusing namespace node;\nusing namespace v8;\n\nclass <%- cppClassName %> : public ObjectWrap {\n  public:\n\n    static Persistent<Function> constructor_template;\n    static void Initialize (Handle<v8::Object> target);\n\n<% if (typeof cType != 'undefined') { -%>\n    <%- cType %> *GetValue();\n\n    static Handle<Value> New(void *raw);\n<% } -%>\n\n  private:\n<% if (typeof cType != 'undefined') { -%>\n    <%- cppClassName %>(<%- cType %> *raw);\n    ~<%- cppClassName %>();\n<% } -%>\n\n    static NAN_METHOD(New);\n\n<% if (typeof fields != 'undefined') { -%>\n<%\n  for (var i in fields) {\n    var fieldInfo = fields[i];\n    if (fieldInfo.ignore) continue;\n-%>\n    static NAN_METHOD(<%- fieldInfo.cppFunctionName %>);\n<% } -%>\n<% } -%>\n\n<% if (typeof functions != 'undefined') { -%>\n<%\n  for (var i in functions) {\n    var functionInfo = functions[i];\n    if (functionInfo.ignore) continue;\n-%>\n    static NAN_METHOD(<%- functionInfo.cppFunctionName %>);\n\n<% } -%>\n<% } -%>\n<% if (typeof cType != 'undefined') { -%>\n    <%- cType %> *raw;\n<% } -%>\n};\n\n#endif\n", filename: "header.h" };
function rethrow(err, str, filename, lineno){
  var lines = str.split('\n')
    , start = Math.max(lineno - 3, 0)
    , end = Math.min(lines.length, lineno + 3);

  // Error context
  var context = lines.slice(start, end).map(function(line, i){
    var curr = i + start + 1;
    return (curr == lineno ? ' >> ' : '    ')
      + curr
      + '| '
      + line;
  }).join('\n');

  // Alter exception message
  err.path = filename;
  err.message = (filename || 'ejs') + ':'
    + lineno + '\n'
    + context + '\n\n'
    + err.message;

  throw err;
}
try {
var buf = [];
with (locals || {}) { (function(){ 
 buf.push('/**\n * This code is auto-generated; unless you know what you\'re doing, do not modify!\n **/\n\n#ifndef ', (__stack.lineno=5,  cppClassName.toUpperCase() ), '_H\n#define ', (__stack.lineno=6,  cppClassName.toUpperCase() ), '_H\n\n#include <v8.h>\n#include <node.h>\n#include <string>\n\n#include "git2.h"\n\nusing namespace node;\nusing namespace v8;\n\nclass ', (__stack.lineno=17,  cppClassName ), ' : public ObjectWrap {\n  public:\n\n    static Persistent<Function> constructor_template;\n    static void Initialize (Handle<v8::Object> target);\n\n');__stack.lineno=23; if (typeof cType != 'undefined') {; buf.push('    ', (__stack.lineno=23,  cType ), ' *GetValue();\n\n    static Handle<Value> New(void *raw);\n');__stack.lineno=26; }; buf.push('\n  private:\n');__stack.lineno=28; if (typeof cType != 'undefined') {; buf.push('    ', (__stack.lineno=28,  cppClassName ), '(', (__stack.lineno=28,  cType ), ' *raw);\n    ~', (__stack.lineno=29,  cppClassName ), '();\n');__stack.lineno=30; }; buf.push('\n    static NAN_METHOD(New);\n\n');__stack.lineno=33; if (typeof fields != 'undefined') {; buf.push('');__stack.lineno=33;
  for (var i in fields) {
    var fieldInfo = fields[i];
    if (fieldInfo.ignore) continue;; buf.push('    static NAN_METHOD(', (__stack.lineno=36,  fieldInfo.cppFunctionName ), ');\n');__stack.lineno=37; }; buf.push('');__stack.lineno=37; }; buf.push('\n');__stack.lineno=38; if (typeof functions != 'undefined') {; buf.push('');__stack.lineno=38;
  for (var i in functions) {
    var functionInfo = functions[i];
    if (functionInfo.ignore) continue;; buf.push('    static NAN_METHOD(', (__stack.lineno=41,  functionInfo.cppFunctionName ), ');\n\n');__stack.lineno=43; }; buf.push('');__stack.lineno=43; }; buf.push('');__stack.lineno=43; if (typeof cType != 'undefined') {; buf.push('    ', (__stack.lineno=43,  cType ), ' *raw;\n');__stack.lineno=44; }; buf.push('};\n\n#endif\n'); })();
} 
return buf.join('');
} catch (err) {
  rethrow(err, __stack.input, __stack.filename, __stack.lineno);
}
}
