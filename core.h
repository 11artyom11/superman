#pragma once

#include "super_defines.h"

#include <unistd.h>
#include <stdio.h>

enum State{
    IDLE,
    RUNNING,
    STOPPED,
    ENDED,
    ERROR
};

typedef struct 
{
    FILE* fp_script;
    enum State e_state;
} SContext;

typedef struct {
    SContext* sa_contexts[256];
    unsigned long ul_count;
} SuperMan;

static SuperMan s_superman;

int create_context  (const char* file_path, SContext* s_new_context);
int enqueue_process (SContext* s_new_context);
void dump_context   (const SContext* s_context);
