# CMake generated Testfile for 
# Source directory: C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice
# Build directory: C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(my_test "C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/build/Debug/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/CMakeLists.txt;56;add_test;C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(my_test "C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/build/Release/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/CMakeLists.txt;56;add_test;C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(my_test "C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/build/MinSizeRel/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/CMakeLists.txt;56;add_test;C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(my_test "C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/build/RelWithDebInfo/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/CMakeLists.txt;56;add_test;C:/Users/Sheng Lu/Documents/School/Undergraduate/Junior Year/Spring Sem/ECE 3574/Dice/CMakeLists.txt;0;")
else()
  add_test(my_test NOT_AVAILABLE)
endif()
