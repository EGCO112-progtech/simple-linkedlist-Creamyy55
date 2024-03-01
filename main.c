//
//  main.c
//  simple linkedlist
//
//  Created by Mingmanas Sivaraksa on 4/2/2566 BE.
//

#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main(int argc, const char * argv[]) {
    int z=5;
    struct node a,b,*head ;
    a.value = z;
    a.next=&b;
    head=&a;
    b.value=head->value+3;
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    
/*  Exercise I
    1. Add 1 more than at the end
    2. Add value(11)
    3. Make next become NULL
 */
 struct node c;
 b.next=&c;
 c.value=11;
 c.next=NULL;
printf("%d\n", head->next->next->value );
    
/*  Exercise II
        1. Add 1 more than at the begining!!!!
        2. Add value (2)
        
*/
    struct node d;
    d.next=&a;
    d.value=2;
    head=&d;
    printf("%d\n", head ->value ); //what value for 5
    printf("%d\n", head ->next->value ); //what value for 8
    printf("%d\n", head ->next->next->value );
    printf("%d\n", head ->next->next->next->value );

    typedef struct node* Nodeptr;
    Nodeptr temp=head; //add temp value to faciliate
        
    //Exercise III Use loop to print everything
        int i,n=4;
        for(i=0;i<n;i++)
        {
            printf("%3d", temp->value);
          temp=temp->next;
        }
        printf("\n");
    
    
   //Exercise IV change to while loop!! (you can use NULL to help)
       
         while(temp!=NULL)
        {
            printf("%3d", temp->value);
            temp=temp->next;
        }
    
    
 /*  Exercise V Use malloc to create all nodes, instead of create a struct!!
         //use a loop to help  */
        head=(Nodeptr) malloc(sizeof(struct node));
        temp=head;

        for(i=2;i<=11;i+=3){ //2 5 8 11
        temp->value=i;
        if(i==11) temp->next=NULL;//ป้องกันการสร้างnodeเกิน
        else{
        temp->next=(Nodeptr) malloc(sizeof(struct node));}
        printf("%3d",temp->value);
        temp=temp->next;    }
        
        printf("\n");

        /* No loop version
        tmp->value=2;
        tmp->next=(Nodeptr) malloc(sizeof(struct node));

        tmp=tmp->next;
        tmp->value=5;
        tmp->next=(Nodeptr) malloc(sizeof(struct node));

        tmp=tmp->next;
        temp->value=8;
        tmp->next=(Nodeptr) malloc(sizeof(struct node));

        tmp=tmp->next;
        tmp->value=5;
        tmp->next=NULL;*/




    /*  Exercise VI Free all node !!
         //use a loop to help   
     */
     temp=head;
     while(head){
        temp=head;
        head=head->next;
        printf("%3d",temp->value);
        free(temp);
     }
     printf("\n");
    
    return 0;
}
