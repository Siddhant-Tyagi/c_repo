/*Closest Pair
 * Given n(2<=n<=1000) points in a 1-dimensional array, find
 * the distance between the closest pair of points.
 * You need to fill the logic in a function which takes as input
 * an integer n and an integer array p[] for 0<=i<n,-10^9),
 * containing n points and sets the output variable to the distance
 * between the closest pair of points.
 * 
 * Example:
 * Input:
 * 5 {10,2,-4,5,29}
 * 
 * Output:
 * 3
 * 
 * Explanation:
 * In the above example, distance between 2 and 5 is 3,
 * distance between all the other points is greater than 3. So,
 * distance between closest pair is 3.
 */


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
  {
	  int arr[30], i=0, result=0, closest=15000, j=0;
	  FILE *fp;
	  char buffer[1000], *ptr;
	  fp = fopen("arr.txt", "r");
	  if(fgets(buffer,900,fp) != NULL)
	    {
			puts(buffer);
		}
	  fclose(fp);
	  ptr = strtok(buffer, " ");
	  while(ptr != NULL)
	    {
			arr[i] = atoi(ptr);
			i++;
			ptr = strtok(NULL, " ");
		}
	  for(i=0;i<29;i++)
	    {
			//printf("%d", arr[i]);
			for(j=i+1;j<=29;j++)
			  {
				  result = abs(arr[i]-arr[j]);
				  if(closest>result)
				    {
						closest = result;
					}
			   }
		 }
 
	   printf("\n\n\nClosest point:%d\n", closest);
	   return 0;
  }
