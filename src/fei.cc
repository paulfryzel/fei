#include <GLFW/glfw3.h>
#include <node.h>
#include <v8.h>

namespace fei {

  using v8::Arguments;
  using v8::Boolean;
  using v8::Handle;
  using v8::HandleScope;
  using v8::Integer;
  using v8::Local;
  using v8::Object;
  using v8::String;
  using v8::Undefined;
  using v8::Value;

  namespace glfw {

    Handle<Value> Init(const Arguments& args) {
      HandleScope scope;
      return scope.Close(Boolean::New(glfwInit() == true));
    }

    Handle<Value> Terminate(const Arguments& args) {
      HandleScope scope;
      glfwTerminate();
      return scope.Close(Undefined());
    }

    Handle<Value> GetVersion(const Arguments& args) {
      HandleScope scope;
      int major, minor, rev;
      glfwGetVersion(&major, &minor, &rev);
      Local<Object> version = Object::New();
      version->Set(String::New("major"), Integer::New(major));
      version->Set(String::New("minor"), Integer::New(minor));
      version->Set(String::New("rev"), Integer::New(rev));
      return scope.Close(version);
    }

    Handle<Value> GetVersionString(const Arguments& args) {
      HandleScope scope;
      return scope.Close(String::New(glfwGetVersionString()));
    }

    void Initialize(Handle<Object> target) {
      NODE_SET_METHOD(target, "init", Init);
      NODE_SET_METHOD(target, "terminate", Terminate);
      NODE_SET_METHOD(target, "getVersion", GetVersion);
      NODE_SET_METHOD(target, "getVersionString", GetVersionString);
      NODE_DEFINE_CONSTANT(target, GLFW_VERSION_MAJOR);
      NODE_DEFINE_CONSTANT(target, GLFW_VERSION_MINOR);
      NODE_DEFINE_CONSTANT(target, GLFW_VERSION_REVISION);
    }

  } // namespace glfw

} // namespace fei

NODE_MODULE(fei, fei::glfw::Initialize);