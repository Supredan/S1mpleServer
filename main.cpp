#include <getopt.h>
#include <string>
#include "net/EventLoop.h"
#include "net/Server.h"
#include "base/Logging.h"

using namespace simple;
using namespace std;

int main(int argc, char *argv[]) {
    int threadNum = 4;
    int port = 8888;
    std::string logPath = "./WebServer.log";
    Logger::setLogFileName(logPath);
#ifndef _PTHREADS
    LOG << "_PTHREADS is not defined !";
#endif
    EventLoop mainLoop;
    Server S1mpleserver(&mainLoop, threadNum, port);
    S1mpleserver.start();
    mainLoop.loop();
    return 0;
}
