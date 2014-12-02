// project Name: Spell Checker and Suggester
// program Name: insertTrie
// Date of last Modification: 1 oct. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// Brief Description: this program is used to write the database into the file. it creates a text document(.dat).
//brief description: this function is used to add a word in to the trie data structrure. it will enter a word in the datastructure which is provided as an input and it will returnthe datastructure with similar datatype.

#include"spellChecker.h"

trie *insert(trie *root, char *spell){
	trie *temp;
	int size,i;
	char flag,emptyFirst='0',emptyNext='0';
	size=strlen(spell);
	temp=root;
	if(temp==NULL){                        // if temp is null then it implies that database is empty so that allocate memory to the new node of the structure
		temp=malloc(sizeof(trie));
		temp->firstChild=NULL;
		temp->nextChild=NULL;
		root=temp;
		temp->word=spell[0];
		i=1;
		while(i<size){
			temp->firstChild=malloc(sizeof(trie));
			temp=temp->firstChild;
			temp->firstChild=NULL;
			temp->nextChild=NULL;
			temp->word=spell[i];
			i++;
		}
	}
	else{				
		i=0;
		while(i<size){           // run the loop until the counter equals to the size of the word entered
			if(temp->word==spell[i]){  //if perticular letter of the word matches with the letter stored in the database
				if(temp->firstChild==NULL){  // if there is no word further then break the loop
					emptyFirst='1';
					i++;
					break;
				}
				if(i+1==size){  // if the loop has been excuted for one time less them the size then it shows that the word has been updated to the database to the successsfully
					temp->flag='1';
					flag='1';
				}
				temp=temp->firstChild; 
				i++;
				continue;
				}
			else{	
				if(temp->nextChild==NULL){  // if letter doesn't match to the letter stored in the node and the next node is also empty then break the loop
					emptyNext='1';
					break;
				}	
				temp=temp->nextChild; // if next child is not empty then goto next child and re execute the loop 
				continue;
			}
		}
		if(emptyFirst=='1')  // if firstChild is empty then allocate memory to the firstCHild of the node
		{	while(i<size){
				temp->firstChild=malloc(sizeof(trie));
				temp=temp->firstChild;
				temp->firstChild=NULL;
				temp->nextChild=NULL;
				temp->word=spell[i];
				i++;
			}
		}
		if(emptyNext=='1')  // if nextChild is empty then allocate memory to the nextCHild of the node
		{
			temp->nextChild=malloc(sizeof(trie));
			temp=temp->nextChild; // go one step towards the next child enter a letter in that node
			temp->word=spell[i];
			i++;
			while(i<size){  // enter further letters in the node stored in the first child on that node
				temp->firstChild=malloc(sizeof(trie));
				temp=temp->firstChild;
				temp->firstChild=NULL;
				temp->nextChild=NULL;
				temp->word=spell[i];
				i++;
			}
		}
	}
	if(flag!='1')
	temp->flag='1';
	if(root==NULL)
	printf("root is NULL\n\n");
	return root;
}

