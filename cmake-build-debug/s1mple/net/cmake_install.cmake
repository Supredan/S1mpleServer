# Install script for directory: /home/supdan/code/web/S1mpleServer/s1mple/net

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/supdan/code/web/S1mpleServer/cmake-build-debug/s1mple/net/liblib_s1mple.a")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/s1mple" TYPE FILE FILES
    "/home/supdan/code/web/S1mpleServer/s1mple/net/../base/util.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/../base/CurrentThread.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/EventLoop.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/Channel.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/TimerQueue.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/Server.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/EventLoopThreadPool.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/EventLoopThread.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/Epoll.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/Timer.h"
    "/home/supdan/code/web/S1mpleServer/s1mple/net/HttpData.h"
    )
endif()

