#include <iostream>
#include <vector>
#include <cstdlib>

void heapsort(std::vector<int> &);
void build_max_heap(std::vector<int> &);
void max_heapify(std::vector<int> &, int, int);
void traverse(std::vector<int> &);

int main()
 {
	int temp;
	std::vector<int> arr;
	//std::cout << "\nFirst ele: " << arr[0] << std::endl;
	std::cout << "\nEnter the elements to build the heap. " << std::endl;
	char choice[10] = "yes";
	while(choice[0]=='y' || choice[0]=='Y')
	 {
		std::cout << "\nInput element: ";
		std::cin >> temp;
		arr.push_back(temp);
		std::cout << "\nInput another? Y or N  ";
		std::cin >> choice;
	 }
	heapsort(arr);
	//build_max_heap(arr);
	std::cout << "\nSorted Array:   ";
	traverse(arr);
	return 0;
 }

void heapsort(std::vector<int> &arr)
 {
	build_max_heap(arr);
	int len = arr.size()-1;
	for(int i=len;i>=0;i--)
	 {
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		len--;
		max_heapify(arr, 0, len);
	 }
 }

void build_max_heap(std::vector<int> &arr)
 {
	int len = arr.size();
	//std::cout << "Len = " << len << std::endl;
	for(int i=(len/2)-1;i>=0;i--)
	 {
		//std::cout << "i's value in for loop: " << i << std::endl;
		max_heapify(arr, i, len-1);
	 }
 }

void max_heapify(std::vector<int> &arr, int i, int len)
 {
	int largest;
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l<=len && arr[l]>arr[i])
	   largest = l;
	else
	   largest = i;
	if(r<=len && arr[r]>arr[largest])
	   largest = r;
	if(i!=largest)
	 {
		int temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;
		//traverse(arr);
		//exit(0);
		max_heapify(arr, largest, len);
	 }
 }

void traverse(std::vector<int> &arr)
 {
	std::vector<int>::const_iterator i;
	for(i=arr.begin();i!=arr.end();i++)
	   std::cout << (*i) << "     ";
	std::cout << std::endl << std::endl;
 }
