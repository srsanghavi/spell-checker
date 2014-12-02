// project Name: Spell Checker and Suggester
// program Name: stack
// Date of last Modification: 26 sept. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// Brief Description: this program is used to create a stack for storing the node to help printTrie and exportTrie function.



#include"spellChecker.h"

void push(trie *num)
{
	struct stack *node=NULL;
	struct stack *temp=NULL;
	if(top1==NULL)
	{
		top1=malloc(sizeof(struct node*));
		top1->data=num;
		top1->next=NULL;
	}
	else{
		temp=top1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
			
		}
		node=malloc(sizeof(struct node*));
		temp->next=node;
		temp=temp->next;
		temp->next=NULL;
		temp->data=num;
	}
}
struct trie *pop()
{
	struct trie *num;
	struct stack *temp=NULL;
	struct stack *prev;
	if(top1==NULL)
		return NULL;
	if(top1->next==NULL)
	{
		num =top1->data;
		top1=NULL;
		return num;
	}
	else
	{
		temp=top1;
		while(temp->next!=NULL)
		{
			prev=temp;
			temp=temp->next;
		}
		num=temp->data;
		prev->next=NULL;
		return num;
	}
}
