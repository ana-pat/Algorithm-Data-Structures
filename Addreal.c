/*
Question: Write a program to add two large real numbers.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *newNode(int data, Node *next){
    Node *pnode = (Node *) calloc(1, sizeof(int));
    pnode->data = data;
    pnode->next = next;
    return pnode;
}

void printList(Node *list) {
    int index = 0;
    printf("%p -> ", list);
    while (list != NULL) {
        printf("(%p, %d, [%d], %p) -> ", list, list->data, index, list->next);
        list = list->next;
        index++;
    }
    printf("NULL\n");
}

void addFirst(Node **ppnode, int data) {
    Node *pnode = newNode(data, *ppnode);
    *ppnode = pnode;
}


/*
    l -> length
    dec -> decimal
    dec1 -> decimal number 1
    dec2 -> decimal number 2
    h1 -> head1
    h2 -> head2
    h3 -> head3
    t  -> temp
*/

int main(){
    int l = 0, count = 0, i, dec, dec1, dec2;
    Node *h1 = NULL;
    Node *h2 = NULL;
    Node *h3 = NULL;
    Node *t;
    char *c, *d;
    int a, b, carry = 0, sum;
    int toint;
    c = (char *)calloc(50, sizeof(char));
    d = (char *)calloc(50, sizeof(char));
    printf("Enter the value of first real number: ");
    scanf("%s",c);
    printf("Enter the value of second real number: ");
    scanf("%s",d);
    a = strlen(c);
    b = strlen(d);


    for(i = 0; i < a; i++){
          if(c[i] == '.'){
                 dec1 = a - (i + 1);
                 break;
          }
    }

    for(i = 0; i < b; i++){
          if(d[i] == '.'){
              dec2 = b - (i + 1);
              break;
          }
    }

    if(dec1 >= dec2){
          dec = dec1;
          for(i = b; i < b+(dec1 - dec2); i++){
               d[i] = '0';
          }
     }
     else{
          dec = dec2;
          for(i = a; i < a+(dec2 - dec1); i++){
              c[i] = '0';
          }
       }

    a = strlen(c);
    b = strlen(d);
    for(i=0; i<a; i++){
        if(c[i] != '.'){
          toint = c[i] - '0';
          addFirst(&h1, toint);
        }
    }

    for(i=0; i<b; i++){
        if(d[i] !='.'){
          toint = d[i] - '0';
          addFirst(&h2, toint);
        }
    }

    while(1){

        if(h2 && h1){
             sum = h1->data + h2->data + carry;
        }

        if(!h2 && h1){
             sum = h1->data + carry;
        }

        if(h2 && !h1){
             sum = h2->data + carry;
        }

        if(!h1 && !h2){

            if(carry == 0)
                break;
            else{
                addFirst(&h3, carry);
                break;
            }
        }
        addFirst(&h3, sum % 10);
        carry = sum / 10;
        if(h1)
        h1 = h1->next;
        if(h2)
        h2 = h2->next;
    }
    t = h3;
    printf("\nThe sum is as: ");
    while(t){
        t = t->next;
        l = l + 1;
    }

    while(h3){
        count = count + 1;
        if(count == (l - dec)){
            printf("%d.", h3->data);
        }
        else{
          printf("%d", h3->data);
        }
        h3 = h3->next;
    }
    return 0;
}
