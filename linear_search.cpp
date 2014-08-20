#include <iostream>
#include <vector>

int main()
 {
	std::vector<int> input;
	int len, temp, pos=-1, element;
    std::cout << "Enter the number of elements: ";
    std::cin >> len;
    for(int i=0;i<len;i++)
     {
		std::cin >> temp;
		input.push_back(temp);
	 }
	std::cout << "Element to find: ";
	std::cin >> element;
	for(int i=0;i<len;i++)
	 {
		if(element==input[i])
		 {
			pos = i+1;
			break;
		 }
	  }
	if(pos!=-1)
	 {
		std::cout << "Element found at position: " << pos <<std::endl;
	 }
	else
	 {
		std::cout << "Element not found." << std::endl;
	 }
	return 0;
 }
