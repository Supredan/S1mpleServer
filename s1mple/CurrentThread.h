//
// Created by dan on 2020/2/17.
//

#ifndef S1MPLESERVER_CURRENTTHREAD_H
#define S1MPLESERVER_CURRENTTHREAD_H

#include "util.h"

namespace simple{
    namespace CurrentThread {
        // internal
        // 由gcc提供的关键字：
        // __thread:线程局部存储(tls)是一种机制,通过这一机制分配的变量,每个当前线程有一个该变量的实例.
        extern __thread int t_cachedTid;
        extern __thread char t_tidString[32];
        extern __thread int t_tidStringLength;
        extern __thread const char *t_threadName;

        void cacheTid();

        inline int tid() {
            if (__builtin_expect(t_cachedTid == 0, 0)) {
                cacheTid();
            }
            return t_cachedTid;
        }

        bool isMainThread();

    }
}
#endif //S1MPLESERVER_CURRENTTHREAD_H
