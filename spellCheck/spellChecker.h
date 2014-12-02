// project Name: Spell Checker and Suggester
// program Name: spellChecker (header file)
// Date of last Modification: 5 oct. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// brief Description: header file which contains delaration of all functions used in the program

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct trie{
	char word;
	struct trie *firstChild;
	struct trie *nextChild;
	char flag;
	int level;
};
typedef struct trie trie;
struct stack
{
	trie *data;
	struct stack * next;
};
struct stack *top1;

void push(trie *num);		//push the node into the stack
struct trie *pop();		//pop the data stored in the stack
trie *insert(trie *root, char *spell); //insert a new word in the TRIE data structure
int search(trie *root, char *spell);   //search a word in the TRIE database 
void *print(trie *root,char *spell);   //print all the words stored in the TRIE database using standard I/O
void *fprint(trie *root);	//print all words stored in  the TRIE data structure using FILE I/O 
trie *fscan(trie *root);	//read a file to get words for creating databse
trie *checkDocument(trie *root,char *doc); //to check a document for misspelled words
void *suggestion(trie *root,char *spell);  //find similar words
void autoComplete(trie *root, char *spell);//find words starting from perticular intial letters
