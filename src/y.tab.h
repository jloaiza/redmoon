/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DECLARAR = 258,
     NEWLINE = 259,
     SI = 260,
     ENTONCES = 261,
     SINO = 262,
     HAGA = 263,
     ETIQUETA = 264,
     IR = 265,
     IMPRIMIR = 266,
     ID = 267,
     NUM = 268,
     OPREL = 269,
     MIENTRAS = 270,
     OPARISU = 271,
     LEER = 272,
     OPARIMUL = 273,
     BOOL = 274,
     FUNCION = 275,
     AUTOR = 276,
     VERSION = 277,
     PARAMETRO = 278,
     FECHA = 279,
     COMENTARIO = 280,
     EXPLICACION = 281,
     SUBEXPLICACION = 282,
     RETORNAR = 283
   };
#endif
/* Tokens.  */
#define DECLARAR 258
#define NEWLINE 259
#define SI 260
#define ENTONCES 261
#define SINO 262
#define HAGA 263
#define ETIQUETA 264
#define IR 265
#define IMPRIMIR 266
#define ID 267
#define NUM 268
#define OPREL 269
#define MIENTRAS 270
#define OPARISU 271
#define LEER 272
#define OPARIMUL 273
#define BOOL 274
#define FUNCION 275
#define AUTOR 276
#define VERSION 277
#define PARAMETRO 278
#define FECHA 279
#define COMENTARIO 280
#define EXPLICACION 281
#define SUBEXPLICACION 282
#define RETORNAR 283




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


