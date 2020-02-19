//
// Created by supdan on 20-2-18.
//

#ifndef S1MPLESERVER_SODUSERVER_H
#define S1MPLESERVER_SODUSERVER_H

#include <sys/epoll.h>
#include <unistd.h>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>

#include "Timer.h"
#include "http_parser.h"

namespace simple{

    class EventLoop;

    class TimerNode;

    class Channel;

    class SudokuServer : noncopyable{
    public:
        SudokuServer(EventLoop *loop, int connfd);

        ~SudokuServer() { close(fd_); }


    private:
        EventLoop *loop_;
        std::shared_ptr<Channel> channel_;
        int fd_;
        std::string inBuffer_;
        std::string outBuffer_;
        bool error_;
        ConnectionState connectionState_;

        HttpMethod method_;
        HttpVersion HTTPVersion_;
        std::string fileName_;
        std::string path_;
        int nowReadPos_;
        ProcessState state_;
        ParseState hState_;
        bool keepAlive_;
        std::map<std::string, std::string> headers_;
        std::weak_ptr<TimerNode> timer_;

        void handleRead();

        void handleWrite();

        void handleConn();

        void handleError(int fd, int err_num, std::string short_msg);

    };
}
#endif //S1MPLESERVER_SODUSERVER_H
