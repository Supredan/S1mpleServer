//
// Created by supdan on 20-2-18.
//
#pragma once
#ifndef S1MPLESERVER_EVENTLOOPTHREADPOOL_H
#define S1MPLESERVER_EVENTLOOPTHREADPOOL_H

#include <memory>
#include <vector>
#include "EventLoopThread.h"
#include "base/Logging.h"
#include "base/noncopyable.h"
namespace simple {


    class EventLoopThreadPool : noncopyable {
    public:
        EventLoopThreadPool(EventLoop *baseLoop, int numThreads);

        ~EventLoopThreadPool() { LOG << "~EventLoopThreadPool()"; }

        void start();

        EventLoop *getNextLoop();

    private:
        EventLoop *baseLoop_;
        bool started_;
        int numThreads_;
        int next_;
        std::vector<std::shared_ptr<EventLoopThread>> threads_;
        std::vector<EventLoop *> loops_;
    };

}
#endif //S1MPLESERVER_EVENTLOOPTHREADPOOL_H
