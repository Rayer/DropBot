// Copyright Vladimir Prus 2002-2004.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "SampleDaemon.h"

/* The simplest usage of the library.
 */


int main(int ac, char* av[])
{

    SampleDaemon *s = new SampleDaemon();
    s->run(ac, av);
    return 0;
}