// project Name: Spell Checker and Suggester
// program Name: installProgram
// Date of last Modification: 28 sept. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
#include<stdio.h>

int main()
{
	FILE *fp;
	char x;
	// check whether the executable file for the similar program exists or not
	fp=fopen("./SSSS","rb");
	if(fp!=NULL) // if file exists ask user if he wants to regenerate the binary or not 
	{
			system("clear");
		printf("program already installed\npress 1 to continue installation 0 to abort.\n");
		scanf("%c",&x);
		fclose(fp);
		if(x=='0'){
		printf("installation terminated.\n");
		return 0;}
	}
	system("rm SSSS"); 
	system("gcc -o SSSS main.c exportTrie.c importTrie.c insertTrie.c autoComplete.c stack.c checkDocument.c searchTrie.c printTrie.c suggestion.c -lm"); // compile the file
	// check whether the file has been compiled properly or not
	fp=fopen("./SSSS","rb");
	if(fp!=NULL)
	{
	printf("./SSSS has been installed successfully.\n");
	system("clear");
	system("./SSSS -h");
	fclose(fp);
	}
	else return 0;
}
