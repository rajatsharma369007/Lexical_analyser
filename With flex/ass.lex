
DIGIT   [0-9]
ID      [a-z][a-z0-9]*

%%

{DIGIT}+        {
			printf("An integer: %s (%d)\n",yytext, atoi(yytext));
                }

{DIGIT}+"."{DIGIT}+     {
				printf("A float: %s (%g)\n",yytext, atof(yytext));
                        }

auto|break|char|const|continue|default|do|else|enum|if|goto|float|extern|sizeof|void|while|return|int   {
														printf("A keyword: %s\n",yytext);
													}

{ID}    {
		printf("An identifier: %s\n",yytext);
	}
	
"()"	{ }

"<"|">"|"=="|"++"|"="|"("|")"|"+"|"-"|"*"|"/" 	{   
							printf( "An operator: %s\n", yytext );
						}

[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]     { }

"//".*    { }     

[ \t\n]+  { } 

","	{ }

";"	{ }

.       printf( "unrecognized character: %s\n", yytext );

%%

int main( int argc, char **argv )
{
        ++argv, --argc;
        if ( argc > 0 )
                yyin = fopen( argv[0], "r" );
        else
                yyin = stdin;
        yylex();
}
