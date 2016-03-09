/******************************************************************************
 *
 * File Name: words.h
 *	      (c) 2010 AED
 * Authors:    AED Team
 * Last modified: ACR 2010-03-17
 * Revision:  v2.1
 *
 * COMMENTS
 *		Structure and prototypes for type t_palavra
 *		t_palavra includes a string (nome) and an int (ocorrencias)
 *
 *****************************************************************************/

#ifndef _PALAVRA_H
#define _PALAVRA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* type definition for structure to hold word */
typedef struct _t_palavra t_palavra;


/* Interface functions for type t_palavra */
t_palavra  *criaPalavra (char *nome);
char       *getPalavra (t_palavra *p);
int         getNocorr (t_palavra *p);
void        incOcorr (t_palavra *p);
void        escreveUmaPalavra (t_palavra *p,FILE *fp);
void 	    libertaPalavra(t_palavra *p);

#endif
