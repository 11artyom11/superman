#include "core.h"

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

i32 create_context  (const i8* file_path, SContext* s_new_context)
{
	s_new_context->e_state = IDLE;
	s_new_context->fp_script = fopen(file_path, "rx");
	if (s_new_context->fp_script == NULL) {
		fprintf(stderr, "Failed to open file, rolling down...\n");
		return F_INV_FILE_PATH;
	}
	return S_SUCCESS;
}

i32 enqueue_process (SContext* s_new_context)
{
	printf("Enqueuing process at position %d\n", s_superman.ul_count);
	if (s_new_context->fp_script == NULL) {
		fprintf(stderr, "File poi32er is null\n");
	}

	if (s_new_context->e_state != IDLE) {
		fprintf(stderr, "context is not idled\n");
	}
	s_superman.sa_contexts[s_superman.ul_count] = s_new_context;
	s_superman.ul_count++;
}


i32 dump_context (const SContext* s_context)
{
	printf("FilePTR : %p", s_context->fp_script);
	switch (s_context->e_state)
	{
	case IDLE:
		printf(" : IDLE");
		break;
	case RUNNING:
		printf(" : RUNNING");
		break;
	
	case STOPPED:
		printf(" : STOPPED");
		break;
	
	case ERROR:
		printf(" : ERROR");
		break;
	case ENDED:
		printf(" : ENDED");
		break;
	default:
		break;
	}
	printf("\n");
	return S_SUCCESS;
}