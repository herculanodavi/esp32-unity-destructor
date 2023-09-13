#include "unity.h"

extern "C"
{
#include "unity_fixture.h"
}

// Execute the tests
void execute(void)
{
  unity_run_test_by_name("resource leak");
  unity_run_test_by_name("getting resource");
}

extern "C" void app_main()
{
  UNITY_MAIN_FUNC(execute);
}