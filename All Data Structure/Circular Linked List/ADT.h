#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node *h, int data){
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    if(h->next == NULL){
        temp->next = h;
        h->next = temp;
    }
    else {
        temp->next = h->next;
        h->next = temp;
    }
}

int length(struct node *h){
    struct node *ptr;
    ptr = h->next;
    int len =0;
    while (ptr != h)   
    {
        len++;
        ptr = ptr->next;
    }
    return len;
}

void add(struct node *h, int data)
{
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    if(h->next == NULL){
        temp->next = h;
        h->next = temp;
        return ;
    }
	struct node *ptr;
    ptr = h->next;
    for(int i =0; i<length(h)-1; i++){
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

void display(struct node *h){
    struct node *ptr;
    ptr = h->next;
    while (ptr != h)   
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void delete(struct node *h){
    struct node *temp = h->next;
    h->next = h->next->next;
    free(temp);
}

void sortL(struct node *head){
	int i=0, j=0, len = length(head);
	struct node *temp1=head->next, *temp = head->next;
	for(i=0; i<len; i++){
		for(j=0; j<len; j++){
			if(temp1->data < temp->data){
				int T = temp1->data;
				temp1->data = temp->data;
				temp->data = T;
			}
			temp = temp->next;
		}
		temp1 = temp1->next;
		temp = head->next;
	}
}