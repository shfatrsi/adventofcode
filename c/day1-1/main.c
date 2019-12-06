/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/** Defines **/
#define NELEMS(x) (sizeof x / sizeof *x)

/** Enums **/
typedef enum {false, true} bool;

/** Prototypes Declerations **/
int* readCloseFile(FILE *file, int *arrSize);
void fuelCalc(int *values, int arrSize);
bool isDigit(char c);
bool isNewline(char c);

/** Main **/
int main()
{
     int arrSize = 0;
     int *arr=readCloseFile(
	  fopen("C:/input/day1-1",
	  "r"),
	  &arrSize);

     fuelCalc(arr, arrSize);

     getchar();
     return(0);
}

/** Prototype Implementations **/
int* readCloseFile(FILE *file, int *arrSize)
{
     fseek(file, 0L, SEEK_END);
     // File size now know
     int fs = ftell(file);
     rewind(file);
     printf("File Size: %d\n", fs);

     // Allocate
     int *numArr = malloc(fs);
     int endSize = NELEMS(numArr);
     int arrSizeReal = 0;
     printf("Number size: %d\n\n", numArr);

     char *buff = malloc(10);
     for(int i=0; feof(file) != 1; i++)
     {
	  fscanf(file, "%s", buff);
	  int buffelems = NELEMS(buff);
	  int number = 0;
	  int mult = 1;
	  int tmp2;
	  // Maybe in the future something different would
	  //  be better but this is Advent of Code so 
	  for (int i=buffelems, tmp2=0; i>-1; i--)
	  {
	       if (isDigit(buff[i]))
	       {
		    tmp2 = buff[i] - '0';
		    tmp2 *= mult;
		    number += tmp2;
		    mult *= 10;
	       }
	  }
	  //printf("Line number: %s\n", buff);
	  //printf("number now: %d\n", number);

	  if (numArr[i] == endSize)
	  {
	       // TODO(shf): Realocate array size if end
	       //  reached
	  }
	  else
	  {
	       numArr[i] = number;
	       arrSizeReal++;
	  }
     }

     printf("real array size: %d\n", arrSizeReal);
     
     /*for (int i=0; ; i++)
     {
	  // Get the Character
	  c = fgetc(fp);

	  // If it's a digit put it into temp array
	  // that needs to be converted to a number at end
	  if (isDigit(c))
	  {
	       nsize++;
	  }
	  if (isNewline(c))
	  {
	       printf("nsize: %d\n", nsize);
	       nsize = 0;
	  }
	  
	  // End of File
	  if (feof(fp))
	  {
	       break;
	  }
	  printf("%c, %d\n", c, c);
     }
     fclose(fp);*/

     // Assign file size, close file, and return ptr with
     // number values
     *arrSize = arrSizeReal;
     fclose(file);

     return numArr;
}

void fuelCalc(int *arr, int arrSize)
{
     int total=0;

     for(int i=0; i<arrSize; i++)
     {
	  total += (floor(arr[i]/3)) - 2;
     }

     printf("Total: %d", total);
     /*printf("%d\n", arrSize);
     for (int i=0; i<arrSize; i++)
     {
	  printf("Array Number: %d\n", arr[i]);
     }*/
}

bool isDigit(char c)
{
     if(c >= '0' && c <='9')
     {
	  return true;
     }
     return false;
}

bool isNewline(char c)
{
     if(c == '\n')
     {
	  return true;
     }
     return false;
}
