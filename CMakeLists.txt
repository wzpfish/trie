project(trie)

include_directories(./)
include_directories(/home/v-zhipew/thirdparty/googletest/googletest/include)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -lpthread")

# test source files 
set (TEST_SOURCE_FILES
     "${CMAKE_SOURCE_DIR}/trie_test.cc"
     )

# test case
add_executable (trietest
    ${TEST_SOURCE_FILES})

# link thirdparty libs
set (THIRDPARTY_DIR /home/v-zhipew/thirdparty/googletest/googletest/cmake)
target_link_libraries (trietest
    "/home/v-zhipew/thirdparty/googletest/googletest/cmake/libgtest.a"
    "/home/v-zhipew/thirdparty/googletest/googletest/cmake/libgtest_main.a")


