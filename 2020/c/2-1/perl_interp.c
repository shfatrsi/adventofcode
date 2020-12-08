/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include <EXTERN.h>
#include <perl.h>
#include "perl_interp.h"

/** Prototypes **/
static FILE *openFile(void);

static PerlInterpreter *my_perl;

void pSetup(int argc, char **argv, char **env)
{
    PERL_SYS_INIT3(&argc, &argv, &env);
    my_perl = perl_alloc();
    perl_construct(my_perl);
    perl_parse(my_perl, NULL, argc, argv, NULL);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
}

void pFree(void)
{
    perl_destruct(my_perl);
    perl_free(my_perl);
    PERL_SYS_TERM();
}

void p(int argc, char **argv, char **env)
{
    perl_parse(my_perl, NULL, argc, argv, (char **)NULL);
    perl_run(my_perl);
}

void subRun(char *routineName)
{
    char *args[] = { NULL };
    call_argv(routineName, G_DISCARD | G_NOARGS, args);
}

void parse(char *fileName)
{
}

static FILE *openFile(void)
{
    FILE *fp = fopen("input", "r");

    if(fp == NULL)
    {
        printf("Failed to open 'input' file.");
        exit(1);
    }
    return fp;
}
