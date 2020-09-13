%{
#include <string.h>
#include <ctype.h>
#include "projet.tab.h"

//cette foncion est redefinition de la fonction atoi en C
//a pour but la convertion du type string vers int
int StrInt(string) register char *string;{
    register int result = 0;
    register unsigned int digit;
    int sign = 1;
    while (isspace(*string)) {
		string++;
    }
    if(*string == '('){
		sign = -1;
		string += 2;
	}else if (*string == '+') {
		string++;
    }
    for ( ; ; string++) {
		digit = *string - '0';
		if (digit > 9) {
			break;
		}
		result *= 10;
		result += digit;
    }
	return sign * result;
}

extern YYSTYPE yylval;
int ligne=1, colonne=1;
const int IND = 4;
%}
digit [0-9]
entier {digit}+|"(""-"{digit}+")"
idf [A-Z][0-9a-z]*
%%

^[ \t]*\n {ligne++;}
"INTEGER" {colonne+=yyleng; yylval.str=strdup(yytext); return(XINT);}
{entier} {colonne+=yyleng; if(StrInt(yytext)<=32767 && StrInt(yytext)>=-32768)yylval.num=StrInt(yytext);
			else {ErrorDepassementTaille(); yylval.num=StrInt("0");} return(ENTIER);}
{idf} {colonne+=yyleng; yylval.str=strdup(yytext);if(yyleng>10){yyerror("IDF Trop Long");} return(IDF);}

"(" {colonne++; yylval.str=strdup(yytext); return (PO);}
")" {colonne++; yylval.str=strdup(yytext); return (PF);}
"[" {colonne++; yylval.str=strdup(yytext); return (CO);}
"]" {colonne++; yylval.str=strdup(yytext); return (CF);}
"{" {colonne++; yylval.str=strdup(yytext); return (AO);}
"}" {colonne++; yylval.str=strdup(yytext); return (AF);}
":" {colonne++; yylval.str=strdup(yytext); return (DP);}
"," {colonne++; yylval.str=strdup(yytext); return (VIRG);}

"-" {colonne++; yylval.str=strdup(yytext); return '-';}
"+" {colonne++; yylval.str=strdup(yytext); return '+';}
"*" {colonne++; yylval.str=strdup(yytext); return '*';}
"/" {colonne++; yylval.str=strdup(yytext); return '/';}
"=" {colonne++; yylval.str=strdup(yytext); return '=';}
"%" {colonne++; yylval.str=strdup(yytext); return '%';}

"IFELSE" {colonne+=yyleng; yylval.str=strdup(yytext); return(IFELSE);}
"ELSE IF" {colonne+=yyleng; yylval.str=strdup(yytext); return(ELIF);}
"ELSE" {colonne+=yyleng; yylval.str=strdup(yytext); return(ELSE);}
"IF" {colonne+=yyleng; yylval.str=strdup(yytext); return(IF);}

"FOR" {colonne+=yyleng; yylval.str=strdup(yytext); return(FOR);}
"IN" {colonne+=yyleng; yylval.str=strdup(yytext); return(INN);}
"WHILE" {colonne+=yyleng; yylval.str=strdup(yytext); return(WHILE);}

">" {colonne++; yylval.str=strdup(yytext); return(GT);}
">=" {colonne++; yylval.str=strdup(yytext); return(GE);}
"==" {colonne++; yylval.str=strdup(yytext); return(EQ);}
"!=" {colonne++; yylval.str=strdup(yytext);return(NE);}
"<=" {colonne++; yylval.str=strdup(yytext);return(LE);}
"<" {colonne++; yylval.str=strdup(yytext);return(LT);}

"+=" {colonne++; yylval.str=strdup(yytext);return(INC);}
"-=" {colonne++; yylval.str=strdup(yytext);return(DEC);}

#.* {colonne+=yyleng; yylval.str=strdup(yytext);}
^[ \t]*#.*\n {ligne++; yylval.str=strdup(yytext);}
[\n] {colonne=1; ligne++; yylval.str=strdup(yytext);return SAUT;}
[\t] {colonne+=IND; yylval.str=strdup(yytext);}
" " {colonne++; yylval.str=strdup(yytext);}

. {yyerror("Erreur lexicale entite");}
%%
int yywrap () {return 1;}
