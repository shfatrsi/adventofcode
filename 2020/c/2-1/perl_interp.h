/*
 * Call before allocating for perl interpreter setup
 */
void pSetup(int argc, char **argv, char **env);

/*
 * Call after all operations for Interpreter are done
 */
void pFree(void);

/*
 * Run subroutine that gets content of file lines from the Perl stack
 */
void fgetLines(char *routineName);

/*
 * Test interpretor program like running perl commands at the command line
 */
void p(int argc, char **argv, char **env);

/*
 * Run a subroutine practice with no return values
 */
void subRun(char *routineName);
