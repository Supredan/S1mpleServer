//
// Created by dan on 2020/2/17.
//

#ifndef S1MPLESERVER_EVENTLOOP_H
#define S1MPLESERVER_EVENTLOOP_H
#include <atomic>
#include <functional>
#include <vector>
#include <memory>

#include "util.h"
#include "CurrentThread.h"
#include "Timestamp.h"

namespace simple{

    class Channel;
    class Poller;
    class TimerQueue;

    class EventLoop : noncopyable{
    public:
        EventLoop();
        ~EventLoop();

        ///
        /// Loops forever.
        ///
        /// Must be called in the same thread as creation of the object.
        ///
        void loop();

        /// Quits loop.
        ///
        /// This is not 100% thread safe, if you call through a raw pointer,
        /// better to call through shared_ptr<EventLoop> for 100% safety.
        void quit();

        // pid_t threadId() const { return threadId_; }
        void assertInLoopThread()
        {
            if (!isInLoopThread())
            {
                abortNotInLoopThread();
            }
        }
        //若将成员成员函数声明为const，则该函数不允许修改类的数据成员。
        bool isInLoopThread() const { return threadId_ == CurrentThread::tid();}

        static EventLoop* getEventLoopOfCurrentThread();

        // internal usage
        void updateChannel(Channel* channel);
    private:
        void abortNotInLoopThread();

        typedef std::vector<Channel*> ChannelList;

        bool looping_;
        std::atomic<bool> quit_;
        const pid_t threadId_;

        std::unique_ptr<Poller> poller_;
        ChannelList activeChannels_;
    };
}
#endif //S1MPLESERVER_EVENTLOOP_H
