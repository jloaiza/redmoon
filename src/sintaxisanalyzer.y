%{
#include <stdio.h>
#include <stdlib.h> 
extern FILE *yyin;
extern FILE *yyout;

int _lineError = 1;

void yyerror (char *s);
void startAnalyzer();

void setErrorLineNumber(int pNumber);
int getErrorLineNumber();

%}


%token DECLARAR
%token NEWLINE
%token SI
%token ENTONCES
%token SINO
%token HAGA
%token ETIQUETA
%token IR
%token IMPRIMIR
%token ID
%token NUM
%token OPREL
%token MIENTRAS
%token OPARISU
%token LEER
%token OPARIMUL
%token BOOL
%token FUNCION
%token AUTOR
%token VERSION
%token PARAMETRO
%token FECHA
%token COMENTARIO
%token EXPLICACION
%token SUBEXPLICACION
%token RETORNAR

%%

Programa : ListaVariables ListaFunciones ListaDeclaraciones 
         |error NEWLINE
         ;
ListaVariables : DeclaracionDocumentacion ListaVariablesPrima
               | ListaVariablesPrima
               ;
ListaVariablesPrima : ListaVariables DeclaracionVariable 
                    | DeclaracionVariable            
                    ;
ListaFunciones : DeclaracionDocumentacion FUNCION ID '(' ID ')' '{' ListaVariables DeclaracionAsignacion RETORNAR ID '}' 
               | FUNCION ID '(' ID ')' '{' ListaVariables DeclaracionAsignacion RETORNAR ID '}'                
               ;
DeclaracionVariable : DECLARAR ID NEWLINE                    
                    ;
ListaDeclaraciones : ListaDeclaraciones Declaracion
                   | Declaracion
                   ;
ListaDeclaracionesCondicionadas : Declaracion
                                | '{' ListaDeclaraciones '}'                              
                                ;
Declaracion : DeclaracionPrima NEWLINE
            ;
DeclaracionPrima : DeclaracionAsignacion 
                 | DeclaracionSeleccion 
                 | DeclaracionIteracion 
                 | DeclaracionEtiqueta 
                 | DeclaracionSaltoEtiqueta 
                 | DeclaracionImprimir 
                 | DeclaracionLeerCaracterDePantalla
                 ;           
DeclaracionAsignacion : ID '=' Expresion NEWLINE                      
                      ;
ExpresionCondicion : Expresion
                   | BOOL
                   ;                   
Expresion : ExpresionSuma OperadorRelacional ExpresionSuma
          | ExpresionSuma
          ;
ExpresionSuma : ExpresionSuma OperadorSuma Termino 
              | ExpresionMult
              ;
ExpresionMult : ExpresionMult OperadorMult ExpresionSuma
              | Termino      
              ;
OperadorRelacional : OPREL
                   ;
OperadorSuma : OPARISU
             ;
OperadorMult : OPARIMUL
 			       ;
Termino : '(' Expresion ')'  
        | ID 
        | NUM
        | FUNCION ID '(' ID ')'        
        ;
DeclaracionSeleccion : SI '(' ExpresionCondicion ')' ENTONCES ListaDeclaracionesCondicionadas        				 
                     | SI '(' ExpresionCondicion ')' ENTONCES ListaDeclaracionesCondicionadas SINO ListaDeclaracionesCondicionadas                     
                     ;
DeclaracionIteracion : MIENTRAS '(' ExpresionCondicion ')' HAGA ListaDeclaracionesCondicionadas
                     | HAGA ListaDeclaracionesCondicionadas MIENTRAS Expresion                  
                     ;
DeclaracionEtiqueta : ETIQUETA ID NEWLINE                    
 					          ;
DeclaracionSaltoEtiqueta : IR ID NEWLINE                         
 						             ; 
DeclaracionImprimir : IMPRIMIR ID NEWLINE                    
					          ; 		
DeclaracionLeerCaracterDePantalla : LEER ID NEWLINE                                  
								                  ;
DeclaracionComentario : '/*' COMENTARIO '*/'	                      
					            ;
DeclaracionDocumentacion : '/**' DeclaracionAutor | DeclaracionVersion | DeclaracionParametro | DeclaracionFecha | DeclaracionExplicacion '**/'
						             ;
DeclaracionAutor : '@' AUTOR ID                
				         ;
DeclaracionVersion : '@' VERSION ID                   
				           ;
DeclaracionParametro : '@' PARAMETRO ID                     
					           ;
DeclaracionFecha : '@' FECHA ID
				         ;
DeclaracionExplicacion : '@' EXPLICACION SUBEXPLICACION		
          					   ; 	 					 						  					                                   
%%

void yyerror (char *s) 
{
    fprintf (yyout, "%s in the line %d", s, getErrorLineNumber());
}

void setErrorLineNumber(int pNumber)
{
    _lineError = pNumber;
}

int getErrorLineNumber()
{
    return _lineError;
}

void startAnalyzer()
{
    yyin = fopen("/root/Desktop/redmoon/src/entrada", "r");
    yyout = fopen("/root/Desktop/redmoon/src/errores", "w");
    if((yyin == NULL) || (yyout == NULL))
    {
         printf("Ha ocurrido un error en la carga del archivo para escritura o lectura.");
    }
    else 
    {
        printf("INICIO DEL PARSER \n");
        yyparse();
        fprintf (yyout, "\nTotal number of syntax errors reported: %d", yynerrs);
        fclose(yyin);
        fclose(yyout);
    } 
}

int main()
{
    startAnalyzer();
    return 0;
}
