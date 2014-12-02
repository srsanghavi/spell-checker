// project Name: Spell Checker and Suggester
// program Name: printTrie
// Date of last Modification: 6 oct. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// Brief Description: this program is used to write the database on the terminal.



#include"spellChecker.h"
void *print(trie *root,char *spell){
	int i=1;
	trie *temp;
	temp=root;
	int level=0;
	char word[30];
	if(temp==NULL){					// checking whether the database is empty or not
		printf("no data available");
		return 0;				// end the program if the database is NULL
	}
	else{
		printf("\n");
		if(spell!=NULL)				// if spell which is input by the user is not empty then print it before each word
			printf("%s",spell);		
		word[level]=temp->word;			// read the character stored in the node and store it in the char array(to form a string)
		while(level<30){
			printf("%c",word[level]);	// print character by character
			if(temp->nextChild!=NULL)	
				push(temp);		// if there is a nextChild of any node then push that node in the stack so that we can get that node of the trie later for obtaining next word
			if(temp->firstChild!=NULL && temp->flag=='1')  // if first child of the TRIE node is not NULL and the flag of that node is 1 that idicates that the node is having a last letter of perticular word but it is a subword of other word
			{
				printf("\n");			 // print a new line character to seperate two words
				if(spell!=NULL)			 // if spell which is input by the user is not empty then print it before each word
				printf("%s",spell);
				for(level=0;level<=temp->level;level++)// print the same word so that we can complete that word to obtain other word
				printf("%c",word[level]);
				level--;
			}
			if(temp->firstChild!=NULL){  // if firstChild of the TRIE node is not NULL then store letter of the node in to the array element and continue the loop from the starting
				temp=temp->firstChild;
				level++;
				word[level]=temp->word;
				temp->level=level;
				continue;	
			}
			else if(top1!=NULL){   // if stack is not empty the pop element from it go to the nextChild of that node print all the letters of the above node and continue the loop
				temp=pop();
				level=temp->level;
				temp=temp->nextChild;
				temp->level=level;
				word[level]=temp->word;
				printf("\n");
				if(spell!=NULL)
				printf("%s",spell);
				for(level=0;level<temp->level;level++){
					printf("%c",word[level]);
				}
				continue;
			}
			else if(top1==NULL) // if fistChild and nextChild of a node is empty and stack is also empty it implies that the whole database has been printed
			return 0;	// close the file and end the program
	}}
}


