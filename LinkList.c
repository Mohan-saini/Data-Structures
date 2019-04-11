#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
/***************************         Structure                   ***********************/
typedef struct link
{
    int data;
    struct link* next;
}link;
/****************************         Insert data to list           ************************/
link* insert(link* start,int d)
{
    link* s=start;                           //for traversing list
    link* s1=NULL;                           //track previous node
    link* temp=(link*)malloc(sizeof(link));  //create new node
    temp->data=d;
    temp->next=NULL;
    if(start==NULL){                         //base case
        start=temp;
    }
    else if(start->data > d)                 //insert node at begin
    {
        temp->next=start;
        start=temp;
    }
    else{
        while(s->next != NULL && s->data <= d){   //traverse list until we got location
            s1=s;                                 //for tracking previous node
            s=s->next;                            //next node
        }
        if(s->data<=d && s->next==NULL){         //insert at last
            s->next=temp;
        }
        else if(s->data > d && s->next==NULL){   //insert at second last position
            temp->next=s;
            s1->next=temp;
        }else                                     //insert somewhere in the middle
        {
            temp->next=s;
            s1->next=temp;
        }
    }
    return(start);
}
/**************                 print the list                     ********************/
void print_list(link* p)
{
    while(p != NULL)
    {
        printf("%2d  ",p->data);
        p=p->next;
    }
}
/**************                delete a value from list             ******************/
link* delete_v(link* start,int v)
{
    if(start==NULL)return(start);              // not a single node exists
    link* s=start;                             //for traversing the list
    link* s1=NULL;                             //to track previous node
    if(v<start->data){                         //since list is sorted, if v is less then first node means it doesn't exist.
        printf("Data not exist!!\n");
        return(start);
    }
    if(start->data==v && start->next==NULL){   //if single node is in list and this is to be deleted
        start=NULL;
    }
    else if(start->data == v){                 //if first node is to be deleted but there are more nodes in the list.
        start=start->next;
    }
    else
    {
        while(s->data != v && s->next != NULL){       //traverse the list until we get the data
            s1=s;
            s=s->next;
        }
        if(s->next==NULL && s->data != v){           //we have traversed the list but didn't get data
            printf("data doesn't exist!!\n");
            return(start);
        }
        s1->next=s->next;                            //we got the location, just put next node location to next pointer of previous node.
    }
    return(start);
}
/////////////////////////////////////    Main Function ///////////////////////////////////////////////////
int main()
{
    link* start=NULL;
    printf("Enter numbers\n");
    int c;
    scanf("%d",&c);                      //it will take until you enter -1.
    while(c!=-1){
        start=insert(start,c);
        scanf("%d",&c);
    }
    printf("List is: ");
    print_list(start);
    printf("\nEnter the value to delete: ");
    scanf("%d",&c);
    start=delete_v(start,c);
    printf("List is: ");
    print_list(start);
}
