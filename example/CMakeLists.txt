# 查找当前目录下的所有源文件
# 并将名称保存到 DIR_EXAMPLE_SRCS 变量
#aux_source_directory(. DIR_EXAMPLE_SRCS)
#
## 生成链接库
#add_library (lib_example ${DIR_EXAMPLE_SRCS})
add_executable(bench pbench.cpp)
target_link_libraries(bench lib_s1mple)

add_executable(server pserver.cpp)
target_link_libraries(server lib_s1mple)

add_executable(client pclient.cpp)
target_link_libraries(client lib_s1mple)