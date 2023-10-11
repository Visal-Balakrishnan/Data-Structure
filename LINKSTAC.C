#include<stdio.h>
#include<conio.h>
struct node{
	int data;
	struct node *next;
};
struct node *head=NULL,*newnode,*temp;
void push(){
	int data;
	printf("enter data\n");
	scanf("%d",&data);
	newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=NULL;
	if(head==NULL)
		head=newnode;
	else{
		newnode->next=head;
		head=newnode;
	}
	return;
}
void pop(){
	if(head==NULL)
		printf("stack overflow\n");
	else{
		temp=head;
		if(temp->next==NULL){
			head=NULL;
			free(temp);
			return;
		}
		head=temp->next;
		printf("%d poped",temp->data);
		free(temp);
	}
	return;
}
void display(){
	if(head==NULL)
		printf("empty stack \n");
	else{
	temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("NULL");
	}

}
void search(){
	int item,i=0,c=0;
	printf("enter item\n");
	scanf("%d",&item);
	temp=head;
	while(temp!=NULL){
		i++;
		if(temp->data==item){
			printf("found at %d\n",i);
			c++;
			break;
		}
		temp=temp->next;
	}
	if(c==0)
		printf("not found\n");
}
void main(){
	int c;
	clrscr();
	while(1){
		printf("1.puwsh\n2.pop\n3.display\n4.search\n5.exit\n");
		scanf("%d",&c);
		switch(c){
			case 1:push();
				break;
			case 2:pop();
				break;
			case 3:display();
				break;
			case 4:search();
				break;
			case 5:exit();

		}
	}

}