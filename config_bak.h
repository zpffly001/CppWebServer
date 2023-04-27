#ifndef CONFIG_BAK_H
#define CONFIG_BAK_H

#include "webserver.h"

using namespace std;

class Config_bak
{

public:
    Config_bak();
    ~Config_bak();

    void parse_arg(int argc, char *argv[]);
    
    // 端口号
    int PORT;

    // 写入日志方式
    int LOGWrite;

    // 触发组合模式
    int TRIGMode;

    // listenfd触发模式
    int LISTENTrigmode;

    // connfd触发模式
    int CONNTrigmode;

    // 优雅关闭链接
    int OPT_LINGER;

    // 数据库连接池数量
    int sql_num;

    // 线程池内的线程数量
    int thread_num;

    // 是否关闭日志
    int close_log;

    // 并发模型选择
    int actor_model;
};

#endif