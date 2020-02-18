//
// Created by supdan on 20-2-17.
//
// 测试poll版的框架
// 使用timerfd做事件，5s后调用回调函数，退出循环并打印Timeout
#include <sys/timerfd.h>
#include <net/Channel.h>
#include "net/EventLoop.h"

using namespace simple;
using namespace std;

EventLoop* g_loop;

void timeout(){
    printf("Timeout!\n");
    g_loop->quit();
}

int main() {
    EventLoop loop;
    g_loop = &loop;

//    第一个参数：clockid指定时间类型，有两个值：
//
//    CLOCK_REALTIME :Systemwide realtime clock. 系统范围内的实时时钟
//
//    CLOCK_MONOTONIC:以固定的速率运行，从不进行调整和复位 ,它不受任何系统time-of-day时钟修改的影响
//
//    第二个参数：flags可以是0或者O_CLOEXEC/O_NONBLOCK。
//
//    返回值：timerfd（文件描述符）
    int timerfd = ::timerfd_create(CLOCK_MONOTONIC, TFD_NONBLOCK | TFD_CLOEXEC);
    Channel channel(&loop, timerfd);
    channel.setReadCallback(timeout);
    channel.enableReading();

    struct itimerspec howlong;
    bzero(&howlong, sizeof(howlong));
    howlong.it_value.tv_sec = 5;
    ::timerfd_settime(timerfd, 0, &howlong, NULL);

    loop.loop();

    ::close(timerfd);
    return 0;
}