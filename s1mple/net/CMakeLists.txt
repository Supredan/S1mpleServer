set(NET_SRCS
        Channel.cpp
        EventLoop.cpp
        Server.cpp
        EventLoopThreadPool.cpp
        EventLoopThread.cpp
        Epoll.cpp
        Timer.cpp
        HttpData.cpp
#        http_parser.c
#        SudokuServer.cpp
        )

add_library(lib_s1mple ${NET_SRCS} ${BASE_SRCS})
target_link_libraries(lib_s1mple lib_base)


install(TARGETS lib_s1mple DESTINATION lib)


set(HEADERS
        ../base/util.h
        ../base/CurrentThread.h
        EventLoop.h
        Channel.h
        TimerQueue.h
        Server.h
        EventLoopThreadPool.h
        EventLoopThread.h
        Epoll.h
        Timer.h
        HttpData.h
        )
install(FILES ${HEADERS} DESTINATION include/s1mple)