
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define _XOPEN_SOURCE
#include <ucontext.h>
#undef _XOPEN_SOURCE

#define CO_DEFAULT_STACK_SIZE (8 * 1024)     // 8kb

void task_entry() {
    printf("HELLO WORLD\n");
}

int main(int argc, char **argv)
{
    char *co_stack = malloc(CO_DEFAULT_STACK_SIZE);
    if(co_stack == NULL) {
        fprintf(stderr, "Failed to allocate stack memory for coroutine");
        return -1;
    }

    bzero(co_stack, CO_DEFAULT_STACK_SIZE);

    ucontext_t ctx;
    ucontext_t ctx_main;

    getcontext(&ctx);

    ctx.uc_stack.ss_sp = co_stack;
    ctx.uc_stack.ss_size = CO_DEFAULT_STACK_SIZE;
    ctx.uc_link = &ctx_main;

    makecontext(&ctx, &task_entry, 0);

    for(int i = 0; i < 10; i++)
    {
        swapcontext(&ctx_main, &ctx);
        makecontext(&ctx, &task_entry, 0);
    }

    free(co_stack);
    return 0;
}