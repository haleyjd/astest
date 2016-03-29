##-----------------------------------------------------------------------------
##
##
##
##-----------------------------------------------------------------------------

cmake_minimum_required(VERSION 2.6)

project(astest)

include(CheckCXXCompilerFlag)


##----------------------------------------------------------------------------|
## Functions                                                                  |
##

##
## TRY_CXX_FLAG
##
function(TRY_CXX_FLAG flag name)
   CHECK_CXX_COMPILER_FLAG(${flag} FLAG_CXX_${name})

   if(FLAG_CXX_${name})
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
   endif()
endfunction()


##----------------------------------------------------------------------------|
## Environment Detection                                                      |
##

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
   TRY_CXX_FLAG(-Wall      Wall   )
   TRY_CXX_FLAG(-Wextra    Wextra )
   TRY_CXX_FLAG(-Wpedantic Wpedantic)
   TRY_CXX_FLAG(-Wshadow   Wshadow)

   TRY_CXX_FLAG(-std=c++11 CXX11)
endif()


##----------------------------------------------------------------------------|
## Environment Configuration                                                  |
##

include_directories(angelscript/include)


##----------------------------------------------------------------------------|
## Targets                                                                    |
##

add_subdirectory(angelscript/projects/cmake)

add_executable(astest
   main.cpp

   misc.cpp
   qstring.cpp
   zone.cpp

   hal/platform.cpp

   posix/posix_platform.cpp
)

target_link_libraries(astest angelscript)

## EOF

