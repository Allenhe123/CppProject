#include <iostream>
#include "future.h"
#include "gflags_glog.h"

using namespace std;

int main(int argc, char* argv[])
{
//    future_test();

    gflags_test(argc, argv);

    cout << "Hello World!" << endl;
    return 0;
}
