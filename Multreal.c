/*
Question: Write a program to multiply two large real numbers.
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
void reverseList(Node **ppnode) {
    Node *pprev = NULL, *pcurrent = *ppnode, *pnext = NULL;
    while (pcurrent) {
        pnext = pcurrent->next;
        pcurrent->next = pprev;
        pprev = pcurrent;
        pcurrent = pnext;
    }
    *ppnode = pprev;
}

void addFirst(Node **ppnode, int data) {
    Node *pnode = newNode(data, *ppnode);
    *ppnode = pnode;
}

void addLast(Node **ppnode, int data) {
    if (*ppnode == NULL) {
        addFirst(ppnode, data);
        return;
    }
    Node *pnode = *ppnode;
    while (pnode->next != NULL) {
        pnode = pnode->next;
    }
    pnode->next = newNode(data, NULL);
}


int main(){
    int dec1=0, dec2=0, dec3 =0, dec, i, count=0, l=0;
    Node *h1 = NULL;
    Node *h2 = NULL;
    Node *h3 = NULL;
    Node *temp3;
    Node *temp3a;
    Node *temp2;
    Node *temp1;
    Node *trial;
    Node *trial1;
    Node *temp;

    char *c;char *d;
    int a, b, carry = 0, carry1 = 0,  mul, toint;
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

    dec = dec1 + dec2;

    a = strlen(c);
    b = strlen(d);
    for(i=0; i<a; i++){
        if(c[i] != '.'){
          toint = c[i] - '0';
          addFirst(&h1, toint);
        }
    }
    temp1 = h1;

    for(i=0; i<b; i++){
        if(d[i] !='.'){
          toint = d[i] - '0';
          addFirst(&h2, toint);
        }
    }
    temp2 = h2;
    addLast(&h3, 0);
    temp3 = h3;
    temp3a = temp3;
    while(temp2){
        temp3 = temp3a;
        temp1 = h1;
        while(temp1){

            mul = temp2->data * temp1->data + carry;
            carry = mul / 10;
            temp3->data += (mul % 10) + carry1;
            carry1 = temp3->data /10;
            temp3->data = (temp3->data)%10;
            if(temp3->next == NULL){
                addLast(&h3, 0);
            }
            temp3 = temp3->next;
            temp1 = temp1->next;

        }
        if(carry != 0){
            temp3->data = carry;
        }
        temp3a = temp3a->next;
        carry = 0;
        carry1 = 0;
        temp2 = temp2->next;
    }

    trial = h3;
    trial1 = h3;
    while(trial){
        if(trial->next == NULL){
                if(trial->data == 0){
                    trial1->next = NULL;
                    break;
                }
        }
        trial1 = trial;
        trial = trial->next;
    }

    printf("\nThe Multiplication is: ");
    reverseList(&h3);
    temp = h3;
    while(temp){
        temp = temp->next;
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
