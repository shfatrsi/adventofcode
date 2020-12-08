/*
 * Call before allocating for perl interpreter setup
 */
void p_setup(int argc, char **argv, char **env);

/*
 * Call after all operations for Interpreter are done
 */
void p_free(void);

/*
 * Call to parse file contents
 *  uhf: To be expanded
 */
void parse(char *fileName);

/*
 * Test interpretor program like running perl commands at the command line
 */
void p(int argc, char **argv, char **env);
