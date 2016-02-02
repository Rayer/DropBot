//
// Created by Rayer on 2/2/16.
//

#include "SampleDaemon.h"
#include <iostream>


int SampleDaemon::application_main(int argc, char **argv) {
    std::cout << "Application Main" << std::endl;
    return 0;
}

int SampleDaemon::daemon_main() {
    std::cout << "Daemon Main!" << std::endl;
    return 0;
}
