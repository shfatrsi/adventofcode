/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Defines **/
#define NELEMS(x) (sizeof x / sizeof *x)

/** Enums **/
typedef enum {false, true} bool;

/** Prototypes **/
static bool isDigit(char c);
static bool isNewline(char c);

static int* readCloseFile(FILE *file, int *arrSize);

/** Main **/
int main(void)
{
    printf("Starting\n");
    FILE *fp = fopen("input", "r");

    if(fp == NULL)
    {
        printf("Failed to open input.");
        exit(1);
    }
    char c;
    int total = 0;
    int nums[199];
    char buf[10];
    for(int j = 0; (c = fgetc(fp)) != EOF; j++)
    {
        if(c == '\n')
        {
            buf[j] = '\0';
            nums[total] = atoi(buf);
            total++;
            j = -1;
            continue;
        }
        buf[j] = c;
    }
    //printf("\n%d", i);

    printf("\n %d\n", (2147483647 / 3600));

    for(int i = 0; i < 200; i++)
    {
        for(int j = 0; j < 200; j++)
        {
            for(int k = 0; k < 200; k++)
            {
                if((nums[i] + nums[j] + nums[k]) == 2020)
                {
                    printf("answer: %d\n", (nums[i] * nums[j] * nums[k]));
                    return(0);
                }
            }
        }
    }

    getchar();
    return(0);
}

static bool isDigit(char c)
{
    if(c >= '0' && c <= '9')
    {
        return true;
    }
    return false;
}

static bool isNewline(char c)
{
    if(c == '\n')
    {
        return true;
    }
    return false;
}
