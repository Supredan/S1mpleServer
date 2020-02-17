//
// Created by dan on 2020/2/17.
//

#include "EventLoop.h"

namespace simple{
    const int kPollTimeMs = 10000;
    __thread EventLoop* t_loopInThisThread = 0;

    EventLoop::EventLoop()
            : looping_(false), threadId_(CurrentThread::tid())
    {
        //log
        if(t_loopInThisThread)
        {
            //log
        }
        else
        {
            t_loopInThisThread = this;
        }
    }

    EventLoop::~EventLoop() {
        assert(!looping_);//其作用是如果它的条件返回错误，则终止程序执行
        t_loopInThisThread = NULL;
    }

    EventLoop* EventLoop::getEventLoopOfCurrentThread() {
        return t_loopInThisThread;
    }

    void EventLoop::loop() {
        assert(!looping_);
        assertInLoopThread();
        looping_ = true;
        quit_ = false;

        while (!quit_){
            activeChannels_.clear();
            poller_->poll(kPollTimeMs, &activeChannels_);
            for (ChannelList::const_iterator it = activeChannels_.begin();
                 it != activeChannels_.end(); ++it)
            {
                (*it)->handleEvent();
            }
        }

        //log
        looping_ = false;
    }

    void EventLoop::quit()
    {
        quit_ = true;
        // There is a chance that loop() just executes while(!quit_) and exits,
        // then EventLoop destructs, then we are accessing an invalid object.
        // Can be fixed using mutex_ in both places.
//    if (!isInLoopThread())
//    {
//        wakeup();
//    }
    }

    void EventLoop::abortNotInLoopThread()
    {
//        LOG_FATAL << "EventLoop::abortNotInLoopThread - EventLoop " << this
//                  << " was created in threadId_ = " << threadId_
//                  << ", current thread id = " <<  CurrentThread::tid();
    }
}

