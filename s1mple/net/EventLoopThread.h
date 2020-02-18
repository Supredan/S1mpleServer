//
// Created by supdan on 20-2-18.
//
#pragma once
#ifndef S1MPLESERVER_EVENTLOOPTHREAD_H
#define S1MPLESERVER_EVENTLOOPTHREAD_H

#include "EventLoop.h"
#include "base/Condition.h"
#include "base/MutexLock.h"
#include "base/Thread.h"
#include "base/noncopyable.h"

namespace simple {


    class EventLoopThread : noncopyable {
    public:
        EventLoopThread();

        ~EventLoopThread();

        EventLoop *startLoop();

    private:
        void threadFunc();

        EventLoop *loop_;
        bool exiting_;
        Thread thread_;
        MutexLock mutex_;
        Condition cond_;
    };

}
#endif //S1MPLESERVER_EVENTLOOPTHREAD_H
