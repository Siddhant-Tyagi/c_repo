#include<stdio.h>
#include<stdlib.h>

struct node
  {
	  int data;
	  struct node *next;
  };

void traverse(struct node *);  
int list_count(struct node *);
void push_node(struct node **, int);
void delete_first_node(struct node **);
void input_data(struct node **);

int main(void)
  {
	struct node *head=NULL, *second=NULL, *third=NULL;
	int count, popped_value;
	
	head = malloc(sizeof(struct node));
	input_data(&head);
        second = malloc(sizeof(struct node));
        third = malloc(sizeof(struct node));
	
	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;
	
	third->data = 3;
	third->next = NULL;
	
	push_node(&head, 24);
	push_node(&head, 30);
	traverse(head);
	
	count = list_count(head);
	printf("\n\nCount before deletion:%d\n", count);
        delete_first_node(&head);
	//printf("\nPopped value:%d", popped_value);
	count = list_count(head);
	printf("Count after deletion of first node:%d\n\n", count);
	return 0;
  }

void delete_first_node(struct node **head)
  {
	  struct node *ptr = *head;
	  int data = ptr->data;
	  *head = ptr->next;
	  free(ptr);
	  //return data;
  }

void push_node(struct node **head, int data)
  {
	  struct node *NewNode = malloc(sizeof(struct node));
	  
	  NewNode->data = data;
	  NewNode->next = *head;
	  *head = NewNode;
  }
	  

void traverse(struct node *current)
  {
	  while(current != NULL)
	    {
		printf("\nData: %d", current->data);
		current = current->next;
	    }
  }

void input_data(struct node **current)
  {
	  struct node *ptr = *current;
	  ptr->data = 29;
   }
  
int list_count(struct node * head)
  {
	  struct node *ptr = head;
	  int count = 0;
	  while(ptr!=NULL)
	    {
	        count++;
	        ptr=ptr->next;
	    }
	  return count;
  }

