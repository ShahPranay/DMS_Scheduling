#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

using namespace std;

void perform_job(char* name, int exec_time);

int main(int argc, char *argv[]) {
    int period, exec_time, deadline;
    pid_t pid;
    auto init = chrono::steady_clock::now();

    chrono::steady_clock::time_point exec_start, finish;


    long wakeup_time, finish_time;

    period = atoi(argv[1]);
    exec_time = atoi(argv[2]);
    deadline = atoi(argv[3]);

    cout << "Period is " << period << " Exec time is " << exec_time << " Deadline is " << deadline << endl;

    pid = getpid();

    syscall(452, pid, period, deadline, exec_time);  // SYS_register_dm = 452

    int job = 1;
    do {
        exec_start = chrono::steady_clock::now();
        wakeup_time = chrono::duration_cast<chrono::milliseconds>(exec_start - init).count();
        cout << "Wakeup: " << wakeup_time << endl;


        perform_job(argv[4], exec_time);



        finish = chrono::steady_clock::now();
        finish_time = chrono::duration_cast<chrono::milliseconds>(finish - exec_start).count();
        cout << "Time to finish: " << finish_time << endl;


        // cout << "Ran for " << finish_time - wakeup_time << "ms"<< endl;

        syscall(453, pid);  //

        job++;

        // Scheduling should be performed after the first invocation of sys_yield()
    } while(job < 11);


    cout << "My name is " << argv[4] << " And I am nearly done " << endl;

    syscall(454, pid);  //

    cout << "My name is " << argv[4] << " And I just exited    " << endl;


    return 0;

}



void perform_job(char* name, int exec_time) {

    std::this_thread::sleep_for(std::chrono::milliseconds(exec_time));

    // int k = 0;
    // for(int i = 0; i < 1000000; i++){
    //     k++;
    // }

    cout << "My name is " << name << " And I just computed for " << exec_time << endl;

}
