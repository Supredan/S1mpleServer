//
// Created by dan on 2020/2/17.
//

#ifndef S1MPLESERVER_CHANNEL_H
#define S1MPLESERVER_CHANNEL_H
#include <functional>
#include <memory>

#include "util.h"

namespace simple{
    class EventLoop;
    ///
/// A selectable I/O channel.
///
/// This class doesn't own the file descriptor.
/// The file descriptor could be a socket,
/// an eventfd, a timerfd, or a signalfd
    class Channel : noncopyable
    {
    public:
        typedef std::function<void()> EventCallback;
//        typedef std::function<void(Timestamp)> ReadEventCallback;

        Channel(EventLoop* loop, int fd);
        ~Channel();

        void handleEvent();
        void setReadCallback(EventCallback cb)
        { readCallback_ = std::move(cb); }
        void setWriteCallback(EventCallback cb)
        { writeCallback_ = std::move(cb); }
        void setCloseCallback(EventCallback cb)
        { closeCallback_ = std::move(cb); }
        void setErrorCallback(EventCallback cb)
        { errorCallback_ = std::move(cb); }

        int fd() const { return fd_; }
        int events() const { return events_;}
        void set_revents(int revt) { revents_ = revt; } // used by pollers
        bool isNoneEvent() const { return events_ == kNoneEvent; }

        void enableReading() { events_ |= kReadEvent; update(); }
//        void disableReading() { events_ &= ~kReadEvent; update(); }
//        void enableWriting() { events_ |= kWriteEvent; update(); }
//        void disableWriting() { events_ &= ~kWriteEvent; update(); }
//        void disableAll() { events_ = kNoneEvent; update(); }
//        bool isWriting() const { return events_ & kWriteEvent; }
//        bool isReading() const { return events_ & kReadEvent; }

        // for Poller
        int index() { return index_; }
        void set_index(int idx) { index_ = idx; }

        EventLoop* ownerLoop() { return loop_; }

    private:
        void update();

        static const int kNoneEvent;
        static const int kReadEvent;
        static const int kWriteEvent;

        EventLoop* loop_;
        const int  fd_;
        int        events_;
        int        revents_; // it's the received event types of epoll or poll
        int        index_; // used by Poller.

        EventCallback readCallback_;
        EventCallback writeCallback_;
        EventCallback closeCallback_;
        EventCallback errorCallback_;
    };
}
#endif //S1MPLESERVER_CHANNEL_H
