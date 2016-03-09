/******************************************************************************
 *
 * File Name: words.c
 *	      (c) 2010 AED
 * Authors:    AED Team
 * Last modified: ACR 2010-03-17
 * Revision:  v2.1
 *
 * COMMENTS
 *		implements functions for type t_palavra
 *
 *****************************************************************************/

#include <strings.h>
#include "words.h"
#include "utils.h"


struct _t_palavra {
  char* pal;
  int ocorrencias;
};


/******************************************************************************
 * criaPalavra()
 *
 * Arguments: pal - word to be stored
 * Returns: t_palavra  *
 * Side-Effects: space is allocated for new word
 *
 * Description: Creates and returns a new word, and set the counter
 *              (ocorrencias) to 1
 *
 *****************************************************************************/

t_palavra  *criaPalavra(char *pal) {
  t_palavra *nova;

  nova = (t_palavra*) malloc(sizeof(t_palavra)); /* INSERT CODE to ALLOCATE MEMORY */
  if(nova == NULL)
    erroMemoria("Reserve memory for new word in criaPalavra" );
 /* INSERT CODE to ALLOCATE MEMORY */
  nova -> pal = (char*) malloc(sizeof(char) * (strlen(pal) + 1));

  if(nova == NULL)
    erroMemoria("Reserve of name in criaPalavra" );

  strcpy(nova -> pal,pal);
  nova -> ocorrencias = 1;

  return nova;
}


/******************************************************************************
 * getPalavra ()
 *
 * Arguments: p - pointer to word structure
 * Returns: (char *) pointer to actual word (string)
 * Side-Effects: none
 *
 * Description: returns a pointer to the string containing the actual word
 *
 *****************************************************************************/

char *getPalavra(t_palavra *p) {

  return p -> pal;
}


/******************************************************************************
 * getNocorr ()
 *
 * Arguments: p - pointer to word structure
 * Returns: int
 * Side-Effects: none
 *
 * Description: returns the counter (ocorrencias) associated to a word
 *
 *****************************************************************************/

int getNocorr(t_palavra *p) {

  return p -> ocorrencias;
}


/******************************************************************************
 * inOcorr ()
 *
 * Arguments: p - pointer to word structure
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: increment counter for the number of times (ocorrencias)
 *              a word has been found
 *
 *****************************************************************************/

void incOcorr(t_palavra *p) {

  (p -> ocorrencias)++;
}


/******************************************************************************
 * escreveUmaPalavra ()
 *
 * Arguments: p - pointer to word structure
 *            fp - pointer to output file descriptor
 * Returns: (void)
 * Side-Effects: none
 *
 * Description: writes to given file the word and the number of times
 *              it was seen on the input (ocorrencias)
 *
 *****************************************************************************/

void escreveUmaPalavra(t_palavra *p, FILE *fp) {

  fprintf(fp,"%4d : %s\n", p->ocorrencias, p->pal);
}


/******************************************************************************
 * libertaPalavra ()
 *
 * Arguments: p - pointer to word structure
 * Returns: (void)
 * Side-Effects: allocated memory for word structure is freed
 *
 * Description: free memory reserved for word
 *
 *****************************************************************************/

void libertaPalavra(t_palavra *p) {

  /* -- FREE MEMORY RESERVED FOR WORD -- */
  free(p->pal);
  free(p);
  return;
}



