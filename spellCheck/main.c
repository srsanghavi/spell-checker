// project Name: Spell Checker and Suggester
// program Name: main
// Date of last Modification: 5 oct. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// Brief Description: this program is bassically menu driven program which decides the function to be called according to the input by the user.



#include"spellChecker.h" //header file which contains declaration of the all the functions which are needed for this program
int main(int argv,char *command[])
{	
	system("clear");	//system command to clr the terminal
	printf("SSSS-ver-2.3.6\n"); 
	if(command[1]==NULL || command[1][0]!='-') // checking wheter commandline inputs are gives or not
	{
		printf("type './SSSS -h' for help\n");
		return 0;
	}
	if(command[1][1]=='h') // if user is asking for the help
	{
		printf("this program is a simple spell suggester which can suggest a right spelling of incorrectly spelled word. With the help of this program you can check the entire textfile. You can add word to the database as well as u can print the whole database. one can also get the different possible words starting from specific letter.\n");
		printf("co-founder: Shashwat Sanghavi\n");
		printf("co-founder: Shikhar Pandya\n");
		printf("\ncommands\nprint database -p\nsearch in database -s\ninsert a word indatabase -i\ncheck a file -f\nfor help -h\npossible words -w\n");
		printf("example: ./SSSS -<command> <word/filename>\n\n");
		return 0;
	}
	trie *root,*temp;
	root=NULL;
	char spell[30];
	int found;
	root=fscan(root);	//retrieving the database from a file
	switch(command[1][1])	//decing the operation depending the command line arguments
	{
		default:	//if commandline aruments contain invalid input
			printf("type './SSSS -h' for help\n");
		return 0;
		
		case 'i':	//insert word in the database
		if(command[2]=='\0'){
		printf("input parameter can not be NULL while using -i command\n");		
		return 0;}
		root=insert(root,command[2]);	//insert function is defined in spellChecker.h
		break;
		case 'p':	// print  the whole database
		print(root,NULL);
		break;
		case 's': // search a perticular word in the database if the word is wrong then it will give u a possible spelling
		if(command[2]=='\0'){
		printf("input parameter can not be NULL while using -s command\n");		
		return 0;}
		found=search(root,command[2]);	//if the word is correct then it will be found in the database and the function search will return a value 1.
		if(found==1) 
		printf("word (%s) found.",command[2]);
		break;
		case 'f': // check each and every word of a file provided as a commandline argument
		
		if(command[2]=='\0'){
		printf("input parameter can not be NULL while using -f command\n");		
		return 0;}
		root=checkDocument(root,command[2]);
		break;
		case 'w': // complete the word
		if(command[2]=='\0'){
		printf("input parameter can not be NULL while using -w command\n");		
		return 0;}
		printf("words starting from '%s' are:\n\n",command[2]);
		autoComplete(root,command[2]);
		break;
	}
	fprint(root);	//writing the database into the file
	printf("\n\n");
	return 0;
}
