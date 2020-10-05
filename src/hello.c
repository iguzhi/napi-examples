#include <node_api.h>
#include <assert.h>

napi_value greeting(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value word;
  char *str = "Hello N-API!";

  status = napi_create_string_utf8(env, str, strlen(str), &word);

  assert(status == napi_ok);

  return word;
}

napi_value init(napi_env env, napi_value exports) {
  napi_status status;
  napi_property_descriptor descriptor = {
    "greeting",
    0,
    greeting,
    0,
    0,
    0,
    napi_default,
    0,
  };

  status = napi_define_properties(env, exports, 1, &descriptor);
  assert(status == napi_ok);

  return exports;
}

NAPI_MODULE(hello, init);