/*
 * Call before allocating for perl interpreter setup
 */
void pSetup(int argc, char **argv, char **env);

/*
 * Call after all operations for Interpreter are done
 */
void pFree(void);

/*
 * Call to parse file contents
 *  uhf: To be expanded
 */
void parse(char *fileName);

/*
 * Test interpretor program like running perl commands at the command line
 */
void p(int argc, char **argv, char **env);

/*
 * Run a sub routine practice
 */
void subRun(char *routineName);
