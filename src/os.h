#ifndef OS_H_
#define OS_H_


#include <thread>
#include <string>


class Os{
    public:
        std::thread::id current_thread_id();
        unsigned int core_count();

};

#endif 