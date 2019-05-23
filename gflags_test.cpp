#ifndef GFLAGS_DEF_H
#define GFLAGS_DEF_H

#include "gflags_test.h"

// 专门定义gflags的头文件

#include "gflags/gflags.h"

DEFINE_bool(foo, false, "a simple gflags named foo, default value is flase");
DEFINE_int32(thread_num, 10, "thread number, default value is 10");

// 定义gflags
DEFINE_bool(add_new_feature_x, false, "x feature, gaojingying, 2018-08-16");
DEFINE_bool(add_new_featrue_y, false, "y feature, xiechao, 2018-08-16");
DEFINE_bool(fix_memory_leak_bug, false, "fix memory leak bug, xiechao, 2018-08-16");
DEFINE_bool(fix_cpu_high_bug, false, "fix cpu high bug, xiechao, 2018-08-16");
DEFINE_int32(thread_pool_worker_num, 10, "thread pool worker number, default value is 10, ligang, 2018-08-16");
DEFINE_string(server_ip, "127.0.0.1", "x server's ip address, gaojingying, 2018-08-16");


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
//    解析gflags参数，只需要1行代码
//    argc和argv就是 main 的入口参数，因为这个函数会改变他们的值，所以都是以指针传入。
//    第三个参数被称为remove_flags。如果它是true,ParseCommandLineFlags会从argv中移除标识和它们的参数，相应减少argc的值然后 argv 只保留命令行参数。
//    相反，remove_flags是false,ParseCommandLineFlags会保留argc不变，但将会重新调整它们的顺序，使得标识再前面。
//    Note: ./sample --big_menu=false arg1  中big_menu是标识，false是它的参数，arg1是命令行参数。
    google::ParseCommandLineFlags(&argc, &argv, true);

    std::cout << "argc= " << argc << std::endl;
    for(int i = 0; i<argc; ++i)
        std::cout << "argv[" << i << "]:" << argv[i] << std::endl;;

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


#endif // GFLAGS_DEF_H
