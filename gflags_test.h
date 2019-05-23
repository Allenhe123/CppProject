#ifndef GFLAGS_GLOG_H
#define GFLAGS_GLOG_H

#include <iostream>
#include "gflags/gflags.h"

//其他文件中使用gflags之前，需要先通过DECLARE_声明。
DECLARE_bool(foo);
DECLARE_int32(thread_num);

DECLARE_bool(add_new_feature_x);
DECLARE_bool(add_new_featrue_y);
DECLARE_bool(fix_memory_leak_bug);
DECLARE_bool(fix_cpu_high_bug);
DECLARE_int32(thread_pool_worker_num);
DECLARE_string(server_ip);


void Work(std::string &name);
void gflags_test(int argc, char* argv[]);

/*
没有参数: ./a.out
foo is false
thread number:10

指定foo和thread_num，./a.out -foo=true -thread_num=99          -和--都可以
foo is true
thread number:99

在工程实践中，有专门定义gflags的文件，通过--flagfile=filename来指定gflags配置文件，
其他文件在使用gflags时需要先声明；通常将gflags定义在专门的配置文件中，以方便对程序运行参数管理。
指定gflags配置文件，./a.out --flagfile=demo_project.gflags

A、gflags支持的类型

DEFINE_bool: boolean

DEFINE_int32: 32-bit integer

DEFINE_int64: 64-bit integer

DEFINE_uint64: unsigned 64-bit integer

DEFINE_double: double

DEFINE_string: C++ string

B、gflags的名字空间：DEFINE_XXX和DECLARE_XXX都是全局命名空间。

C、常用的特殊flag

--help  显示文件中所有标识的完整帮助信息
--helpfull  和-help 一样，
--helpshort  只显示当前执行文件里的标志
--helpxml  以 xml 凡是打印，方便处理
--version  打印版本信息，由 google::SetVersionString()设定
--flagfile  -flagfile=f 从文件 f 中读取命令行参数
*/

#endif // GFLAGS_GLOG_H
