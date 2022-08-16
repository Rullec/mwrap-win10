cmake_minimum_required(VERSION 3.10)
project(mwrap_win)
enable_language(CXX)

add_executable(
    mwrap
    src/lex.yy.cc
    src/mwrap-ast.cc 
    src/mwrap-cgen.cc 
    src/mwrap-mgen.cc
    src/mwrap-typecheck.cc
    src/mwrap.cc
)

set_target_properties(mwrap
PROPERTIES
RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}
RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}
)