//
// Created by dan on 2020/2/17.
//

#include "Channel.h"
#include "EventLoop.h"

#include <sstream>

#include <poll.h>

using namespace simple;

const int Channel::kNoneEvent = 0;
const int Channel::kReadEvent = POLLIN | POLLPRI;
const int Channel::kWriteEvent = POLLOUT;

Channel::Channel(simple::EventLoop *loop, int fd)
    :loop_(loop),
    fd_(fd),
    events_(0),
    revents_(0),
    index_(-1)
{
}

void Channel::update() {
    loop_->updateChannel(this);
}

void Channel::handleEvent(){
    if(revents_ & POLLNVAL){
        //log
    }
    if(revents_ & (POLLERR | POLLNVAL)){
        if(errorCallback_) errorCallback_();
    }
    if(revents_ & (POLLIN | POLLPRI | POLLRDHUP)){
        if(readCallback_) readCallback_();
    }
    if(revents_ & POLLOUT){
        if(writeCallback_) writeCallback_();
    }
}


//void Channel::handleEvent(Timestamp receiveTime)
//{
//    std::shared_ptr<void> guard;
//    if (tied_)
//    {
//        guard = tie_.lock();
//        if (guard)
//        {
//            handleEventWithGuard(receiveTime);
//        }
//    }
//    else
//    {
//        handleEventWithGuard(receiveTime);
//    }
//}

//void Channel::handleEventWithGuard(Timestamp receiveTime)
//{
//    eventHandling_ = true;
//    LOG_TRACE << reventsToString();
//    if ((revents_ & POLLHUP) && !(revents_ & POLLIN))
//    {
//        if (logHup_)
//        {
//            LOG_WARN << "fd = " << fd_ << " Channel::handle_event() POLLHUP";
//        }
//        if (closeCallback_) closeCallback_();
//    }
//
//    if (revents_ & POLLNVAL)
//    {
//        LOG_WARN << "fd = " << fd_ << " Channel::handle_event() POLLNVAL";
//    }
//
//    if (revents_ & (POLLERR | POLLNVAL))
//    {
//        if (errorCallback_) errorCallback_();
//    }
//    if (revents_ & (POLLIN | POLLPRI | POLLRDHUP))
//    {
//        if (readCallback_) readCallback_(receiveTime);
//    }
//    if (revents_ & POLLOUT)
//    {
//        if (writeCallback_) writeCallback_();
//    }
//    eventHandling_ = false;
//}