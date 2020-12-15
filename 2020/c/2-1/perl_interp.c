/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include <EXTERN.h>
#include <perl.h>
#include "perl_interp.h"

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

FileContent *fgetLines(char *routineName)
{
    // Consideration to avoid two for loops. Have another
    //  subroutine that gets called that returns file content size
    //  and pop that before the string. Is it better than 2 for loops...
    //  ¯\_(ツ)_/¯
    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);

    char *args[] = { NULL };
    int count = call_argv(routineName, G_ARRAY | G_NOARGS, args);
    SPAGAIN;

    STRLEN len;
    char *temp[count];
    int totalChars = 0;
    if(count > 0)
    {
        for(int i = count - 1; i >= 0; i--)
        {
            SV *sv = POPs;
            temp[i] = SvPV(sv, len);
            totalChars += strlen(temp[i]);
        }
    }
    else
    {
        printf("I'm too lazy to handle errors right now just die");
        exit(1);
    }
    FileContent *c;
    c = malloc(sizeof(*c) + (sizeof(int) * (totalChars)));
    c->t_chars = totalChars;
    c->t_lines = count;

    for(int i = 0; i < count; i++)
    {
        c->lines[i] = strdup(temp[i]);
    }

    PUTBACK;
    FREETMPS;
    LEAVE;

    return c;
}
