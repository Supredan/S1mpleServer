set(BASE_SRC
        AsyncLogging.cpp
        CountDownLatch.cpp
        FileUtil.cpp
        LogFile.cpp
        Logging.cpp
        LogStream.cpp
        Thread.cpp
        Util.cpp
        )

add_library(lib_base ${BASE_SRC})
target_link_libraries(lib_base pthread rt)

file(GLOB HEADERS "*.h")
install(FILES ${HEADERS} DESTINATION include/s1mple/base)

set_target_properties(lib_base PROPERTIES OUTPUT_NAME "lib_base")