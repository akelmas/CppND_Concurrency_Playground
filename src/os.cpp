#include <thread>
#include <string>

#include "os.h"

std::thread::id Os::current_thread_id(){
    return  std::this_thread::get_id() ;
}

unsigned int Os::core_count(){
    return std::thread::hardware_concurrency();
}