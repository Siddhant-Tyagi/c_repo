#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int base_to_the_power(int, int);

int main(void)
  {
	  int base, power, result;
	  //double result1;
	  printf("Enter base:");
	  scanf("%d", &base);
	  printf("Enter power:");
	  scanf("%d", &power);
	  result = base_to_the_power(base, power);
	  //result1 = pow(16.0, 0.5);
	  printf("%d raise to the power %d: %d\n", base, power, result);
	  //printf("\n%f\n", result1);
	  return 0;
  }
  
  
int base_to_the_power(int base, int power)
  {
	  if(power==0)
	    return 1;
	  return base*base_to_the_power(base, power-1);
  }
