#ifndef GFLAGS_GLOG_H
#define GFLAGS_GLOG_H

#include <iostream>
#include "gflags/gflags.h"
#include "glog/logging.h"
#include "gflags_def.h"

DEFINE_bool(foo, false, "a simple gflags named foo, default value is flase");
DEFINE_int32(thread_num, 10, "thread number, default value is 10");

//其他文件中使用gflags之前，需要先通过DECLARE_声明。
DECLARE_bool(add_new_feature_x);
DECLARE_bool(add_new_featrue_y);
DECLARE_bool(fix_memory_leak_bug);
DECLARE_bool(fix_cpu_high_bug);
DECLARE_int32(thread_pool_worker_num);
DECLARE_string(server_ip);


void Work(std::string &name) {
  name = "feature";
  // 启用x功能
  if (FLAGS_add_new_feature_x) {
    name += "_x";
  }

  // 启用y功能
  if (FLAGS_add_new_featrue_y) {
    name += "_y";
  }

  char *value = new char[100];
  snprintf(value, 100, "thread number: %d", FLAGS_thread_pool_worker_num);
  name = name + "," + value + "," + FLAGS_server_ip;

  // 留下消缺记录
  if (FLAGS_fix_memory_leak_bug) {
    delete []value;
  }
}


void gflags_test(int argc, char* argv[]) {
     // 解析gflags参数，只需要1行代码
    google::ParseCommandLineFlags(&argc, &argv, true);
//    google::InitGoogleLogging(argv[0]);
//    google::SetLogDestination(google::GLOG_INFO, "./log_");

    // demo1
    // 使用gflags
    if (FLAGS_foo) {
        std::cout << "foo is true" << std::endl;
    } else {
        std::cout << "foo is false" << std::endl;
    }

     // 使用gflags
    int thread_num = FLAGS_thread_num;
    std::cout << "thread number:" << thread_num << std::endl;

    // demo2
    std::string name;
    Work(name);
    std::cout << name << std::endl;
}


/*
没有参数: ./a.out
foo is false
thread number:10

指定foo和thread_num，./a.out -foo=true -thread_num=99
foo is true
thread number:99

在工程实践中，有专门定义gflags的文件，通过--flagfile=filename来指定gflags配置文件，
其他文件在使用gflags时需要先声明；通常将gflags定义在专门的配置文件中，以方便对程序运行参数管理。
*/

#endif // GFLAGS_GLOG_H
