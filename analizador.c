/*
*  Autor: Alejandro Castro
*  
*  Temas Avanzados en Lenguajes de Programacion
*  2018-1
*/

#include <stdio.h>
#include <stdint.h>
#include "reservados_especiales.h"

#define FIPATH "/home/alejandro/Documents/Maestria/S3/Lenguajes_Programacion/taller1/testCases/0/in01.txt"
#define	MAX_WORD_SIZE	255

FILE *filein;
FILE *fileout;

uint16_t fila;
uint16_t columna;
char current_word[MAX_WORD_SIZE];
















/*
int main()
{
  filein = fopen("in01.txt","r");
  fileout = fopen("out.txt","w+");

  int chat_read;
  uint8_t letter = 0;
  uint8_t palres = 0;
  uint8_t char_ok = 0;

  while ((chat_read = getc(filein)) != EOF)
  {
    char_ok = 0;
    palres = 0;

    current_word[letter] = chat_read;

  
    for(uint8_t ches = 0; ches < MAX_CHAR_ESP; ++ches)
    {
      if(current_word[letter] == (intptr_t)char_esp[ches])
      {
        char_ok = 1;
        break;
      }
    }

    for(uint8_t chesdo = 0; chesdo < MAX_CHAR_ESP_DOB; ++chesdo)
    {
      if(current_word == char_esp_dob[chesdo])
      {
        char_ok = 1;
        break;
      }
    }

    if(char_ok == 0)
    {
      printf(">>>>Error lexico(linea:%d,posicion:%d)\n",1,2);
      return 1;
    }

    putchar(current_word[letter]);
    ++letter;   
  }

  for(uint8_t i = 0; i < 100; ++i) putchar(current_word[i]);

  fprintf(fileout, "This is testing for fprintf...\n");
  fputs("This is testing for fputs...\n", fileout);

  fclose(filein);
  fclose(fileout);

  return 0;
}
*/

