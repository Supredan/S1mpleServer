//
// Created by dan on 2020/2/17.
//

#ifndef S1MPLESERVER_POLLER_H
#define S1MPLESERVER_POLLER_H
#include <map>
#include <vector>

#include "EventLoop.h"
#include "Timestamp.h"
#include <poll.h>

namespace simple{
    class Channel;

    ///
/// Base class for IO Multiplexing
///
/// This class doesn't own the Channel objects.
    class Poller : noncopyable
    {
    public:
        typedef std::vector<Channel*> ChannelList;

        Poller(EventLoop* loop);
        ~Poller();

        /// Polls the I/O events.
        /// Must be called in the loop thread.
        Timestamp poll(int timeoutMs, ChannelList* activeChannels);

        /// Changes the interested I/O events.
        /// Must be called in the loop thread.
        void updateChannel(Channel* channel);

        void assertInLoopThread() const
        {
            ownerLoop_->assertInLoopThread();
        }

    private:
        void fillActiveChannels(int numEvents,
                                ChannelList* activeChannels) const ;

        typedef std::map<int, Channel*> ChannelMap;
        typedef std::vector<struct pollfd> PollFdList;

        ChannelMap channels_;
        EventLoop* ownerLoop_;
        PollFdList pollfds_;

    };
}
#endif //S1MPLESERVER_POLLER_H
