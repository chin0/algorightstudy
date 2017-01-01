#include <stdio.h>
#include <stdlib.h>
typedef struct _node{
	int data;
	struct _node* next;
}node;

node* HEAD=NULL;

node* newnode(int data){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->data = data;
	return newnode;
}

void newhogang(int data){
	if(HEAD == NULL)
		HEAD=newnode(data);
	else{
		node* temp = HEAD;
		while(temp->next != NULL)
		   temp = temp->next;
	   temp->next = newnode(data);
	}
}

int pophogang(){

	if(HEAD==NULL){
		return -1;
	}
	else{
		int ret=HEAD->data;
		HEAD = HEAD->next;
		return ret;
	}
}
void printAllNode(node* head){
	if(head == NULL)
		return;
	printAllNode(head->next);

	printf("[%d]\n",head->data);
}
int remainNode(node *head){
	int count=0;
	node *temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}
int main(void){
	int select = 0;
	int ret;
	while(1){
		printf("input number: ");
		scanf("%d",&select);
		if(select == 0){
			ret = pophogang();
			if(ret == -1)
				printf("list is empty.\n");
			else
				printf("[%d]\n",ret);	
		}
		else if (select == -1){
			printAllNode(HEAD);
			break;
		} else if(select == -2){
			printf("%d\n",remainNode(HEAD));
		}
		else{
			newhogang(select);
		}
	}
	return 0;
}
