
#include <iostream>
#include <thread>


#include "os.h"
#include "vehicle.h"

void print_thread_id_and_core_count();
void example_task_to_emulate_randomness();
void example_detach();
void threadFunctionEven();
void threadFunctionOdd();

int main(){
    //create a single thread
    std::thread t(print_thread_id_and_core_count);
    std::cout<<"Created a single thread"<<std::endl;
    t.join();

    //EXAMPLE: randomness of events
    std::thread t0(example_task_to_emulate_randomness);
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work 1 in main\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
    std::cout << "Finished work 2 in main\n";
    t0.join();


    //EXAMPLE: detach()
    std::thread t1(example_detach);
    t1.detach();
    std::cout<<"Thread t1 detached"<<std::endl;


    //EXAMPLE: multiple threads
    std::cout<<"Multiple thread example (detach) started"<<std::endl;

    for (int i = 0; i < 6; i++)
    {
        std::thread t2((i%2)?threadFunctionOdd:threadFunctionEven);
        t2.detach();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::cout<<"Multiple thread example (detach) finished"<<std::endl;
    


    //EXAMPLE: multiple threads (sleep_for removed)
    std::cout<<"Multiple thread example (detach) started (sleep_for removed)"<<std::endl;

    for (int i = 0; i < 6; i++)
    {
        std::thread t2((i%2)?threadFunctionOdd:threadFunctionEven);
        t2.detach();
    }
    std::cout<<"Multiple thread example (detach) finished (sleep_for removed)"<<std::endl;


    //EXAMPLE: passing function objects to threads
        // create thread 
    std::thread t3((Vehicle(1))); // C++'s most vexing parse

    // do something in main()
    std::cout << "created t3 \n";

    // wait for thread to finish
    t3.join();
    //copy initialization

    std::thread t4=  std::thread( Vehicle(2) ); 

    // do something in main()
    std::cout << "created t4(copy initialization) \n";

    // wait for thread to finish
    t4.join();

   //uniform initialization

    std::thread t5{Vehicle(3)}  ; 

    // do something in main()
    std::cout << "created t5(uniform initialization) \n";

    // wait for thread to finish
    t5.join();

    return 0;


}

void print_thread_id_and_core_count(){
    std::cout<<"Thread started"<<std::endl;
    Os os;
    //get current thread id
    std::cout<<"Current thread id: "<<os.current_thread_id()<<std::endl;
    //get number of cores
    std::cout<<"Number of cores: "<<os.core_count()<<std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Thread finished working."<<std::endl;

}

void example_task_to_emulate_randomness(){
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work 1 in thread\n"; 

    std::this_thread::sleep_for(std::chrono::milliseconds(50)); 
    std::cout << "Finished work 2 in thread\n"; 
}


void threadFunctionEven()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Even thread\n";
}

void threadFunctionOdd()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1)); // simulate work
    std::cout << "Odd thread\n";
}


void example_detach(){
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in thread (detach example)\n"; 
}