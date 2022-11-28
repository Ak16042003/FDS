#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
struct node{
    char name[20];
    int prn;
    struct node* next;
    struct node* prev; 
}*head;
void insertpresident(struct node* head){
    struct node*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter name of new president:\n");
    scanf("%s",newnode->name);
    printf("enter prn of new president:\n");
    scanf("%d",&newnode->prn);
    newnode->next=head;
    newnode->prev=NULL;
    head=newnode;
}

void insertsecretary(struct node* head){
    struct node* newnode,*temp;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the name of new secretary:\n");
    scanf("%s",newnode->name);
    printf("enter the prn of new secretary:\n ");
    scanf("%d",&newnode->prn);
    newnode->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
}

void createsecretary(){
    struct node *new;
    new= (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the name and PRN of Secretary : \n");
    scanf(" %s%d",new->name,&new->prn);
    new->next=NULL;
    new->prev=NULL;
    new->prev=head;
    head->next=new;
}

void createpresident(){
    head=(struct node*)malloc(sizeof(struct node));
    printf("enter the name (President): \n");
    fflush(stdin);
    scanf("%s",head->name);
    printf("enter PRN (President):");
    fflush(stdin);
    scanf("%d",&head->prn);
    head->next=NULL;
    head->prev=NULL;
}

void deletepresident(struct node* head){
    struct node* temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    temp=head;
    head=head->next;
    free(temp);
    insertpresident(head);
}

void deletesecretary(struct node* head){
    struct node* temp, *back;
    temp=head;
    back=head;
    while(temp->next!=NULL){
        back=temp;
        temp=temp->next;
    }
    back->next=temp->next;
    free(temp);
    printf("\nThe secretary has been deleted..\n");
    insertsecretary(head);
}

void delete_mem(){
    printf("Enter the name of a member to delete : ");
    char mem_name[20];
    scanf(" %s",mem_name);
    struct node* temp,*back;
    temp=head->next;
    back=head;
    while((strcmp(temp->name,mem_name)) && temp->next!=NULL){
        back=temp;
        temp=temp->next;
    }
    if(temp->next==NULL){
        printf("Member is not in the list..\n");
    }
    else{
        back->next=temp->next;
        free(temp);
        printf("The selected member has been deleted..\n");
    }
}
void count_mem(){
    struct node*temp;
    int count=0;
    temp=head->next;
    while(temp->next!=NULL){
        temp=temp->next;
        count++;
    }
    printf("Total members are %d\n",count);
}
void reverse(){
    struct node*temp,*swap;
    temp=head;
    while(temp!=NULL){
        swap=temp->prev;
        temp->prev=temp->next;
        temp->next=swap;
        if(temp->prev==NULL){
            head=temp;
        }
        temp=temp->prev;
    }
    printf("The members list has been reversed..\n");
    
}
void display(struct node*  head){
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        printf("name: %s\tPRN:%d\n",temp->name,temp->prn);
        temp=temp->next;
    }
}
void insertmem(struct node* head){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the name and prn of MEMBER:\n");
    scanf(" %s",newnode->name);
    scanf("%d",&newnode->prn);
    newnode->next=head->next;
    head->next=newnode;
    newnode->prev=head;
    newnode->next->prev=newnode;
}


void main(){
    int ch;
    createpresident();
    createsecretary();
    aa: 
        printf("\n1:Insert a member\n2:Delete a member\n3:Delete President\n4:Delete Seretary\n5:Count members\n6:Reverse member's list of club\n7:Display list of members\n\nSelect an option to perform : ");
        scanf("%d",&ch);
            switch(ch){
                case 1:
                    insertmem(head);
                    break;
                
                case 2:
                    delete_mem();
                    break;
                
                case 3:
                    deletepresident(head);
                    break;
                
                case 4:
                    deletesecretary(head);
                    break;
                case 5:
                    count_mem();
                    break;
                case 6:  
                    reverse();
                    break;
                case 7:
                    display(head);
                    break;      
            }
            printf("\nDo you to perform it again (Y/N) : ");
    char q;
    scanf(" %c",&q);
    if(q=='y'||q=='Y'){
        goto aa;
    }
}