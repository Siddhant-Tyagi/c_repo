#include <iostream>
#include <vector>

int main()
 {
	std::vector<int> input;
	std::vector<int>::const_iterator it;
	int len, temp, num, low, mid, high;
	std::cout << "Enter the number of elements: ";
    std::cin >> len;
    for(int i=0;i<len;i++)
     {
		std::cin >> temp;
		input.push_back(temp);
	 }
	for(int i=len-1;i>=1;i--)
	 {
		for(int j=0;j<i;j++)
		 {
			if(input[j+1]<input[j])
			 {
				temp = input[j];
				input[j] = input[j+1];
				input[j+1] = temp;
			 }
		 }
	 }
	std::cout << std::endl << std::endl << "Sorted Array: ";
	for(it=input.begin();it!=input.end();it++)
	 {
		std::cout << (*it) << "   ";
	 } 
	std::cout << std::endl << "Enter the element to be searched: ";
	std::cin >> num;
	low = 0; high = len-1; mid = (low+high)/2;
	while(low<=high && input[mid] != num)
	 {
		if(num>input[mid])
		 {
			low = mid + 1;
			mid = (low+high)/2;
		 }
		if(num<input[mid])
		 {
			high = mid -1;
			mid = (low+high)/2;
		 }
	 }
	if(low>high)
	  std::cout << "Number not found." << std::endl;
	else
	  std::cout << "Number found at position: " << mid + 1 << std::endl;
	return 0;
 }
