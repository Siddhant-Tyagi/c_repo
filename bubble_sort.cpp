//Bubble sort algorithm with worst case and average running
// time of O(n^2)
#include <iostream>
#include <vector>

int main()
 {
    std::vector<int> input;
    std::vector<int>::const_iterator it;
    int len, temp;
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
	return 0;
 }
