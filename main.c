#include "super_defines.h"
#include "core.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

i32 main(int argc, char* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "[ERROR] Please provide the path of the script\n");
        return F_NOT_ENOUGH_ARGS;
    }
    
    i32 status = 0;
    SContext context;

    create_context(argv[1], &context);
    dump_context(&context);
    enqueue_process(&context);
    enqueue_process(&context);
}