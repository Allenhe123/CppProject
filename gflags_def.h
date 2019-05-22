#ifndef GFLAGS_DEF_H
#define GFLAGS_DEF_H

// 专门定义gflags的头文件

#include "gflags/gflags.h"

// 定义gflags
DEFINE_bool(add_new_feature_x, false, "x feature, gaojingying, 2018-08-16");
DEFINE_bool(add_new_featrue_y, false, "y feature, xiechao, 2018-08-16");
DEFINE_bool(fix_memory_leak_bug, false, "fix memory leak bug, xiechao, 2018-08-16");
DEFINE_bool(fix_cpu_high_bug, false, "fix cpu high bug, xiechao, 2018-08-16");
DEFINE_int32(thread_pool_worker_num, 10, "thread pool worker number, default value is 10, ligang, 2018-08-16");
DEFINE_string(server_ip, "127.0.0.1", "x server's ip address, gaojingying, 2018-08-16");

#endif // GFLAGS_DEF_H
