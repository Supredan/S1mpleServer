# Install script for directory: /home/supdan/code/web/S1mpleServer/s1mple/base

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/s1mple/base" TYPE FILE FILES
    "/home/supdan/code/web/S1mpleServer/s1mple/base/AsyncLogging.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/Condition.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/CountDownLatch.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/CurrentThread.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/FileUtil.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/LogFile.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/LogStream.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/Logging.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/MutexLock.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/Thread.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/Util.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/noncopyable.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/sudoku.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/base/util.h"
    )
endif()

