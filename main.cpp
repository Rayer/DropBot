// Copyright Vladimir Prus 2002-2004.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "SampleDaemon.h"
#include <iostream>
#include <boost/program_options.hpp>
/* The simplest usage of the library.
 */

namespace po = boost::program_options;

int main(int ac, char* av[])
{
    po::options_description desc("Allowed options");
    desc.add_options()
            ("help", "produce help message")
            ("non-daemon", "Run blocking mode")
            ("terminate", "Terminate existing DropBot daemon(s)")
            ("daemon-status", "Show current daemon(s) and its status");


    po::variables_map vm;
    po::store(po::parse_command_line(ac, av, desc), vm);
    po::notify(vm);

    if(vm.count("help")) {
        std::cout << desc << std::endl;
        exit(0);
    }

    SampleDaemon *s = new SampleDaemon();
    s->set_daemon(vm.count("non-daemon") == 0);
    s->run(ac, av);
    return 0;
}