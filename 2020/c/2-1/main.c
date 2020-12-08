/** Includes **/
#include <stdio.h>
#include "perl_interp.h"

/** Main **/
int main(int argc, char **argv, char **env)
{
    p_setup(argc, argv, env);
    p(argc, argv, env);
    p_free();
    return(0);
}
