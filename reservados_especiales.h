/*
*  Autor: Alejandro Castro
*  
*  Temas Avanzados en Lenguajes de Programacion
*  2018-1
*/

#define MAX_PAL_SERVER		16
#define MAX_CHAR_ESP		18
#define MAX_CHAR_ESP_DOB	6

const char *palabras_reservadas[MAX_PAL_SERVER] = {
		"true","false","nil","if","else","while",
		"log","for","in","funcion","end"
		"retorno","importar","desde","todo","."
		};

const char *char_esp[MAX_CHAR_ESP] = {
		">","<","+","-","*","/","%%","^","!",
		"=","(",")","{","}","[","]",",",":"
		};

const char *char_esp_dob[MAX_CHAR_ESP_DOB] = {
		"||","&&","==","!=",">=","<="
		};
