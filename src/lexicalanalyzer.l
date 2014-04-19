%{
	#include "y.tab.h"
	/* comentario ([a-zA-Z0-9]|\*|_|\n)* */
	/* {comentario} {printf("COMENTARIO:%s ",yytext);return(COMENTARIO);} */
	/* subexplicacion ({ws}|\n|{id})* */
	/* {subexplicacion} {printf("SUBEXPLICACION:%s ",yytext);return (SUBEXPLICACION);} */
	/*Definicion de los tokens
	ESPACIO, DECLARAR, NEWLINE, SI, ENTONCES, SINO, HAGA, 
	ETIQUETA, IR, IMPRIMIR, ID, NUM, OPREL, OPARI, BOOL, FUNCION,
	AUTOR, VERSION, PARAMETRO, FECHA, EXPLICACION */
%}

/*Definicion de las expresiones regulares*/

delim [ \t]
digito [0-9]
letra [a-zA-Z]
ws {delim}+
num {digito}{digito}*
id ({letra}|_)({letra}|[0-9]){0,30}
otro .
%%

{ws} {printf("ESPACIO:%s ",yytext);}
newline {printf("NUEVA LINEA:%s ",yytext);return(NEWLINE);}
declarar {printf("DECLARAR:%s ",yytext);return (DECLARAR);}
funcion {printf("FUNCION:%s ",yytext);return(FUNCION);}
true {printf("TRUE:%s ",yytext);return(BOOL);}
autor {printf("AUTOR:%s ",yytext);return(AUTOR);}
version {printf("VERSION:%s ",yytext);return(VERSION);}
parametro {printf("PARAMETRO:%s ",yytext);return(PARAMETRO);}
fecha {printf("FECHA:%s ",yytext);return(FECHA);}
explicacion {printf("EXPLICACION:%s ",yytext);return(EXPLICACION);}
false {printf("FALSE:%s ",yytext);return(BOOL);}
si {printf("SI:%s ",yytext);return(SI);}
entonces {printf("ENTONCES:%s ",yytext);return(ENTONCES);}
leer {printf("LEER:%s ",yytext);return(LEER);}
sino {printf("SINO:%s ",yytext);return(SINO);}
mientras {printf("MIENTRAS:%s ",yytext);return(MIENTRAS);}
retornar {printf("RETORNAR:%s ",yytext);return(RETORNAR);}
haga {printf("HAGA:%s ",yytext);return(HAGA);}
etiqueta {printf("ETIQUETA:%s ",yytext);return(ETIQUETA);}
ir {printf("IR:%s ",yytext);return(IR);}
imprimir {printf("IMPRIMIR:%s ",yytext);return(IMPRIMIR);}
{num} {printf("NUM:%s ",yytext);return(NUM);}
{id} {printf("ID:%s ",yytext);return(ID);}
"<" {printf("MENOR:%s ",yytext);return(OPREL);}
">" {printf("MAYOR:%s ",yytext);return(OPREL);}
"<=" {printf("MENOR IGUAL:%s ",yytext);return(OPREL);}
">=" {printf("MAYOR IGUAL:%s ",yytext);return(OPREL);}
"==" {printf("IGUAL:%s ",yytext);return(OPREL);}
"!=" {printf("DIFERENTE:%s ",yytext);return(OPREL);}
"+" {printf("MAS:%s ",yytext);return(OPARISU);}
"-" {printf("MENOS:%s ",yytext);return(OPARISU);}
"*" {printf("MULTIPLICACION:%s ",yytext);return(OPARIMUL);}
"/" {printf("DIVISION:%s ",yytext);return(OPARIMUL);}
{otro} {printf("Otro:%s ", yytext);return(yytext[0]);}
%%