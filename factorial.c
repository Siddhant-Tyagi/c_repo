//calculating factorial through recursion
#include<stdio.h>
#include<stdlib.h>

int factorial(int);

int main(void)
  {
	  int num, result;
	  scanf("%d", &num);
	  result = factorial(num);
	  printf("\n%d\n", result);
	  return 0;
  }

int factorial(int n)
  {
	  if(n==1)
	    return 1;
	  return n*factorial(n-1);
   }
