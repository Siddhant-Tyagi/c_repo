//merge sort with worst case running time of O(n log n)

#include <iostream>
#include <vector>
#include <cstdlib>

void merge(std::vector<int> &, int, int);
void merge_sort(std::vector<int> &, int, int, int);

int main()
 {
	std::vector<int> arr;
	int len, temp;
	std::cout << "Enter the number of elements: ";
	std::cin >> len;
	std::cout << "Input the elements: ";
	for(int i=0;i<len;i++)
	 {
		std::cin >> temp;
		arr.push_back(temp);
	 }
	int p = 0, r = len-1;
	merge(arr, p, r);
	std::cout << "\nSorted array:  ";
	std::vector<int>::const_iterator i;
	for(i=arr.begin();i!=arr.end();i++)
	  std::cout << (*i) << "     "; 
	std::cout << std::endl;
	return 0;
 }
 
//the divide step of the algorithm 
void merge(std::vector<int>& arr, int p, int r)
 {
	int q;
	if(p<r-1)
	 {
		q = (p+r)/2;
		merge(arr, p, q);
		merge(arr, q+1, r);
		merge_sort(arr, p, q, r);
 	 }
 }
 
//the conquer step of the algorithm
void merge_sort(std::vector<int>& arr, int p, int q, int r)
 {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int> left;
	std::vector<int> right;
	for(int i=0; i<n1; i++)
	 {
		left.push_back(arr[p+i]);
	 }
	for(int j=0; j<n2; j++)
	 {
		right.push_back(arr[q+j+1]);
	 }
	left.push_back(99999999);    //infinity assumed to be 99999999
	right.push_back(99999999);   //infinity assumed to be 99999999
	int i = 0, j = 0;
	for(int k=p;k<r;k++)
	 {
		if(left[i]<=right[j])
		 {
			arr[k] = left[i];
			i++;
		 }
		else
		 {
			arr[k] = right[j];
			j++;
		 }
	 }
 }
 
