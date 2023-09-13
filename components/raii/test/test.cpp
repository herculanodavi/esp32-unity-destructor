#include "raii.hpp"
#include "unity.h"

TEST_CASE("resource leak", "[raii]")
{
  auto raii = GetRAII();
  TEST_FAIL_MESSAGE("leaking resource");
  /* constructor is not called here */
}

TEST_CASE("getting resource", "[raii]")
{
  auto raii = GetRAII();
  /* constructor was not called above so resource is unavailable */
  TEST_ASSERT_MESSAGE(raii.has_value(), "RAII initialization failed!!");
}