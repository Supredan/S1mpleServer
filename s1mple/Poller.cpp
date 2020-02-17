//
// Created by dan on 2020/2/17.
//

#include "Poller.h"
#include "Channel.h"
#include "util.h"

#include <assert.h>
#include <errno.h>

using namespace simple;

Poller::Poller(EventLoop* loop)
        : ownerLoop_(loop)
{
}

Poller::~Poller() = default;

Timestamp Poller::poll(int timeoutMs, simple::Poller::ChannelList *activeChannels) {
    int numEvents = ::poll(&*pollfds_.begin(), pollfds_.size(), timeoutMs);
    Timestamp now(Timestamp::now());
    if(numEvents > 0){
        //log
        fillActiveChannels(numEvents, activeChannels);
    } else if (numEvents == 0){
        //log
    } else{
        //log
    }
    return now;
}

void Poller::fillActiveChannels(int numEvents, simple::Poller::ChannelList *activeChannels) const {
    for (PollFdList::const_iterator pfd = pollfds_.begin();
            pfd != pollfds_.end() && numEvents > 0; ++pfd) {
        if (pfd->revents > 0){
            --numEvents;
            ChannelMap::const_iterator ch = channels_.find(pfd->fd);
            assert(ch != channels_.end());
            Channel* channel = ch->second;
            assert(channel->fd() == pfd->fd);
            channel->set_revents(pfd->revents);
            activeChannels->push_back(channel);
        }
    }
}

void Poller::updateChannel(Channel* channel)
{
    Poller::assertInLoopThread();
//   LOG_TRACE << "fd = " << channel->fd() << " events = " << channel->events();
    if (channel->index() < 0)
    {
        // a new one, add to pollfds_
        assert(channels_.find(channel->fd()) == channels_.end());
        struct pollfd pfd;
        pfd.fd = channel->fd();
        pfd.events = static_cast<short>(channel->events());
        pfd.revents = 0;
        pollfds_.push_back(pfd);
        int idx = static_cast<int>(pollfds_.size())-1;
        channel->set_index(idx);
        channels_[pfd.fd] = channel;
    }
    else
    {
        // update existing one
        assert(channels_.find(channel->fd()) != channels_.end());
        assert(channels_[channel->fd()] == channel);
        int idx = channel->index();
        assert(0 <= idx && idx < static_cast<int>(pollfds_.size()));
        struct pollfd& pfd = pollfds_[idx];
        assert(pfd.fd == channel->fd() || pfd.fd == -channel->fd()-1);
        pfd.fd = channel->fd();
        pfd.events = static_cast<short>(channel->events());
        pfd.revents = 0;
        if (channel->isNoneEvent())
        {
            // ignore this pollfd
            pfd.fd = -channel->fd()-1;
        }
    }
}
