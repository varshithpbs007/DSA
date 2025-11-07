/* Singly Linked List Implementation in C */
/*Including the necessary header files*/
#include<stdio.h> // contains printf() and scanf()
#include<stdlib.h> //contains malloc()

/* Globally struct data type node is created which is  accessed by all methods */
struct node
{
    int data;
    struct node *link;
};

struct node *root = NULL;//global variable is by default initiated with NULL
int len;//global variable to save the length of linked list

/* Function prototypes */
/*1*/ void append(void);
/*2*/ void addatbegin(void);
/*3*/ void addafter(void);
/*4*/ int length(void);
/*5*/ void display_list(void);
/*6*/ void delete_node(void);

/*main() function from where the execution is started*/
void main()
{
    int choice;//local variable to main() to read the user's choice into
    while(1)
    {
        printf("Single Liked List Operations:\n");
        printf("1. Append\n");
        printf("2. Add at begin\n");
        printf("3. Add after\n");
        printf("4. Length\n");
        printf("5. Display list\n");
        printf("6. Delete\n");
        printf("7. Quit\n");
        
        printf("Enter your choice of operation:\n");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1 : append();
                     break;
            case 2 : addatbegin();
                     break;
            case 3 : addafter();
                     break;
            case 4 : len = length();
                     printf("Length of list is %d nodes\n",len);
                     break;
            case 5 : display_list();
                     break;
            case 6 : delete_node();
                     break;
            case 7 : exit(1);
            default : printf("Invalid choice number\n");
        }
        
    }
}

/* Writing method defenitions for all the choices */

//1. Append (adding a node at the last)
void append()
{
    struct node *temp; //local varible --> gets automatically deleted after every call
    temp = (struct node*)malloc(sizeof(struct node)); //creation of a node and saving its base address in temp
    printf("Enter node data : \n");//asking the user what data to read
    scanf("%d", &temp -> data);//reading the user entered data into data field pointed by temp
    temp -> link = NULL;//always keep the newly created link field NULL initially
    
    if(root == NULL) //if list is empty is checked
    {
        root = temp;//list empty means the created node is 1st node and root should point where temp is pointing
    }
    else
    {
        struct node *p;//local variable created to perform traversal to check which link is NULL so that we can append the new node there
        p = root;//root is passed and further temporary ops are done on p
        while(p -> link != NULL)
        {
            p = p -> link; //p gets the link address to point to next node and again check in the loop that link is NULL or not till last position
        }
        p -> link = temp; //this line appends the node at last position
    }
}

//2. Add at begin
void addatbegin(void)
{
    
}

//3, Add after
void addafter(void)
{
    
}

//4. Length of list
int length()
{
    int count = 0;
    struct node *temp;
    temp = root;
    
    while(temp != NULL)
    {
        count++;
        temp = temp -> link;
    }
    return count;
    
}

//5. Displaying all the elements in the list
void display_list()
{
    struct node *temp;
    temp = root;
    if(temp == NULL)
    {
         printf("No elements in the list\n\n");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d -->",temp -> data);
            temp = temp -> link;
        }
        printf("\n\n");
    }
   
}

//6. Delete a node from list
void delete_node(void)
{
    
}

