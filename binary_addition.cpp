#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <cstring>


int main(int argc, char *argv[])
 {
	std::vector<int> input1, input2, solution;
	int len, binary;
	std::vector<int>::const_iterator iter;
	//std::cout << "Enter the length of the binary integer: ";
	//std::cin >> len;
	len = std::strlen(argv[1]);
	//input1.resize(len);
	//input2.resize(len);
	solution.resize(len+1);
	std::cout << "size of sol: " << solution.size() <<std::endl;
	for(int i=0;i<std::strlen(argv[1]);i++)
	 {
		
	    binary = argv[1][i] - '0';
	    input1.push_back(binary);
	    binary = argv[2][i] - '0';
	    input2.push_back(binary);
	 }
	int carry=0;
	std::cout << std::endl;
	/*for(iter=input2.begin();iter!=input2.end();iter++)
	 {
		std::cout << (*iter) << "  ";
	 }*/
	for(int i=(len-1);i>=0;i--)
	 {
		if(input1[i]==0 && input2[i]==0)
		 {
			if(carry==1)
			 {
				solution[i+1] = 1;
				carry = 0;
			 }
			else
			 {
				solution[i+1] = 0;
				carry = 0;
			 }
		 }
		 
		if(input1[i]==1 && input2[i]==0 || input1[i]==0 && input2[i]==1)
		 {
			if(carry==1)
			 {
				solution[i+1] = 0;
				carry = 1;
			 }
			else
			 {
				solution[i+1] = 1;
				carry = 0;
			 }
		 }
		 
		if(input1[i]==1 && input2[i]==1)
		 {
			if(carry==1)
			 {
				solution[i+1] = 1;
				carry = 1;
			 }
			else
			 {
				solution[i+1] = 0;
				carry = 1;
			 }
		 }
		 
		if(i==0 && carry==1)
		 {
			solution[i] = 1;
		 }
		if(i==0 && carry==0)
		 {
			solution[i] = 0;
		 }
	 }
	 
	std::cout << "Binary Addition of " << argv[1] << " + " << argv[2] << " : ";
	for(iter=solution.begin();iter!=solution.end();iter++)
	 {
		std::cout << (*iter) << "  ";
	 }
	std::cout << std::endl;
	return 0;
	
 }
