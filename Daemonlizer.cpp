//
// Created by rayer on 2016/2/2.
//

#include "Daemonlizer.h"
#include <fstream>
#include <iostream>

#ifndef WIN32

#include <signal.h>

#endif

using namespace std;

int Daemonlizer::_daemon_flow(int argc, char **argv) {

    pid_t process_id = 0;
    pid_t sid = 0;

    if (this->pid_file_exists()) {
        ifstream f(this->pid_file_name());
        //string content(istreambuf_iterator<char>(f), istreambuf_iterator<char>());
        string content = string(istreambuf_iterator<char>(f), istreambuf_iterator<char>());

        // string content("123");
        pid_t pid = stoi(content);
        cout << "PID file existed : " << pid << endl;
        cout << "Killing..." << endl;
        kill(pid, 9);
    }

    process_id = fork();


    if (process_id < 0) {
        printf("fork failed\n");
        exit(1);
    }


    printf("process_id = %d\n", process_id);

    if (process_id > 0) {
        //Non-daemon logic(including argument parsing) here
        //this->_init_parent();
        this->pid_file_delete();
        this->create_pid_file(process_id);
        printf("process_id of child process %d \n", process_id);
        this->application_main(argc, argv);
        exit(0);
    }

    //this->_init_child();

    umask(0);
    sid = setsid();
    if (sid < 0) {
        printf("Set SID failed\n");
        exit(1);
    }


    //close(STDIN_FILENO);
    //close(STDOUT_FILENO);
    //close(STDERR_FILENO);

    //Daemon Logic Here.....
    int ret = 0;
    while (true) {
        ret = this->daemon_main();
        if (ret > 0)
            break;
        sleep(1);
    }

    return ret;

}

int Daemonlizer::run(int argc, char **argv) {
    return _daemon_flow(argc, argv);
}

Daemonlizer::~Daemonlizer() { }

bool Daemonlizer::pid_file_exists() {
    struct stat buffer;
    return stat(this->pid_file_name().c_str(), &buffer) == 0;
}

string Daemonlizer::pid_file_name() {
    string ret;
    ret.append(PID_DIR);
    ret.append(APP_NAME);
    ret.append(".pid");
    return ret;
}

void Daemonlizer::pid_file_delete() {
    remove(pid_file_name().c_str());
}

void Daemonlizer::create_pid_file(pid_t pid) {
    ofstream f(pid_file_name());
    printf("dump pid %d to file...\n", pid);
    f << pid;
    f.flush();
    f.close();
}
