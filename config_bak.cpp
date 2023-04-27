#include "config_bak.h"

Config_bak::Config_bak()
{
    // 端口号,默认8086
    PORT = 8086;

    // 日志写入方式，默认同步
    LOGWrite = 0;

    // listenfd触发模式，默认LT
    LISTENTrigmode = 0;

    // connfd触发模式，默认LT
    CONNTrigmode = 0;

   // 优雅关闭链接，默认不使用
    OPT_LINGER = 0;

    // 数据库连接池数量,默认8
    sql_num = 8;

    // 线程池内的线程数量,默认8
    thread_num = 8;

    // 关闭日志,默认不关闭
    close_log = 0;

    // 并发模型,默认是proactor
    actor_model = 0;
}

/**
 * @brief 解析命令行参数
 * 
 * @param argc 包含程序执行时的参数数量
 * @param argv 包含程序执行时的参数列表
 */
void Config_bak::parse_arg(int argc, char *argv[])
{
    int opt;
    const char *str = "p:l:m:o:s:t:c:a:";
    // getopt() 是一个 C 函数，它用于处理命令行参数。它可以帮助程序员更容易地处理命令行参数，并从中提取有用的信息。
    // 使用 "p:l:" 作为 getopt() 函数的第三个参数。这表示我们期望命令行选项 -p 和 -l 后面都有一个参数。
    // 在 while 循环中，我们调用 getopt() 函数，直到返回 -1，即命令行选项解析完毕。
    while ((opt = getopt(argc, argv, str)))
    {
        switch (opt)
        {
        case 'p':
            PORT = atoi(optarg);
            break;
        case 'l':
            LOGWrite = atoi(optarg);
            break;
        case 'm':
            TRIGMode = atoi(optarg);
            break;
        case 'o':
            OPT_LINGER = atoi(optarg);
            break;
        case 's':
            sql_num = atoi(optarg);
            break;
        case 't':
            thread_num = atoi(optarg);
            break;
        case 'c':
            close_log = atoi(optarg);
            break;
        case 'a':
            actor_model = atoi(optarg);
            break;
        default:
            break;
        }
    }
    
}