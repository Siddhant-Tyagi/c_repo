/*Enter the element number n and get the 
  fibbonaci series result for the nth element*/

#include<stdio.h>
#include<stdlib.h>

int fibbonaci(int);

int main(void)
  {
	  int num, result;
	  printf("Enter the element:");
	  scanf("%d", &num);
	  result = fibbonaci(num-1);
	  printf("Result: %d\n", result);
	  return 0;
  }
  
int fibbonaci(int num)
  {
	  if(num==1)
	    return 1;
	  if(num==0)
	    return 0;
	  return (fibbonaci(num-1)+fibbonaci(num-2));
  }
