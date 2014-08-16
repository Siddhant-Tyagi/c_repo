#include<stdio.h>
#include<stdlib.h>

void hunt(int mul_arr[5][5]);

int main(void)
  {
	  int arr[5][5] = { 
		                 {34,21,32,41,25},
		                 {14,42,43,14,31},
		                 {54,45,52,42,23},
		                 {33,15,51,31,35},
		                 {21,52,33,13,23}
		               };
      int row, column;
      printf("\n");
      for(row=0;row<5;row++)
        {
			for(column=0;column<5;column++)
			  {
				  printf("%d\t", arr[row][column]);
               }
             printf("\n-----------------------------------------\n");
         }
      printf("\n");
      hunt(arr);
      return 0;
  }

void hunt(int mul_arr[5][5])
  {
	  int current = mul_arr[0][0];
	  //printf("\n\nCurrent:%d\n", current);
	  int units=0, tens=0;
	  while(current!=(tens*10+units))
	    {
			units = current%10;
			tens = current/10;
			current = mul_arr[tens-1][units-1];
			printf("\nVisiting Row:%d and Column:%d", tens, units);
		}
	  printf("\n\nTreasure found!! Row:%d and Column:%d\n\n", tens, units);
  }
