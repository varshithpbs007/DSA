/*Stack implementation using static array*/

#include <stdio.h>
#include <stdlib.h>
#define CAPACITY 5 //Pre-processor macro
int stack[CAPACITY], top = -1; //global variables

/* Prototype of the functions other than  void main()*/
void Push(int ele);
int Pop(void);
void Peek(void);
void Traverse(void);
int isFull(void);
int isEmpty(void);
//Prototypes end

void main() //main function
{
    while(1)
    {
        int ch, item; //ch = choice of user
        printf("Available operations to choose on created stack :- \n");
        printf("1.Push \n");
        printf("2.Pop \n");
        printf("3.Peek \n");
        printf("4.Traverse \n");
        printf("5.Quit \n");
        
        printf("Enter your choice : ");
        scanf("%d",&ch);
        
        switch(ch) // switch case used to execute respective method based on choice entered by the user
        {
            case 1 : printf("Enter item to push: ");
                     scanf("%d",&item);
                     Push(item); 
                     break;
            case 2 : item = Pop(); //returns and removes the top element
                     if (item == 0)
                     {
                         printf("Stack is Underflow (Stack is empty) \n");
                     }
                     else
                     {
                         printf("Popped item is : %d \n", item);
                     }
                     break;
            case 3 : Peek(); //only prints the top element and doesnt remove
                     break;
                    
            case 4 : Traverse(); //Prints and displays all elements of stack on screen
                     break;
            case 5 : exit(0);
                     break;
           default : printf("Invalid input choice :( \n\n");
        }
    
    
    }
    
}

void Push(int ele)
{
    if (isFull())
    {
        printf("Stack Overflow (Stack is full) \n");
    }
    else
    {
        top++ ;
        stack[top] = ele;
        printf("%d Pushed on top of stack \n", ele);
    }
}

int isFull()
{
    if(top == CAPACITY-1)
    {
        return 1;
    }
    else
    {
        return 0;   
    }
}

int Pop()
{
    if(isEmpty())
    {
        printf("Stack is Underflow (Stack is Empty) and garbage value returned \n ");
        return -9999; // Here we didnot use return 0 because if 0 is the value that was there, we wouldnot know its a stack value or the stack is empty
    }
    else
    {
        return stack[top--]; //As we have used post decrement it decrements top after stack[top] is returned to the caller
    }
}

int isEmpty()
{
    if(top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Peek()
{
    if(isEmpty())
    {
        printf("Stack is Underflow (Stack is Empty) \n");
    }
    else
    {
        printf("Peek element is : %d \n",stack[top]);
    }
}

void Traverse()
{
    if(isEmpty())
    {
        printf("Stack is Underflow (Stack is Empty) \n");
    }
    else
    {
         printf("Elements of stack from bottom to top are :- \n");
         int i;
         for(i = 0; i <= top; i++)
         {
             printf("%d \n", stack[i]);
         }
    }
}
