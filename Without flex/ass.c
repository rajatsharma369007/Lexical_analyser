#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char keyword[][10] ={
                        "while","break","continue","char","int","float",
                        "if","else","do","switch","case","void","return"
                    };

/*size of the keyword array*/
int size = sizeof(keyword)/sizeof(keyword[0]),i,j;

char operator[] = "!%&*+-/<>=";

void check_oper(char);      /* function for checking any operator*/
void check_key(char []);    /* function for checking any keyword*/

main(int argc, char *argv[])
{
	char ch, buffer[15];
	FILE *fp = fopen("text.txt","r");

	while((ch = fgetc(fp)) != EOF)
	{
	    /* checking ch contains any operator or not */
		check_oper(ch);

        /* if ch is alphanumeric then store it in buffer */
		if(ch>=48 && ch<=57 || ch>=65 && ch<=90 || ch>=97 && ch<=122)
		{
			buffer[j++] = ch;
		}
		else if((ch == ' ' || ch == '\n') && (j != 0))
		{
		    /* convert the buffer into string */
			buffer[j] = '\0';
			j = 0;
			/* check whether string is keyword, literal, identifer (valid or invalid) */
			check_key(buffer);
		}
	}

	fclose(fp);
}

void check_oper(char ch)
{
		for(i=0;i<=sizeof(operator);i++)
		{
		    /* linear search for the operator*/
			if(ch == operator[i])
				printf("Operator   : %c\n", ch);
		}
}

void check_key(char buffer[])
{
	int i, flag = 0;
	for(i = 0; i < size; ++i)
	{
	    /* linear search for the keyword */
		if(strcmp(keyword[i], buffer) == 0)
		{
			printf("Keyword    : %s\n", buffer);
			return;
		}
	}

    /* if string starts with number*/
	if(buffer[0] >=48 && buffer[0] <=57)
	{
		for(i=0;i<strlen(buffer);i++)
		{
		    /* checking whether it is literal or invalid identifier */
			if(!(buffer[i] >= 48 && buffer[i] <= 57))
				flag=1;   /*0 flag=invalid ,1 flag=literal*/
		}

		if(flag!=1)
		{
		    /* converting string into number */
			int temp = atoi(buffer);
			printf("Literal    : %d\n", temp);
			return;
		}
		else
		{
		    printf("Identifier : %s (invalid)\n", buffer);
            return;
		}
	}

    /* if string starts with alphabet */
	if(buffer[0] >=65 && buffer[0] <=90 || buffer[0] >=97 && buffer[0] <=122)
	{
		printf("Identifier : %s\n", buffer);
		return;
	}
}
