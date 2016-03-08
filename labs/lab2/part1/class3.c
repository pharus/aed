/******************************************************************************
 *
 * File Name: palavras.c
 *	      (c) 2012 AED
 * Authors:    AED Team
 * Last modified:
 * Revision:  v2.0
 *
 * COMMENTS:    Version with no globals variables
 *		Passing structure for functions
 *		More compact test for EOF
 *
 *****************************************************************************/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_STR 100

typedef struct _st_texto {
  int  n_total_palavras;	/* total number of words */
  int  n_dist_palavras;		/* number of distinct words*/
  char **palavras;		/* Table of strings for words "palavras"*/
  int  *ocorrencias;		/* Table of integers for counting occurences
                                   "ocorrências" */
} st_texto;


/******************************************************************************
 * LePalavra()
 *
 * Arguments: f - pointer to file where word will be read
 * Returns: pointer to word just read
 * Side-Effects: none
 *
 * Description:
 *
 *****************************************************************************/

char *LePalavra ( FILE * f )
{
  static char palavra[MAX_STR];
  /* It is assumed that the words present in the text files do not exceed
     100 characters in length  */
  /* Note that the variable palavra is declared as "static". */
  if ( fscanf ( f, "%s", palavra ) ==1 )
    return (palavra);
  else
    return ((char *) NULL);
}


/******************************************************************************
 * AbreFicheiro()
 *
 * Arguments: nome - pointer to string holding name of file to open
 *            mode - pointer to string holding mode to use for opening file
 * Returns: pointer to opened file
 * Side-Effects: exits if given file cannot be opened with given mode
 *
 * Description:
 *
 *****************************************************************************/

FILE *AbreFicheiro ( char *nome, char *mode )
{
  FILE *f;
  f = fopen ( nome, mode );
  if ( f == NULL ) {
    fprintf ( stderr, "ERROR: It is not possible to open file %s!\n", nome );
    exit ( 1 );
    /* Error messages are sent to the stderr channel.
       Use an exit number different from 0 (zero) in case of error.*/
  }
  return (f);
}


/******************************************************************************
 * AlocaTabelaPalavras()
 *
 * Arguments: ficheiro - pointer to string holding name of file to open
 *            st_texto - pointer to structure where information will be saved
 * Returns: (none)
 * Side-Effects: none
 *
 * Description:
 *
 *****************************************************************************/

void AlocaTabelaPalavras ( char *ficheiro, st_texto *t)
{
  FILE *f;
  char *palavra;
  int i, l, n_max_caracteres = 0;

  (*t).n_total_palavras = 0;
  (*t).n_dist_palavras = 0;
  f = AbreFicheiro ( ficheiro, "r" );
  while ( ( palavra = LePalavra ( f ) ) != NULL ) {
    (*t).n_total_palavras++;
    l = strlen ( palavra );
    if ( l > n_max_caracteres )
      n_max_caracteres = l;
  }
  fclose ( f );
  printf ( "Words count: %d\n", (*t).n_total_palavras );
/* -- Insert code for memory allocation --*/
  (*t).palavras = (char**)malloc(sizeof(char*) * (*t).n_total_palavras);
  if ( (*t).palavras == NULL ) {
    fprintf ( stderr, "ERROR: not enough memory available!\n" );
    exit ( 2 );
  }
/* -- Insert code for memory allocation --*/
  (*t).ocorrencias = (int*) malloc(sizeof(int) * (*t).n_total_palavras);
  if ( (*t).ocorrencias == NULL ) {
    fprintf ( stderr, "ERROR: not enough memory available!\n" );
    exit ( 4 );
  }
  for ( i = 0; i < (*t).n_total_palavras; i++ )	{
  /* -- Insert code for memory allocation --*/
    (*t).palavras[i] = (char*) malloc(sizeof(char)*(n_max_caracteres + 1));
    if ( (*t).palavras[i] == NULL ) {
      fprintf ( stderr, "ERROR: not enough memory available!\n" );
      exit ( 3 );
    }

    (*t).palavras[i][0] = '\0'; /* -- INSERT code to initialize table of strings  --*/
    (*t).ocorrencias[i] = 0;    /* -- INSERT code to initialize table  of counters --*/ ;
  }

  return;
}


