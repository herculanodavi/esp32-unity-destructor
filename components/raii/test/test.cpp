#include "raii.hpp"
#include "unity.h"

TEST_CASE("resource leak", "[raii]")
{
  auto raii = GetRAII();
  TEST_FAIL_MESSAGE("leaking resource");
}

TEST_CASE("getting resource", "[raii]")
{
  auto raii = GetRAII();
  TEST_ASSERT_MESSAGE(raii.has_value(), "RAII initialization failed!!");
}