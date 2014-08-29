//Quick Sort with average running time of O(n log n)
#include <iostream>
#include <vector>
#include <cstdlib>

void QuickSort(std::vector<int> &, int, int);
int partition(std::vector<int> &, int, int); 

int main()
 {
	std::vector<int> arr;
	int len, tmp;
	std::cout << "\nEnter the number of elements: ";
	std::cin >> len;
	std::cout << "Enter the elements.\n";
	for(int i=0;i<len;i++)
	 {
		std::cin >> tmp;
		arr.push_back(tmp);
	 }
	int p = 0, r = len-1; 
	QuickSort(arr, p, r);
	std::vector<int>::const_iterator i;
	std::cout << "\nSorted array: ";
	for(i=arr.begin();i<arr.end();i++)
	 {
		std::cout << (*i) << "    ";
	 }
	std::cout << std::endl; 
	return 0;
 }

void QuickSort(std::vector<int> &arr, int p, int r)
 {
	int q;
	if(p<r-1)
	 {
		q = partition(arr, p, r);
		//std::cout << "P: " << p << " Q: " << q << " R: " << r << std::endl;
		QuickSort(arr, p, q-1);
		QuickSort(arr, q, r);
     }
 }
 
int partition(std::vector<int> &arr, int p, int r)
 {
	int pivot, i, tmp, j;
	pivot = arr[r];
	i = p - 1;
	for(j=p;j<r;j++)
	 {
		if(arr[j]<=pivot)
		 {
			i = i + 1; 
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		 }
	 }
	tmp = arr[i+1];
	arr[i+1] = arr[r];
	arr[r] = tmp;
	return i+1;
 }
