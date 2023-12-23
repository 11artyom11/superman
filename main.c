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

	if ((status &= create_context(argv[1], &context)) != S_SUCCESS) {
		return F_FATAL_EXIT;
	}

	if ((status &= dump_context(&context)) != S_SUCCESS) {
		return F_FATAL_EXIT;
	}
   
	if ((status &= enqueue_process(&context)) != S_SUCCESS) {
		return F_FATAL_EXIT;
	}
   
	if ((status &= enqueue_process(&context))!= S_SUCCESS) {
		return F_FATAL_EXIT;
	}

}