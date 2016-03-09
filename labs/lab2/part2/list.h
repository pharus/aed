/******************************************************************************
 *
 * File Name: lista.h
 *	      (c) 2010 AED
 * Authors:    AED Team
 * Last modified: ACR 2010-03-17
 * Revision:  v2.1
 *
 * COMMENTS:
 *		Structure and prototypes for type t_lista, a 1st order
 *              abstract data type that is a container.
 *		Each variable of type t_lista implements a node of
 *              list of Items.
 *
 *****************************************************************************/

#ifndef _LISTA_H
#define _LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#include "defs.h"

/* type definition for structure to hold list item */
typedef struct _t_lista t_lista;


t_lista  *iniLista (void);
t_lista  *criaNovoNoLista (t_lista *lp, Item this, int *err);
Item      getItemLista (t_lista *p);
t_lista  *getProxElementoLista(t_lista *p);
int       numItensNaLista (t_lista *lp);
void 	  libertaLista(t_lista *lp, void freeItem(Item));

#endif
