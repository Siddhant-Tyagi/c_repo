#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
  {
	  int arr[30], i=0, count=0, highest=0;
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
	  for(i=0;i<30;i++)
	    {
			if(arr[i+1]<arr[i])
			  count =0;
			  count++; 
			  i++;
			  while(arr[i+1]<arr[i])
			    {
					count++;
					i++;
				}
			  if(count>highest)
			    highest = count;
		 }
		 
	   printf("\nLDS:%d\n", highest);
	   return 0;
  }
