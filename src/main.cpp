
#include <iostream>
#include <thread>

#include "os.h"
#include "vehicle.h"

#define CURRENT_EXAMPLE 10

void print_thread_id_and_core_count();
void example_task_to_emulate_randomness();
void example_detach();
void threadFunctionEven();
void threadFunctionOdd();

int main()
{
#if CURRENT_EXAMPLE == 1
    //create a single thread
    std::thread t(print_thread_id_and_core_count);
    std::cout << "Created a single thread" << std::endl;
    t.join();
#elif CURRENT_EXAMPLE == 2

    //EXAMPLE: randomness of events
    std::thread t(example_task_to_emulate_randomness);
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work 1 in main\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Finished work 2 in main\n";
    t0.join();
#elif CURRENT_EXAMPLE == 3

    //EXAMPLE: detach()
    std::thread t(example_detach);
    t1.detach();
    std::cout << "Thread t1 detached" << std::endl;

#elif CURRENT_EXAMPLE == 4
    //EXAMPLE: multiple threads
    std::cout << "Multiple thread example (detach) started" << std::endl;

    for (int i = 0; i < 6; i++)
    {
        std::thread t((i % 2) ? threadFunctionOdd : threadFunctionEven);
        t2.detach();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::cout << "Multiple thread example (detach) finished" << std::endl;

#elif CURRENT_EXAMPLE == 5

    //EXAMPLE: multiple threads (sleep_for removed)
    std::cout << "Multiple thread example (detach) started (sleep_for removed)" << std::endl;

    for (int i = 0; i < 6; i++)
    {
        std::thread t((i % 2) ? threadFunctionOdd : threadFunctionEven);
        t2.detach();
    }
    std::cout << "Multiple thread example (detach) finished (sleep_for removed)" << std::endl;

#elif CURRENT_EXAMPLE == 6
    //EXAMPLE: passing function objects to threads
    // create thread
    std::thread t1((Vehicle(1))); // C++'s most vexing parse

    // do something in main()
    std::cout << "created t1 \n";

    // wait for thread to finish
    t1.join();
    //copy initialization

    std::thread t2 = std::thread(Vehicle(2));

    // do something in main()
    std::cout << "created t2(copy initialization) \n";

    // wait for thread to finish
    t2.join();

    //uniform initialization

    std::thread t3{Vehicle(3)};

    // do something in main()
    std::cout << "created t3(uniform initialization) \n";

    // wait for thread to finish
    t3.join();
#elif CURRENT_EXAMPLE == 7
    //EXAMPLE: lambdas
    int id = 0; // Define an integer variable

    //auto f0 = []() { std::cout << "ID = " << id << std::endl; }; // Error: 'id' cannot be accessed

    id++;
    auto f1 = [id]() { std::cout << "ID = " << id << std::endl; }; // OK, 'id' is captured by value

    id++;
    auto f2 = [&id]() { std::cout << "ID = " << ++id << std::endl; }; // OK, 'id' is captured by reference

    //auto f3 = [id]() { std::cout << "ID = " << ++id << std::endl; }; // Error, 'id' may not be modified

    auto f4 = [id]() mutable { std::cout << "ID = " << ++id << std::endl; }; // OK, 'id' may be modified

    auto f5 = [id]()mutable{std::cout << "ID = " << ++id<< " * "<<id<<" = "<<id*id << std::endl; };

    // execute lambdas
    f1();
    f2();
    f4();
    f5();

#elif CURRENT_EXAMPLE == 8
    int id = 0; // Define an integer variable

    // create lambda
    auto f = [](const int id) { std::cout << "ID = " << id << std::endl; }; // ID is passed as a parameter

    // execute function object and pass the parameter
    f(id);

#elif CURRENT_EXAMPLE == 9

    //QUIZ: lambdas

    int id = 0; // Define an integer variable

    // capture by reference (immutable)
    auto f0 = [&id]() { std::cout << "a) ID in Lambda = " << id << std::endl; };

    // capture by value (mutable) 
    auto f1 = [id]() mutable { std::cout << "b) ID in Lambda = " << ++id << std::endl; };
    f1(); // call the closure and execute the code witin the Lambda
    std::cout << "c) ID in Main = " << id << std::endl;

    // capture by reference (mutable)
    auto f2 = [&id]() mutable { std::cout << "d) ID in Lambda = " << ++id << std::endl; };
    f2(); 
    std::cout << "e) ID in Main = " << id << std::endl; 

    // pass parameter 
    auto f3 = [](const int id) { std::cout << "f) ID in Lambda = " << id << std::endl; };   
    f3(++id);

    // observe the effect of capturing by reference at an earlier point in time
    f0(); 
#elif CURRENT_EXAMPLE 10
    


#endif
    return 0;
}

void print_thread_id_and_core_count()
{
    std::cout << "Thread started" << std::endl;
    Os os;
    //get current thread id
    std::cout << "Current thread id: " << os.current_thread_id() << std::endl;
    //get number of cores
    std::cout << "Number of cores: " << os.core_count() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "Thread finished working." << std::endl;
}

void example_task_to_emulate_randomness()
{
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

void example_detach()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // simulate work
    std::cout << "Finished work in thread (detach example)\n";
}