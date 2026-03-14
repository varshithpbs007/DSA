/* Implementation of Single Linked List in C */

#include<stdio.h> // This library contains standard input (scanf()), and output (printf()) functions
#include<stdlib.h> // This library contains malloc() function

// Functions prototypes other than main()
void append(void); // 1
void addatbeginning(void); // 2
void addafter(void); // 3
int length(void); // 4
void display(void); // 5
void deletenode(void); // 6

struct node // Global struct type variable(user defined) named node , accessed by all the functions
{ 
    int data;
    struct node* link;
};

struct node *root = NULL; // Global varibales (here root) are by default initialized with 0, even when un-innitialised
int len; // Global varibales are by default initialized with 0

// Custom functions to achieve linked list operations

// 1
void append()
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter data to save in node:\n");
    scanf("%d",&temp->data);
    temp->link = NULL;
    // till now node is created and temp is pointing to created node

    if(root == NULL) // i.e., the list is empty
    {
        root = temp; // assigning temp contents to root so that the root points to created node
    }
    else
    {
        struct node* p;
        p = root;
        while(p->link != NULL)
        {
            p = p->link;
        }
        p->link = temp; // this line appends the new node at the end of the list
    
    }
    
}


//2
void addatbeginning(void)
{
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));

    printf("Enter node data:\n");
    scanf("%d",&temp->data);
    temp->link = NULL;

    if(root == NULL)
    {
        printf("List is EMPTY\n");
    }
    else
    {
        temp->link = root;
        root = temp;
    }

}


//3
void addafter(void)
{
    struct node* p;
    struct node* temp;
    int loc;
    int len = length();
    int i = 1;
    
    printf("Enter location to add node\n");
    scanf("%d",&loc);

    if(loc > len)
    {
        printf("INVALID LOCATION\n");
    }
    else
    {
        p = root;
        while(i < loc)
        {
            p = p->link;
            i++;
        }

        temp = (struct node*)malloc(sizeof(struct node));
        printf("Enter new node data:\n");
        scanf("%d",&temp->data);
        temp->link = NULL;

        temp->link = p->link;
        p->link = temp;
    }
}


//4
int length(void)
{
    int count = 0;
    struct node* temp;
    temp = root;

    while(temp != NULL)
    {
        count++;
        temp = temp->link;
    }

    return count;

}


//5
void display(void)
{
    struct node* temp;
    temp = root;

    if(temp == NULL)
    {
        printf("List is EMPTY");
    }
    else
    {
        while(temp != NULL)
        {
            printf("%d->",temp->data);
            temp = temp->link;
        }

        printf("\n\n");
    }

}

//6
void deletenode(void)
{
    struct node* temp;
    int loc;
    int len = length();

    printf("Enter node location to delete:\n");
    scanf("%d",&loc);

    if(loc > len)
    {
        printf("Location is INVALID\n");
    }
    else if (loc == 1)
    {
        temp = root;
        root = temp->link;
        temp->link = NULL;
        free(temp);
    }
    else
    {
        struct node* p = root;
        struct node* q;
        int i =1;
        while(i < loc-1)
        {
            p = p->link;
            i++;
        }
        q = p->link;

        p->link = q->link;
        q->link = NULL;
        
        free(q);
    }
}


//-------------------------------------------------main function--------------------------------------------------
void  main()
{
    int choice; // local variable as it is only used by main() function
    while(1)
    {
        printf("Choose from the below available Single Linked List Operations:\n");

        printf("1.Append (Addatend)\n");
        printf("2.Addatbeginning\n");
        printf("3.Addafter\n");
        printf("4.length\n");
        printf("5.Display\n");
        printf("6.Deletenode\n");
        printf("7.Quit\n");

        printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: append();
                    break;
            case 2: addatbeginning();
                    break;
            case 3: addafter();
                    break;
            case 4: len = length();
                    printf("Length of Linked list is %d\n",len);
                    break;
            case 5: display();
                    break;
            case 6: deletenode();
                    break;
            case 7: exit(1);

            default: printf("INVALID choice\n");
        }
    }


}




