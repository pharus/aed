/******************************************************************************
 *
 * File Name: utils.c
 *	      (c) 2010 AED
 * Authors:    AED Team
 * Last modified: ACR 2010-03-17
 * Revision:  v2.1
 *
 * COMMENTS
 *		Implements the function erroMemoria
 *
 *****************************************************************************/

#include "defs.h"
#include "words.h"
#include "list.h"
#include "utils.h"


/******************************************************************************
 * erroMemoria ()
 *
 * Arguments: msg - pointer to message to print
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: print to standard error output an allocation error message
 *
 *****************************************************************************/

void erroMemoria(char *msg) {

  fprintf(stderr, "Error during memory reserve attempt.\n");
  fprintf(stderr, "Msg: %s\n",msg);
  fprintf(stderr, "Exit Program due to unmanaged error.\n");

  exit(1);
}


/******************************************************************************
 * testaPalavra ()
 *
 * Arguments: lp - pointer to list of words
 *            novaPal - pointer to new word to be tested
 * Returns: t_listaPalavras  *
 * Side-Effects: none
 *
 * Description: searchs for a word in the list
 *              if found increments ocorrencias,
 *              otherwise adds a new word to the list and returns a pointer
 *                    to the begin of the list
 *              this pointer could have been modified (when ?);
 *
 *****************************************************************************/

t_lista  *testaPalavra(t_lista *lp, char *novaPal) {
  t_lista *aux; /* auxiliar pointers to travel through the list */
  t_palavra *pal;
  int err;

  aux =lp;
  while (aux != NULL){
    pal = (t_palavra*) getItemLista(aux);
    if(strcasecmp(getPalavra(pal),novaPal)==0){
      incOcorr(pal);
      return lp;
    }
    aux = getProxElementoLista(aux);
  }
  /* Insertion at the begin of the list (not sorted!) */

  pal = criaPalavra(novaPal);
  lp = criaNovoNoLista(lp, pal, &err);

  return lp;
}


/******************************************************************************
 * escrevePalavras ()
 *
 * Arguments: lp - pointer to list of words
 *            fp - pointer to file where output is written
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: output all words and ocurrences to file
 *
 *****************************************************************************/

void escrevePalavras(t_lista *lp, FILE *fp) {
  t_lista *aux; /* auxiliar pointers to travel through the list */
  aux = lp;
  while(aux != NULL){
    escreveUmaPalavra((t_palavra*) getItemLista(aux), fp);
    aux = getProxElementoLista(aux);
  }
}

void escrevePalavrasRec(t_lista *lp, FILE *fp) {
  if (lp) {
    escrevePalavrasRec(getProxElementoLista(lp), fp);
    escreveUmaPalavra((t_palavra*) getItemLista(lp), fp);
  }
}



/******************************************************************************
 * leFicheiro ()
 *
 * Arguments: fp - pointer to file to read words from
 *            numPalavras - pointer to number of words read
 * Returns: t_lista  *
 * Side-Effects: none
 *
 * Description: Read words from a file and returns a list of words.
 *              Increments the counter numPalavras (passed by reference)
 *              for each word read.
 *
 *****************************************************************************/

t_lista  *leFicheiro(FILE *fp, int *numPalavras) {
  char novaPal[DIM_MAX_PALAVRA];
  t_lista *lp;

  lp = iniLista();
  while(fscanf(fp, "%s", novaPal) == 1){
    lp = testaPalavra(lp,novaPal);
    (*numPalavras)++;
  }

  return lp;
}


/******************************************************************************
 * libertaItem ()
 *
 * Arguments: p - pointer to Item
 * Returns: (void)
 * Side-Effects: calls function to free word structure
 *
 * Description: interfaces generic list item to specific word structure
 *
 *****************************************************************************/

void libertaItem(Item this) {

  libertaPalavra((t_palavra *) this);

  return;
}
