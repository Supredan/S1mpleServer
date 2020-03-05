# 简介

本项目是一个C++11编写的多线程服务器，是学习了[muduo](https://github.com/chenshuo/muduo "muduo")、[WebServer（牛客网的天线宝宝大佬）](https://github.com/linyacool/WebServer "WebServer（牛客网的天线宝宝大佬）")、[Handy](https://github.com/yedf/handy "Handy")后的练手项目，感谢各位大佬的无私奉献。
本项目针对muduo进行了代码的简化，并运行了一个数独求解在上面，保留了muduo库的优良特性。

项目特性：

- C++11编写的Web服务器库，利用非阻塞IO和IO复用技术，实现了one loop per thread + thread pool模型的并发连接
- 使用timerfd处理定时事件，存储的数据结构采用时间堆
- 使用eventfd进行线程唤醒，能够跨线程的调用回调函数
- 使用双缓冲技术实现异步日志系统
- 实现了长连接和管线化

详情请看我的博客文章：[点我](https://blog.csdn.net/weixin_42687826/article/details/104398845)  
测试页面：[数独求解](http://114.116.250.194:8888/)  
PS：项目名称来源于我喜爱的CSGO职业选手S1mple，苏卡布列！  
# 安装与运行
```bash
mkdir build
cd build
cmake ..
make -j4 && make install
./S1mpleServer
```
# 使用方式  
  `fixme`  
# 系统设计
本项目主要有以下几个类：
对外可见的：
- EventLoop：事件循环，也即大家熟知的Reactor，负责事件的分发，每个拥有一个Epoll和至少一个Channel。
- Server：主服务器类，封装一个服务器的各种参数。

内部实现：
- Channel：负责响应和接收IO事件，可以想象为socket的包装，它含有socket的回调函数，在各个类间传递数据。
- Epoll：epoll的包装类
- EventLoopThreadPoll：线程池的最上层封装
- Logging：日志的最上层封装类
- Timer：时间类
- HttpData：http数据处理类



```cpp
    EventLoop mainLoop;
    Server SudokuServer(&mainLoop, threadNum, port);
    SudokuServer.start();
    mainLoop.loop();
```
4句话就能运行这个服务器，下图是此时服务器的状态。
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200219203428804.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MjY4NzgyNg==,size_16,color_FFFFFF,t_70)
首先创建了一个mainloop的实例，正如其名它是主循环，默认有一个channel类包含一个wakeupfd，一个Epoll类用来注册epoll事件。
然后创建了一个SudokuServer的实例，它和主循环相对应，同时默认有一个acceptchannel负责listenfd的新建连接，还有一个线程池负责分发事件。
之后运行start函数让各个模块初始化，最后运行主循环。

当一个新连接到来，状态如下图所示：![在这里插入图片描述](https://img-blog.csdnimg.cn/20200219211919478.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MjY4NzgyNg==,size_16,color_FFFFFF,t_70)

subloop是工作线程的循环，httpdata充当了各个类的数据处理中心，connfd如果你熟悉UNP的各个例子，就会知道它是新连接的socket，数据从connfd送往httpdata类解析，回调函数通过channel最终再调用httpdata中的readhandle处理。

这里要注意subloop同样拥有一个epoll，connfd是注册到它的上面。
# 测试结果
使用webbench进行的本地测试，下图是在开启4线程，1000个连接，使用keep-Alive方式的结果，全部请求都成功，吞吐量在38MB/s。  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200220233531717.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80MjY4NzgyNg==,size_16,color_FFFFFF,t_70)
# TODO

