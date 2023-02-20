#include<stdio.h>
#include<stdlib.h>
struct node{
        char name[10], USN[20], dep[10], phone[20];
        int marks1, marks2, marks3;
        struct node*next;
        struct node*prev;
}*head, *newnode, *tail;


void getnode(){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter student data \n");
        printf("NAME: \n");
        scanf("%s",&newnode->name);
        printf("USN: \n");
        scanf("%s",&newnode->USN);
        printf("Department: \n");
        scanf("%s",&newnode->dep);
        printf("Phone Number: \n");
        scanf("%s",&newnode->phone);
        printf("MARKS: \n");
        scanf("%d%d%d",&newnode->marks1,&newnode->marks2,&newnode->marks3);
        newnode->prev=NULL;
        newnode->next=NULL;
}

void create(){
        int n;
        printf("\nEnter the number of students: \n");
        scanf("%d",&n);
        head=NULL;
        struct node*temp;
        int i=0;
        while(i<n){
                getnode();
                if(head==NULL){
                        head=temp=newnode;
                        tail=newnode;
                }
                else{
                        temp->next=newnode;
                        newnode->prev=temp;
                        temp=tail=newnode;           
                }
                i++;
        }
}

void display(){
        int count=0;
        struct node*ptr=NULL;
        float average;
        if(head==NULL)
                printf("\nEmpty\n");

        else{
                ptr=head;
                while(ptr!=NULL){
                        printf("NAME: %s\n",ptr->name);
                        printf("USN: %s\n",ptr->USN);
                        printf("Department: %s\n",ptr->dep);
                        printf("Phone Number: %s\n",ptr->phone);
                        printf("Mark1: %d\tMark2: %d\tMark3:%d\n",ptr->marks1,ptr->marks2,ptr->marks3);
                        printf("\nAverage of these 3 Marks\t");
                        average=((ptr->marks1+ptr->marks2+ptr->marks3)/3);
                        printf("%f\n",average);
                        count++;
                        ptr=ptr->next;
                }
                printf("\nNumber of students %d\n",count);
        }
}

void insert_at_front(){
        printf("\nInsert at front\n");
        getnode();
        head->prev=newnode;
        newnode->next=head;
        head=newnode;
}

void delete_at_front(){
        printf("\nDeleted at the front\n");
        struct node*temp;
        temp=head;
        if(head==NULL)
                printf("\nNo data\n");
        else if(temp->next==NULL){
                head=NULL;
                free(temp);
        }
        else {
                head->next->prev=NULL;
                head=head->next;
                temp->next=NULL;
                free(temp);
        }
}

void insert_at_end(){
        struct node*temp;
        printf("\nInserting at the end\n");
        getnode();
        if(head==NULL){
                        head=temp=newnode;
                        tail=newnode;
                }
        else{
                tail->next=newnode;
                newnode->prev=tail;
                tail=newnode;
        }
        /*newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;*/
}

void delete_at_end(){
        printf("\nDeleted at the end\n");
        struct node*p,*q;
        p=head;
        if(head==NULL) 
                printf("\nNO ELEMENT\n");
        else if(p->next==NULL){
                head=NULL;
                free(p);
        }
        else{
                while(p->next!=NULL){
                        p=p->next;
                }
                q=p->prev;
                q->next=NULL;
                tail = p->prev;
                tail->next = NULL;
                free(p);
        }       
}

void main(){
        int choice,i,cont;
        do{
                printf("1. Create\n2. Display\n3. To Insert at the front\n4. Delete at front\n5. Insert at the end\n6. Delete at the end\n");
                printf("\nEnter your choice: \n");
                scanf("%d",&choice);

                switch(choice){
                        case 1:
                                create();
                                printf("Created\n");
                                break;
                        case 2:
                                display();
                                printf("Displayed\n");
                                break;
                        case 3:
                                insert_at_front();
                                printf("Inserted at the front\n");
                                break;
                        case 4:
                                delete_at_front();
                                printf("Deleted at the front\n");
                                break;
                        case 5:
                                insert_at_end();
                                printf("Inserted at the end\n");
                                break;
                        case 6:
                                delete_at_end();
                                printf("Deleted at the end\n");
                                break;
                        case 7:
                                exit(0);
                }
                printf("press '1' to continue or '0' to exit\n");
                scanf("%d",&cont);
        }
        while(cont);
 }
