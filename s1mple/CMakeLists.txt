set(s1mple_SRCS
        Channel.cpp
        CurrentThread.cpp
        EventLoop.cpp
        Poller.cpp
        Timestamp.cc
        )

add_library(lib_s1mple ${s1mple_SRCS})
target_link_libraries(lib_s1mple pthread rt)


install(TARGETS lib_s1mple DESTINATION lib)


set(HEADERS
        Channel.h
        CurrentThread.h
        EventLoop.h
        Poller.h
        Timestamp.h
        util.h
        )
install(FILES ${HEADERS} DESTINATION include/s1mple)