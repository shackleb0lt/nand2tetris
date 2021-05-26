#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXCHARPERLINE 80

FILE* initializeInput(char *filename)
{
	return (fopen(filename,"r"));
}

FILE* initializeOutput(char *filename)
{
	int i=0;
	while (filename[i]!='.')i++;
	filename[i+1]='t';
	filename[i+2]='o';
	filename[i+3]='k';
	filename[i+4]='\0';
	return(fopen(filename,"w"));
}
bool is_sym(char s)
{
	if(s=='{' || s=='}' || s=='(' || s==')' || s=='[' || s==']' || s=='.' || s==',' || s==';' || s=='+' || s=='-' || s=='*' || s=='/' || s=='&' || s=='|' || s=='<' || s=='>' || s=='=' || s=='~') return true;

	return false;

}
bool keyword(char *s,FILE* f)
{
	if (strcmp(s,"class")==0 || strcmp(s,"return")==0 || strcmp(s,"constructor")==0 || 
		strcmp(s,"function")==0 || strcmp(s,"method")==0 || strcmp(s,"field")==0 || 
		strcmp(s,"static")==0 || strcmp(s,"var")==0 || strcmp(s,"int")==0 || 
		strcmp(s,"char")==0  || strcmp(s,"boolean")==0 || strcmp(s,"void")==0 || 
		strcmp(s,"true")==0 || strcmp(s,"false")==0 || strcmp(s,"null")==0 || 
		strcmp(s,"this")==0 || strcmp(s,"let")==0 || strcmp(s,"do")==0 || 
		strcmp(s,"if")==0 || strcmp(s,"else")==0 || strcmp(s,"while")==0)
	{
		fprintf(f,"<keyword> %s </keyword>\n",s);
		return true;
	}
	return false;
}
int main(int argc , char *argv[])
{
	FILE *inFile;
	FILE *opFile;

	int i,j,k;
	int lineno=0;

	bool isComm=false;
	char nextcmd[MAXCHARPERLINE];
	char parsedcmd[MAXCHARPERLINE];
	char symbol1[MAXCHARPERLINE];

	inFile=initializeInput(argv[1]);
	opFile=initializeOutput(argv[1]);

	fprintf(opFile,"<tokens>\n");

	while(fgets(nextcmd,MAXCHARPERLINE,inFile)!=NULL)
	{

		lineno++;
		i=0;
		j=0;
		parsedcmd[0]= '\0';
		while(nextcmd[i]==' ' || nextcmd[i]=='\t')i++;
		if(nextcmd[i]=='\n')continue;
		while(nextcmd[i]!='\n' && nextcmd[i]!='\0')
		{
			if(nextcmd[i]=='/' && nextcmd[i+1]=='/')break;
			if(nextcmd[i]=='/' && nextcmd[i+1]=='*')
			{

				isComm=true;
				i+=2;
			}
			if(isComm==true && nextcmd[i]=='*' && nextcmd[i+1]=='/')
			{
	
				isComm=false;
				i+=2;
			}

			if(isComm==false && nextcmd[i]!='\n'){
				parsedcmd[j]=nextcmd[i];
				j++;
			}

			i++;
		}
		if(isComm==false) parsedcmd[j]='\0';

		if (strlen(parsedcmd)==0)continue;

		// printf("%s", parsedcmd);

		i=0;
		j=0;
		symbol1[0]='\0';
		while(parsedcmd[i]!='\0')
		{
			if(parsedcmd[i]=='\"')
			{
				i++;
				while(parsedcmd[i]!='\"')
				{
					symbol1[j]=parsedcmd[i];
					j++;
					i++;
				}
				symbol1[j]='\0';
				fprintf(opFile,"<stringConstant> %s </stringConstant>\n",symbol1);
				j=0;
				symbol1[0]='\0';
				i++;
			}

			if(is_sym(parsedcmd[i])==true)
			{
				symbol1[j]='\0';
				if(strlen(symbol1)!=0)
				{	if(keyword(symbol1,opFile)==false){
						if(symbol1[0]>=48 && symbol1[0]<=57)fprintf(opFile,"<integerConstant> %s </integerConstant>\n",symbol1);
						else fprintf(opFile,"<identifier> %s </identifier>\n",symbol1);
					}
				}

				j=0;
				symbol1[0]='\0';
				if(parsedcmd[i]=='&') fprintf(opFile,"<symbol> &amp; </symbol>\n");
				else if(parsedcmd[i]=='<') fprintf(opFile,"<symbol> &lt; </symbol>\n");
				else if(parsedcmd[i]=='>') fprintf(opFile,"<symbol> &gt; </symbol>\n");
				else if(parsedcmd[i]!='&' && parsedcmd[i]!='<' && parsedcmd[i]!='>')fprintf(opFile,"<symbol> %c </symbol>\n",parsedcmd[i]);
				i++;
				continue;
			}

			if(parsedcmd[i]==' ' && strlen(symbol1)!=0) 
			{ 
				symbol1[j]='\0';
				if(keyword(symbol1,opFile)==false)
				{
					if(symbol1[0]>=48 && symbol1[0]<=57)fprintf(opFile,"<integerConstant> %s </integerConstant>\n",symbol1);
					else fprintf(opFile,"<identifier> %s </identifier>\n",symbol1);
				}
				
				j=0;
				symbol1[0]='\0';
			}

			if(parsedcmd[i]!=' ')
			{
				symbol1[j]=parsedcmd[i];
				j++;
			}
			i++;
		}			
		

		
	



	}
	fprintf(opFile,"</tokens>\n" );
}