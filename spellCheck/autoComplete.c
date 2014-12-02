// project Name: Spell Checker and Suggester
// program Name: autoComplete
// Date of last Modification: 7 oct. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// Brief Description: this program is used for auto completing the word starting from perticular initial(s).


#include"spellChecker.h"

// basically is checks for the word which the user has given as the input whether it is in the database or not if it is there then it will call print function and give that word as the argument
void autoComplete(trie *root, char *spell){
	trie *temp,*temp1;
	int size,i,emptyFirst=0,emptyNext=0,last;
	size=strlen(spell);
	temp=root;
	char spell1[30]={0};
	if(temp==NULL)
		printf("no data available");
	else{	i=0;
		while(i<size){
			if(temp->word==spell[i]){
				if(temp->firstChild==NULL && i+1!=size){
					emptyFirst=1;
					break;
				}
				temp1=temp;
				temp=temp->firstChild;
				i++;
				continue;
			}
			else{	
				if(temp->nextChild==NULL ){
					emptyNext=1;
					break;
				}
				temp1=temp;
				temp=temp->nextChild;
				continue;
			}
		}
		if(emptyFirst==1 || emptyNext==1)
			printf("word not found");
		else
		{
			for(i=0;i<size;i++)
			spell1[i]=spell[i];
			print(temp,spell1);
		}
	}
	
}
