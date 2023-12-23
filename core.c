#include "core.h"

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

int _process (SContext* s_new_context)
{
    if (s_new_context->fp_script == NULL) {
        fprintf(stderr, "File pointer is null\n");
    }

    if (s_new_context->e_state != IDLE) {
        fprintf(stderr, "context is not idled\n");
    }
    s_superman.sa_contexts[s_superman.ul_count] = s_new_context;

}


void dump_context (const SContext* s_context)
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
}