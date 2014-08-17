/*Write a program to search for the "saddle points" in
 * a 5 by 5 array of integers. A saddle point is a cell
 * whose value is greater than or equal to any in its row,
 * and less than or equal to any in its column. There may
 * be more than one saddle point in the array. Print out
 * the coordinates of any saddle points your program finds.
 * Print out "No saddle points" if there are none.*/


#include<stdio.h>
#include<stdlib.h>

int main(void)
  {
	  int arr[5][5] = { 
		                 {34,67,32,41,25},
		                 {14,42,30,14,31},
		                 {54,78,52,42,23},
		                 {33,98,51,31,35},
		                 {21,52,33,13,23}
		               };
      int row, column, r, c, row_count, column_count;
      for(row=0;row<5;row++)
        {
			for(column=0;column<5;column++)
			  {
				  row_count = 0;
				  column_count = 0;
				  for(c=0;c<5;c++)
				    {
						if(arr[row][column]<arr[row][c])
						  {
							  if(column!=c)
							    row_count++;
						   }
					}
			   
				  //printf("\nRow_count:%d\n", row_count);
				  if(row_count==0)
				    {
						for(r=0;r<5;r++)
						  {
							  if(arr[row][column]>arr[r][column])
							    {
									if(row!=r)
									  column_count++;
								}
						  }
					}
				if(row_count==0 && column_count==0)
			      printf("\nSaddle point: Row:%d Column:%d\n", row+1, column+1);
		      }
			   
	      }
		return 0;
	}
		
