#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdio.h>


struct node
 {
	int data;
	node *next;
 };

void input_data(node **);
void push_node(node **);
int delete_node(node **);
void traverse(node *);


int main()
 {
	node *head = new node;
	input_data(&head);
	head->next = NULL;
	//std::cout << std::endl;
	//std::cout << std::endl;
	char choice[5];
	while(1)
	 {
		std::cout << "\n1. Enqueue" << std::endl << "2. Dequeue" << std::endl << "3. Traverse" << std::endl;
		std::cout << "4. Exit" << std::endl << "Enter choice number: ";
		//system("stty raw");
		std::cin >> choice;
		//std::cout << "choice: " << choice << std::endl;
		
		switch(choice[0])
		 {
			case '1':
			   push_node(&head);
			   break;
			
			case '2':
			   delete_node(&head);
			   break;
			
			case '3':
			   traverse(head);
			   break;
			
			case '4':
			   exit(0);
			   break;
			   
			default:
			   exit(0);
			   break;
		 }
		//system("stty cooked");
	 }	 
	//std::cout << std::endl << std::endl;
	//traverse(head);
	//std::cout << "Data: " << head->data << std::endl;
	return 0;
 }


int delete_node(node **head)
 {
	node *prev = NULL;
	node *current = *head;
	if(*head==NULL)
	 {
		std::cout << "\nDeque operation not possible. No more elements. " << std::endl;
		exit(0);
	 }
	if(current->next==NULL)
	 {
		*head = NULL;
		delete current;
		return 1;
	 }
	 
	while(current->next!=NULL)
	 {
		prev = current;
		current = current->next;
	 } 	
	prev->next = NULL;
	delete current;
	return 1;
 }

void push_node(node **head)
 {
	node *NewNode = new node;
	
	input_data(&NewNode);
	NewNode->next = *head;
	*head = NewNode;
 }	

void input_data(node **current)
 {
	int temp;
	node *ptr = *current;
	std::cout << "\nEnter the data: ";
	std::cin >> temp;
	ptr->data = temp;
 }

void traverse(node *head)
 {
	node *current = head;
	std::cout << std::endl;
	while(current!=NULL)
	 {
		std::cout << "Data: " << current->data << std::endl;
		current = current->next;
	 }
 }

