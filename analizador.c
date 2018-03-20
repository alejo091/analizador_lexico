/*
*  Autor: Alejandro Castro
*
*  Temas Avanzados en Lenguajes de Programacion
*  2018-1
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FIPATH "/home/alejandro/Documents/Maestria/S3/Lenguajes_Programacion/taller1/testCases/0/in01.txt"
#define MAX_PAL_RESER		15
#define MAX_WORD_SIZE   10

char tokens_esp[25][25] = { "token_mayor","token_menor","token_mas","token_div",
                    "token_menos","token_mul","token_mod","token_mod",
                    "token_pot","token_not","token_assign","token_par_izq",
                    "token_par_der","token_llave_izq","token_llave_der",
                    "token_cor_izq","token_cor_der","token_coma","token_dosp"
                    "token_point"};

char pal_res[MAX_PAL_RESER][MAX_WORD_SIZE] = {"true","false","nil","if","else","while",
                		                        "log","for","in","funcion","end"
                		                        "retorno","importar","desde","todo"};

uint8_t pos;

uint8_t palabra_reservada(char buffer[])
{

    uint8_t flag = 0;

    for(pos = 0; pos < MAX_PAL_RESER; ++pos)
    {
        if(strcmp(pal_res[pos], buffer) == 0)
        {
            flag = 1;
            break;
        }
    }

    return flag;
}

int main()
{
    char operadores_especiales[] = "><+/-*%%^!=(){}[],:.";

    FILE *filein;
    FILE *fileout;
    filein = fopen("in01.txt","r");
    fileout = fopen("out.txt","w+");

    char chat_read;
    uint8_t i;
    uint8_t j;
    uint8_t char_ok;
    uint8_t char_esp;
    uint16_t fila = 1;
    uint16_t columna = 1;
    char buffer[50];

    if(filein == NULL){
        printf(">>>>No se encontro el archivo a abrir\n");
        exit(0);
    }

    while((chat_read = fgetc(filein)) != EOF)
    {
      while(chat_read == '#')
      {
        ++fila;
        chat_read = fgetc(filein);
      }
      char_ok = 1;
      char_esp = 0;
      /*
      * Look for [a-z], [A-Z] or [0-9] characters
      */
      if(isalnum(chat_read))
      {
        buffer[j++] = chat_read;
      }
      else
      {

        /*
        * Look for any special character
        */
        for(i = 0; i < 20; ++i)
        {
          if(chat_read == operadores_especiales[i])
          {
            char_esp = 1;
            break;
          }
        }

        if(char_esp == 1)
        {
          if(palabra_reservada(buffer) == 1)
          {
            buffer[j]='\0';
            fprintf(fileout, "<%s,%d,%d>\n", pal_res[pos], fila, columna-j);
            for(uint8_t i = 0;i < sizeof(buffer); ++i)buffer[i]='\0';
            j = 0;
          }
          fprintf(fileout, "<%s,%d,%d>\n", tokens_esp[i], fila, columna);
        }

        if(chat_read == 0x0A || chat_read == 0x0D || chat_read == 0x20 || chat_read == 0x09)
        {
          if(palabra_reservada(buffer) == 1)
          {
            buffer[j]='\0';
            fprintf(fileout, "<%s,%d,%d>\n", pal_res[pos], fila, columna-j);
            for(uint8_t i = 0;i < sizeof(buffer); ++i)buffer[i]='\0';
            j = 0;
          }
          if(chat_read == 0x0A)
          {
            ++fila;
            columna = 0;
          }
        }
        else
        {
          if(char_esp == 0)
          {
            char_ok = 0;
          }
        }
      }
      if(char_ok == 0)
      {
        printf("\n--- char read: %d",chat_read);
        printf("\n>>>>Error lexico(linea:%d,posicion:%d)\n",fila,columna);
        return 1;
      }
      else
      {
        putchar(chat_read);
      }
      ++columna;
    }

    fclose(filein);

    return 0;
}
