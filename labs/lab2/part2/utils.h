/******************************************************************************
 *
 * File Name: utils.h
 *	      (c) 2010 AED
 * Authors:    AED Team
 * Last modified: ACR 2010-03-17
 * Revision:  v2.1
 *
 * COMMENTS
 *		Function prototype for memory allocation error message
 *
 *****************************************************************************/

#ifndef _UTIL_H
#define _UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "defs.h"
#include "list.h"


void erroMemoria (char *msg);

t_lista  *testaPalavra (t_lista *lp, char *pal);
void      escreve (t_lista *lp,FILE *fp);
t_lista  *leFicheiro (FILE *fp,int *num);
t_lista  *leFicheiro(FILE *fp,int *numPalavras);
void      escrevePalavras(t_lista *lp, FILE *fp);
/* Our function */
void      escrevePalavrasRec(t_lista *lp, FILE *fp);
void      libertaItem(Item this);

#endif
