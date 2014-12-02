// project Name: Spell Checker and Suggester
// program Name: searchTrie
// Date of last Modification: 3 oct. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// brief description: this function find a perticular word in the TRIE databse. it will return 1 if word is found.

#include"spellChecker.h"

int search(trie *root, char *spell){

	trie *temp;				
	int size,i;
	char emptyFirst='0',emptyNext='0',last;
	size=strlen(spell);
	temp=root;

	if(temp==NULL){				//checking: if database is NULL
		printf("no data available");
	}

	else{					//if database is not NULL
		i=0;
		while(i<size){			// execute the loop as much time as the lenght of the word
			if(temp->word==spell[i] ){  // if letter matches with the leter stored in the node
				if(temp->firstChild==NULL && i+1!=size){   //fistChild is empty and it is not the last letter of the word 
					emptyFirst='1'; // break the loop
					break;
				}
				if( temp->flag=='1') last='1';  // if the node contains the last letter of the word then mark the flag last
				else last='0';
				temp=temp->firstChild;          
				i++;
				continue;
				}
			else{	//if letter doesn't match to the letter stored in the node
				if(temp->nextChild==NULL ){  //next child is empty mark the flag emptyNext
					emptyNext='1';
					break;
				}
				temp=temp->nextChild;
				continue;
			}
		}
		if(emptyFirst=='1' || last=='0'|| emptyNext=='1') //if the given condition is true then it implies that the word is not there in the database so call the function suggest to suggest similar word
		{	
			
			if(spell[0]!='.' && spell[0]!='?' && spell[0]!='!')
			{
			printf("did you mean this instead of %s\n",spell);
			suggestion(root,spell);
			}
			return 0;
		}
		else if(last=='1' ) // else the word is there in the database so return 1
		{
		return 1;
		}
	}
}
