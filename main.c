#include "core.h"

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define NOT_ENOUGH_ARGS 0x1

int main(int argc, char* argv[])
{
    if (argc < 2) {
        fprintf(stderr, "[ERROR] Please provide the path of the script\n");
        return NOT_ENOUGH_ARGS;
    }

    SContext context;
    char* script_path;
    script_path = argv[1];
    context.e_state = IDLE;
    context.fp_script = fopen(script_path, "rx");
    dump_context(&context);
}