//
// Created by rayer on 2015/9/14.
//

#ifndef SCG_CLUSTER_NATIVE_AGENT_DAEMONLIZER_H
#define SCG_CLUSTER_NATIVE_AGENT_DAEMONLIZER_H

#include <vector>
#include <string>
#include "Daemonlizer.h"
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

class DefaultContext {
private:
    bool single_step;
    bool debug;

public:
    void isDebug();
    void isSingleStep();
};

template<typename Daemonlizer_Context = DefaultContext>
class Daemonlizer {
private:
    Daemonlizer_Context* context;


    int _daemon_flow(int argc, char* argv[]) {
        FILE *fp = NULL;
        pid_t process_id = 0;
        pid_t sid = 0;

        process_id = fork();

        if(process_id < 0) {
            printf("fork failed\n");
            exit(1);
        }

        printf("process_id = %d\n", process_id);

        if(process_id > 0) {
            //Non-daemon logic(including argument parsing) here
            //this->_init_parent();
            printf("process_id of child process %d \n", process_id);
            this->application_main(argc, argv);
            exit(0);
        }

        //this->_init_child();

        umask(0);
        sid = setsid();
        if(sid < 0) {
            printf("Set SID failed\n");
            exit(1);
        }


        //close(STDIN_FILENO);
        //close(STDOUT_FILENO);
        //close(STDERR_FILENO);

        //Daemon Logic Here.....
        this->daemon_main();

        return 0;
    }
protected:
    virtual void init_with_context(Daemonlizer_Context* context) {

    }

public:
    Daemonlizer() : context(new Daemonlizer_Context()) {
        init_with_context(context);
    }

    Daemonlizer(Daemonlizer_Context* in_context) : context(in_context) {
        init_with_context(context);
    }

    /**
     * It's main application.
     * TBD: Search for paired daemon PID
     */
    virtual int application_main(int argc, char* argv[]) = 0;
    /**
     * It's daemon logic
     */
    virtual int daemon_main() = 0;

    int run(int argc, char* argv[]) {
        return _daemon_flow(argc, argv);
    }

    virtual ~Daemonlizer() {
        delete context;
    }
};



#endif //SCG_CLUSTER_NATIVE_AGENT_DAEMONLIZER_H
