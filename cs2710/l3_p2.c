#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct num{
    int a;
   struct num* next;
};/*one integer datatype is defined*/
int main() {
    long int sum(head);
    struct num* temp;
    struct num* head;
    struct num* tail;
    int k=0;
    int i=1;
    struct num* rev(struct num* head);
    while(scanf("%d",&k)!=EOF){
        temp=(struct num*)malloc(sizeof(struct num));/*space is allocated for defined data type once in each loop*/
        temp->a=k;
        temp->next=NULL;
        if(i==1){head=temp;
               tail=temp;}
        else{tail->next=temp;
            tail=tail->next;}
        i++;
    }
    printf("%ld\n",sum(head));/*printing the sum of all input integers*/
    temp=rev(head);
    while(temp!=NULL){printf("%d ",temp->a);
                          temp=temp->next;}/*printing the reverse linked list*/
    return 0;
}
long int sum(struct num* head)
{
    long int Sum=0;
    while(head!=NULL){Sum=Sum+head->a;
                     head=head->next;}
    return Sum;
}/*function sum is defined to find sum of all input integers*/
struct num* rev(struct num* head)
{
    struct num* temp1;
    struct num* temp2;
    struct num* temp3;
    temp1=head;
    temp2=temp1->next;
    temp3=temp2->next;
    while(temp3->next!=NULL){
        temp2->next=temp1;
        temp1=temp2;
        temp2=temp3;
        temp3=temp3->next;
    }
    temp2->next=temp1;
    temp3->next=temp2;
    head->next=NULL;
    return temp3;
}/*function rev is defined to reverse the links in the linked list*/
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    
