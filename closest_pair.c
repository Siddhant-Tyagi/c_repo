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
