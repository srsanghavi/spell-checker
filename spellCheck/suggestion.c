// project Name: Spell Checker and Suggester
// program Name: suggestion
// Date of last Modification: 4 oct. 2013 
// Author name: Shashwat Sanghavi, Shikhar Pandya
// 
// Brief Description: this program is used to find the correct spelling of the input word. if it can not find any word then it will give the nearest word.



#include"spellChecker.h"
#include<math.h>

//program works similarly as the printTrie program but here instead of printing each character after execution of loop, we are storing that letter in to the array. so thats how we can generate a string and instead of printing a new line character we are checking the string with the input word and then the string will be reinistialized by NULL. thats how each and every word of the trie will be checked with the input word.
void *suggestion(trie *root,char *spell){
	int i=0,diff,j,no;
	no=2;
	trie *temp;
	temp=root;
	int level=0;
	char word[30],*spell1,noSuggest;
	spell1=NULL;
	spell1=malloc(30*sizeof(char *));
	noSuggest='1';
	if(temp==NULL){
		printf("no data available");
		return 0;
	}
	else{

		loop:
		temp=root;
		level=1;
		free(spell1);
		spell1=malloc(30*sizeof(char *));
		word[level]=temp->word;
		while(level<30){
			spell1[level]=word[level];
			if(temp->nextChild!=NULL){
				push(temp);
			}
			if(temp->firstChild!=NULL && temp->flag=='1') 
			{

								spell1[level+1]='\0';
				
					diff=sqrt((strlen(spell)-strlen(spell1))*(strlen(spell)-strlen(spell1)));	// calculating a difference in string length	
					for(j=0;j<strlen(spell),j<strlen(spell1);j++){//calculating the charecter differences
						if((int)spell[j]!=(int)spell1[j] && (int)spell[j]!=(int)spell1[j]+32 && (int)spell[j]!=(int)spell1[j]-32)
						diff++;
					}
					if(diff<no) // here no. is a variable by which u can specify the accuracy that how many differences are acceptable
					{
					printf("%s\n",spell1);
					noSuggest='0';
					}
				free(spell1);
					spell1=malloc(30*sizeof(char *));
				for(level=0;level<=temp->level;level++)
					spell1[level]=word[level];
				level--;
			}
			if(temp->firstChild!=NULL){
				temp=temp->firstChild;
				level++;
				word[level]=temp->word;
				temp->level=level;
				continue;	
			}
			else if(top1!=NULL){
				temp=pop();
				spell1[level+1]='\0';
				level=temp->level;
				temp=temp->nextChild;
				temp->level=level;
				word[level]=temp->word;
				
					diff=sqrt((strlen(spell)-strlen(spell1))*(strlen(spell)-strlen(spell1)));		
					for(j=0;j<strlen(spell) && j<strlen(spell1);j++){
						if((int)spell[j]!=(int)spell1[j] && (int)spell[j]!=(int)spell1[j]+32 && (int)spell[j]!=(int)spell1[j]-32)
						diff++;
					}
					if(diff<no)
					{
					printf("%s\n",spell1);
					noSuggest='0';
					}
				free(spell1);
				spell1=malloc(30*sizeof(char *));
				for(level=0;level<temp->level;level++){
					spell1[level]=word[level];
				}
				continue;
			}
			else if(top1==NULL)
			{
			spell1[level+1]='\0';
			
					diff=sqrt((strlen(spell)-strlen(spell1))*(strlen(spell)-strlen(spell1)));		
					for(j=0;j<strlen(spell) && j<strlen(spell1);j++){
						if(spell[j]!=spell1[j])
						diff++;
					}
					if(diff<no)
					{
					printf("%s\n",spell1);
					noSuggest='0';
					}
			if(temp->nextChild==NULL && temp->firstChild==NULL)
			{
				if(noSuggest=='1')  // if for the given value of the no. if there is no similar word then no. will be incremented by one and then the loop will be executed again
				{
					if(no<3)
					no++;
					else return 0;
					goto loop;
				}
				return 0;
			}
			}
	}}
}
