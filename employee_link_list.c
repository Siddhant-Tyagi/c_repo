#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<termios.h>

#define CHUNK 10

static struct termios old, new;


struct employee
  {
	  char *name;
	  char *dept;
	  char *dob;
	  int empid;
	  struct employee *next;
  };

void push_node(struct employee **);
void input_data(struct employee **);
char *getln();
char getch_(int);
char getche();

int main(void)
  {
	  char choice = 'y';
	  int len;
	  struct employee *head = malloc(sizeof(struct employee));
	  head->next = NULL;
	  input_data(&head);
	  printf("\nDo you wish to add another employee? Y or N ");
	  choice = getche();

	  while(choice=='y' || choice=='Y')
	    {
			push_node(&head);
			printf("\nDo you wish to add another employee? Y or N ");
			choice = getche();
		}

	  struct employee *current = head;
	  while(current != NULL)
	    {
			printf("\n\nName:%s", current->name);
			printf("\nDept:%s", current->dept);
			printf("\nDOB:%s", current->dob);
			printf("\nEmpid:%d\n", current->empid);
			current = current->next;
		}
			
	  return 0;
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

void push_node(struct employee **head)
  {
	  struct employee *NewNode = malloc(sizeof(struct employee));
	  
	  input_data(&NewNode);
	  NewNode->next = *head;
	  *head = NewNode;
  }

void input_data(struct employee **current)
  {
	  //struct employee *ptr = *current;
	  
	  struct employee *ptr = *current;
	  char *temp;
	  printf("\n\nEnter name: ");
	  temp = (char *)getln();
	  ptr->name = temp;
	  temp = NULL;
	  printf("\nEnter dept: ");
	  temp = (char *)getln();
	  ptr->dept = temp;
	  temp = NULL;
	  printf("\nEnter dob: ");
	  temp = (char *)getln();
	  ptr->dob = temp;
	  temp = NULL;
	  printf("\nEnter empid: ");
	  temp = (char *)getln();
	  ptr->empid = atoi(temp);
	  
  }
  
char *getln()
  {
    char *line = NULL, *tmp = NULL;
    size_t size = 0, index = 0;
    int ch = EOF;

    while (ch) {
        ch = getc(stdin);

        /* Check if we need to stop. */
        if (ch == EOF || ch == '\n')
            ch = 0;

        /* Check if we need to expand. */
        if (size <= index) {
            size += CHUNK;
            tmp = realloc(line, size);
            if (!tmp) {
                free(line);
                line = NULL;
                break;
            }
            line = tmp;
        }

        /* Actually store the thing. */
        line[index++] = ch;
    }

    return line;
  }
