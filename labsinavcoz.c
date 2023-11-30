#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  struct node{
        int employeeno;
        char name[10];
        struct node* next;
        struct node* prev;
    }node; 


struct node* insert1(struct node * head,int no,char name1[]){
    struct node* temp=(struct node*)malloc(sizeof(node));
    temp->employeeno=no;
    strcpy(temp->name,name1);
    if(head==NULL){
        temp->next=temp->prev=NULL;
        head=temp;
    }
    else{
        if(no<head->employeeno){
            head->prev=temp;
            temp->next=head;
            //***
        }
        else{
            struct node* last=head;
            while(last->next->employeeno<no && last->next!=NULL){
            last=last->next;
            if(last->next==NULL){
                last->next=temp;
                temp->prev=last;
                temp->next=NULL;
            }
            else{
                temp->next=last->next;
                last->next=temp;
                temp->next->prev=temp;
                temp->prev=last;
            }
        }
    }
 }
 return head;
}
int main(){
  struct node* list=NULL;
  int n;
  char name1[5];
  printf("");
  scanf("%d %s",&n,&name1);
    list=insert1(list,8,name1);
    printf("%d",list->employeeno);
    return 0;
}