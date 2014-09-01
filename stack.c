#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<termios.h>

#define CHUNK 10

static struct termios old, new;

struct stack
  {
	  char *process_name;
	  char *pid;
	  struct stack *next;
  };

void input_data(struct stack **);
void push_node(struct stack **);
void pop_node(struct stack **);
void traverse(struct stack*);
char *getln();
char getch_(int);
char getche();
  
int main(void)
  {
	  char choice = '1';
	  struct stack *head = malloc(sizeof(struct stack));
	  head->next = NULL;
	  input_data(&head);
	  while(1)
	    {
			printf("\n\n1. Push\n2. Pop\n3. Traverse\n4. Exit\nInput option:");
			choice = getche();
			switch(choice)
			  {
				  case '1':
				     push_node(&head);
				     break;
				     
				  case '2':
				     pop_node(&head);
				     break;
				     
				  case '3':
				     traverse(head);
				     break;
				     
				  case '4':
				     return 0;
				     break;
				     
			      default:
			         return 0;
			         break;
              }
        }
      return 0;
  }


//this function performs the pop operation on the top of the stack
void pop_node(struct stack **head)
  {
	  struct stack *current = *head;
	  if(*head==NULL)
	    {
			printf("\n\n\tStack Underflow!! No more values to pop.\n\n");
			exit(0);
		}	
	  printf("\n\n\tProcess name: %s\n", current->process_name);
	  printf("\n\tProcess id(pid): %s\n", current->pid);
	  *head = current->next;
	  free(current);
  }
  
//the function traverse the nodes present in the given stack
void traverse(struct stack *head)
  {
	  struct stack *current = head;
	  while(current!=NULL)
	    {
			printf("\n\n\n\tProcess name: %s\n", current->process_name);
			printf("\n\tProcess id(pid): %s\n", current->pid);
			current = current->next;
	    }
  }
  
//the function performs the push operation on the top of the stack 
void push_node(struct stack **head)
  {
	  struct stack *NewNode = malloc(sizeof(struct stack));
	  
	  input_data(&NewNode);
	  NewNode->next = *head;
	  *head = NewNode;
  }
  
void input_data(struct stack **current)
  {
	  struct stack *ptr = *current;
	  char *temp;
	  printf("\n\nEnter the process name: ");
	  temp = getln();
	  ptr->process_name = temp;
	  temp = NULL;
	  printf("\nEnter process id(pid): ");
	  temp = getln();
	  ptr->pid = temp;
	  temp = NULL;
  }
	

//the function allocates the memory according to the user's input	  
char *getln()
  {
	  char *line = NULL, *tmp = NULL;
	  size_t size = 0, index = 0;
	  int ch = EOF;
	  
	  while(ch)
	    {
			ch = getc(stdin);
			
			if(ch == EOF || ch == '\n')
			   ch = 0;
			
			if(size<=index)
			  {
				  size += CHUNK;
				  tmp = realloc(line, size);
				  if (!tmp) 
				    {
						free(line);
						line = NULL;
						break;
                    }  
              
                  line = tmp;
              }
            line[index++] = ch;
        }
      return line;
      
  }

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char getche(void) 
{
  return getch_(1);
}
