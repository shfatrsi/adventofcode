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
    int count = call_argv(routineName, G_DISCARD | G_NOARGS, args);
}

void fgetLines(char *routineName)
{
    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);

    char *args[] = { NULL };
    int count = call_argv(routineName, G_ARRAY | G_NOARGS, args);
    SPAGAIN;

    STRLEN len;
    char *s[count];
    if(count > 0)
    {
        for(int i = 0; i < count; i++)
        {
            SV *sv = POPs;
            s[i] = SvPV(sv, len);
            printf("%s", s[i]);
        }
    }
    PUTBACK;
    FREETMPS;
    LEAVE;
}
