#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

int counter;
mutex mtx;
condition_variable cv;
bool done = false;

void even_thread()
{
    while(true) {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [](){return counter%2 == 0 || done;});
        if (done || counter > 50) {
            done = true;
            cv.notify_all();
            break;
        }
        cout << counter++<<endl;
        cv.notify_all();
    }
}

void odd_thread()
{
    while(true) {
        unique_lock<mutex> lk(mtx);
        cv.wait(lk, [](){return counter%2 || done;});
        if (done || counter > 50) {
            done = true;
            cv.notify_all();
            break;
        }
        cout << counter++<<endl;
        cv.notify_all();
    }
}

int main()
{
    thread t1(even_thread);
    thread t2(odd_thread);
    t1.join();
    t2.join();
    return 0;
}