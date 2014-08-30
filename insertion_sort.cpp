//Insertion sort implementation.
//Worst case and average running time of O(n^2)
#include <iostream>
#include <vector>

int main()
 {
	std::vector<int> arr;
	int i, j, tmp;
	char ch = 'y';
	for(i=0;i<10;i++)
	 {
		std::cin >> tmp;
		arr.push_back(tmp);
	 }
	 
	for(i=0;i<arr.size();i++)
	 {
		tmp = arr[i];
		j = i-1;
		while(tmp<arr[j] && i>0)
		 {
			arr[j+1] = arr[j];
			j--;
		 }
		arr[j+1] = tmp;
	 }
	std::cout << std::endl << std::endl << "Sorted Array:  ";
	std::vector<int>::const_iterator iter;
	for(iter=arr.begin();iter!=arr.end();iter++)
	 {
		std::cout << (*iter) << "     ";
	 }
	 
	std::cout << std::endl;
	return 0;
 }
