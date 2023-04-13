# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Euro2Dollar_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Euro2Dollar_autogen.dir\\ParseCache.txt"
  "Euro2Dollar_autogen"
  "tests\\CMakeFiles\\Euro2DollarTest_autogen.dir\\AutogenUsed.txt"
  "tests\\CMakeFiles\\Euro2DollarTest_autogen.dir\\ParseCache.txt"
  "tests\\Euro2DollarTest_autogen"
  "tests\\google\\googlemock\\CMakeFiles\\gmock_autogen.dir\\AutogenUsed.txt"
  "tests\\google\\googlemock\\CMakeFiles\\gmock_autogen.dir\\ParseCache.txt"
  "tests\\google\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\AutogenUsed.txt"
  "tests\\google\\googlemock\\CMakeFiles\\gmock_main_autogen.dir\\ParseCache.txt"
  "tests\\google\\googlemock\\gmock_autogen"
  "tests\\google\\googlemock\\gmock_main_autogen"
  "tests\\google\\googletest\\CMakeFiles\\gtest_autogen.dir\\AutogenUsed.txt"
  "tests\\google\\googletest\\CMakeFiles\\gtest_autogen.dir\\ParseCache.txt"
  "tests\\google\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\AutogenUsed.txt"
  "tests\\google\\googletest\\CMakeFiles\\gtest_main_autogen.dir\\ParseCache.txt"
  "tests\\google\\googletest\\gtest_autogen"
  "tests\\google\\googletest\\gtest_main_autogen"
  )
endif()