/******************************************************************************
 * NovaPalavra()
 *
 * Arguments: palavra - pointer to string holding a word
 *            st_texto - pointer to structure where run information is kept
 * Returns: (none)
 * Side-Effects: none
 *
 * Description:
 *
 *****************************************************************************/

int NovaPalavra ( char *palavra, st_texto *t )
{
  int i = 0;
  /* This function searches for a word in the table.
     if the word is not found returns -1,
     Otherwise returns the position of the word in the table */
  while ( ( (*t).palavras[i][0] != '\0' ) && i < (*t).n_total_palavras ) {
    if ( strcmp ( (*t).palavras[i], palavra ) == 0 )
      return (i);
    i++;
  }
  return (-1);
}


/******************************************************************************
 * PreencheTabelaPalavras()
 *
 * Arguments: ficheiro - pointer to string holding name of file to open
 *            st_texto - pointer to structure where information will be saved
 * Returns: (none)
 * Side-Effects: none
 *
 * Description:
 *
 *****************************************************************************/

void PreencheTabelaPalavras ( char *ficheiro, st_texto *t )
{
  FILE *f;
  int n;
  char *palavra;

  f = AbreFicheiro ( ficheiro, "r" );
  while ( ( palavra = LePalavra ( f ) ) != NULL ) {
    if ( ( n = NovaPalavra ( palavra, &(*t) ) ) == -1 )	{
      strcpy ( (*t).palavras[(*t).n_dist_palavras], palavra );
      (*t).ocorrencias[(*t).n_dist_palavras]++;
      (*t).n_dist_palavras++;
    }
    else {
      (*t).ocorrencias[n]++;
    }
  }
  fclose ( f );
  return;
}


/******************************************************************************
 * EscreveFicheiro()
 *
 * Arguments: ficheiro - pointer to string holding name of file to save
 *            st_texto - pointer to structure where information is kept
 * Returns: (none)
 * Side-Effects: none
 *
 * Description:
 *
 *****************************************************************************/

void EscreveFicheiro ( char *ficheiro, st_texto *t )
{
  FILE *f;
  char *nome;
  int i = 0;
/* -- Insert code for memory allocation,  remember to add space for the dot (.), the filename extension and the string termination --*/ 
  nome = (char*) malloc(sizeof(char) * (strlen(ficheiro) + strlen(".palavras") + 1));  
  if ( nome == NULL ) {
    fprintf ( stderr, "ERROr: not enough memory available!\n" );
    exit ( 5 );
  }
  strcpy ( nome, ficheiro );
  strcat ( nome, ".palavras" );
  f = AbreFicheiro ( nome, "w" );
  for ( i = 0; i < (*t).n_dist_palavras; i++ ) {
    fprintf ( f, "%d: %s\n", (*t).ocorrencias[i], (*t).palavras[i] );
  }
  printf ( "Count of distinct words: %d\n", (*t).n_dist_palavras );
  fclose ( f );

  /* freeing memory*/
  free(nome);
  return;
}


/******************************************************************************
 * main()
 *
 * Arguments: argc - counter of number of arguments in call
 *            argv - pointer to array of strings holding the arguments
 * Returns: (none)
 * Side-Effects: none
 *
 * Description:
 *
 *****************************************************************************/

int main ( int argc, char **argv )
{
  int i;
  st_texto st_palavras;

  if ( argc < 2 ) {
    fprintf ( stderr, "ERROR: missing filename in argument!\n" );
    exit ( 6 );
  }

  AlocaTabelaPalavras ( argv[1], &st_palavras );
  PreencheTabelaPalavras ( argv[1],&st_palavras );
  EscreveFicheiro ( argv[1], &st_palavras );


  /* freeing memory */
  for (i = 0; i < st_palavras.n_total_palavras; i++)
    free(st_palavras.palavras[i]);
  
  free(st_palavras.ocorrencias);
  free(st_palavras.palavras); 
  return (0);
}
