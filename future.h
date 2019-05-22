#ifndef FUTURE_H
#define FUTURE_H

#include <iostream>
#include <future>
#include <utility>
#include <thread>

using namespace std;

void future_test(){
    std::future<int> f1 = std::async(std::launch::async, [](){return 8;} );
    cout << f1.get() << endl;

    std::future<int> f2 = std::async(std::launch::async, [](){ /*cout<<9<<endl; */return 9;} );
    f2.wait();

    std::future<int> f3 = std::async(std::launch::async, [](){std::this_thread::sleep_for(std::chrono::seconds(3)); return 888; } );
    std::cout<<"waiting..."<<endl;
    std::future_status status;
    do
    {
        status = f3.wait_for(std::chrono::seconds(1));
        if (status == std::future_status::deferred)
            std::cout<<"std::future_status::deferred"<<endl;
        else if (status == std::future_status::timeout)
            std::cout<<"std::future_status::timeout"<<endl;
        else if (status == std::future_status::ready)
            std::cout<<"std::future_status::ready"<<endl;

    } while (status != std::future_status::ready);

    std::cout<<"result: "<<f3.get()<<endl;
}

#endif // FUTURE_H
