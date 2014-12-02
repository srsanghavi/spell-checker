// project Name: Spell Checker and Suggester
// program Name: checkDocument
// Date of last Modification: 28 sept. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// Brief Description: this program read a file to be checked for the spelling mistakes.



#include"spellChecker.h"
trie *checkDocument(trie *root,char *doc)
{
	char spell[23];
	FILE *fp;
	fp=fopen(doc,"r");
	if(fp!=NULL){
		fscanf(fp,"%s",spell);
		spell[22]=fgetc(fp);
		while(spell[22]!=EOF) //read the file word by word
		{
			search(root,spell);   //search each word
			fscanf(fp,"%s",spell);
			spell[22]=fgetc(fp);
		}
		fclose(fp);
		return root;
	}
	else printf("database not found");
}
