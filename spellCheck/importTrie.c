// project Name: Spell Checker and Suggester
// program Name: importTrie
// Date of last Modification: 6 oct. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// Brief Description: this program is used to read the database from the file. it can read a text document(.dat).

#include"spellChecker.h"
trie *fscan(trie *root){
	char spell[25],fileName[25];		//max size of word is 24
	FILE *fp;
	fp=fopen("database.dat","r");
	if(fp!=NULL){
		fscanf(fp,"%s",spell);
		while(spell[24]!=EOF)			//read the file word by word until a EOF character
		{
			root=insert(root,spell);    //insert a word into the trie data structure
			fscanf(fp,"%s",spell);
			spell[24]=fgetc(fp);
		}
		root=insert(root,spell);
		fclose(fp);
	}
	else printf("database not found");
	return root;
}
