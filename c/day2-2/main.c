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
void readCodes(int *opCodes, int arrSize);
int readFourCodes(int *fourCodes, int arrSize);
int doTheMaths(int *fourCodes, int arrSize);
void replaceCodeWithNewValue(int *opCodes, int index, int newValue);
bool isOob(int num, int arrSize);
bool isCode99(int code);
bool isDigit(char c);
int* copyCodes(int *orgCodes, int arrSize);

/** Main **/
int main()
{
     int arrSize = 0;
     int *opCodes=readCloseFile(
	  fopen("C:/input/day2-1",
	  "r"),
	  &arrSize);

     int answer = 0;
     int result = 0;

     int pos1 = 0;
     int pos2 = 0;
     for(int i=0; result!=19690720 || i==99999;i++)
     {
	  int *cCodes=copyCodes(opCodes, arrSize);

	  readCodes(cCodes, arrSize);
	  //printf("zeroth value: %d\n", cCodes[0]);

	  if (cCodes[0] == 19690720)
	  {
	       answer = cCodes[0];
	  }
	  free(cCodes);
     }
     printf("Answer: %d\n", answer);
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
     // For some reason not having this printf
     //  causes my program to crash and there are
     //  a bunch of \n inbetween each printf in main wut
     printf("File Size: %d\n", fs);

     // Allocate
     int *numArr = malloc(fs);
     int endSize = NELEMS(numArr);
     int arrSizeReal = 0;
     //printf("Number size: %d\n\n", numArr);
     
     for(int i=0; feof(file) != 1; i++)
     {
	  char *buff = malloc(10);
          fscanf(file, "%10[^,]%*c", buff);
	  // TODO(shf): Look deeper into fscanf
	  //  and what strtol does
	  char *tmp;
	  int number = strtol(buff, &tmp, 10);
	
	  if (numArr[i] == endSize)
	  {
	       // TODO(shf): Realocate array size if end
	       //  reached. double check the numbers match
	  }
	  else
	  {
	       numArr[i] = number;
	       arrSizeReal++;
	  }
	  free(buff);
	  free(tmp);
     }

     //printf("real array size: %d\n", arrSizeReal);
     
     // Assign file size, close file, and return ptr with
     // number values
     *arrSize = arrSizeReal;
     // Close file and free ptrs
     fclose(file);

     return numArr;
}

void readCodes(int *opCodes, int arrSize)
{
     for(int i=0; i<arrSize; i+=4)
     {
	  bool code99 = isCode99(opCodes[i]);

	  // Code 99 reached time to stop
	  if (code99)
	  {
	       //printf("code 99\n\n");
	       return;
	  }

	  // This breaks the oob check
	  int pos1 = opCodes[i+1];
	  int pos2 = opCodes[i+2];

	  int fourCodes[] = {opCodes[i],
			     opCodes[pos1],
			     opCodes[pos2],
			     opCodes[i+3]};

	  int value = readFourCodes(fourCodes, arrSize);

	  if(value == -2)
	  {
	       // Out of bounds something is wrong
	       return;
	  }
	  if (value != -1)
	  {
	       //printf("Value: %d", value);
	       replaceCodeWithNewValue(opCodes, fourCodes[3], value);
	  }
     }
}

int readFourCodes(int *fourCodes, int arrSize)
{
     for(int i=0; i<4; i++)
     {
	  /*bool oob = isOob(fourCodes[i], arrSize);
	  if (oob)
	  {
	       printf("Code %d is out of bounds!\n", fourCodes[i]);
	       return(-2);
	  }*/
	  //printf("code: %d\n", fourCodes[i]);
     }
     return(doTheMaths(fourCodes, arrSize));
}

int doTheMaths(int *fourCodes, int arrSize)
{
     int value = -1;

     switch(fourCodes[0])
     {
     case 1:
	  value = fourCodes[1] + fourCodes[2];
	  break;
     case 2:
	  value = fourCodes[1] * fourCodes[2];
	  break;
     default:
	  //printf("Unknown Value\n");
	  break;
     }

     //printf("Value: %d", value);
     return(value);
}

void replaceCodeWithNewValue(int *opCodes, int index, int newValue)
{
     opCodes[index] = newValue;
}

bool isOob(int num, int arrSize)
{
     if(num >= arrSize)
     {
	  return true;
     }
     return false;
}

bool isCode99(int code)
{
     if(code==99)
     {
	  return true;
     }
     return false;
}

bool isDigit(char c)
{
     if(c >= '0' && c <='9')
     {
	  return true;
     }
     return false;
}


int* copyCodes(int *orgCodes, int arrSize)
{
     int *codes = malloc(arrSize);

     for(int i=0; i<arrSize; i++)
     {
	  codes[i] = orgCodes[i];
     }
     return codes;
}
