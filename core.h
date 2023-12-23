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
	SContext* sa_contexts[MAX_CONTEXT];
	u32 ul_count;
} SuperMan;

static SuperMan s_superman;

i32 create_context  (const char* file_path, SContext* s_new_context);
i32 enqueue_process (SContext* s_new_context);
i32 dump_context   (const SContext* s_context);
