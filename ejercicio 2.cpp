#include  <stdio.h>
#include <string.h>


void cambiarCaracter(char cad[]){
	
	for(int i = 0;i<(strlen(cad));i++){
		if(cad[i]=='3'){
			cad[i] = '9';
		}
	}
	
}
void copiarPalabra(const char *src, char *dest, size_t n) {//Recordatorio estudiar estos parametros
    strncpy(dest, src, n);
    dest[n] = '\0';  // Asegura que la cadena esté correctamente terminada
}
void contarVocolaesMejorado(const char cad[]) {//mejorado segun chat-GPT
    // Usar un array booleano para verificar la presencia de vocales
    int vocales[256] = {0}; // Asumimos ASCII, 256 es el número de caracteres ASCII
    vocales['a'] = 1;
    vocales['e'] = 1;
    vocales['i'] = 1;
    vocales['o'] = 1;
    vocales['u'] = 1;
    vocales['A'] = 1; // Para manejar mayúsculas
    vocales['E'] = 1;
    vocales['I'] = 1;
    vocales['O'] = 1;
    vocales['U'] = 1;

    int cont = 0;
    for(int i = 0; i < strlen(cad); i++) {
        if(vocales[(unsigned char)cad[i]]) {
            cont++;
        }
    }
    printf("\nLa cantidad de vocales es: %i\n", cont);
}

void contarVocales(char cad[]){//esta la hice yo
	char vocales[5] ={'a','e','i','o','u'};
	int cont = 0;
	for(int i = 0;i<strlen(cad);i++){
		for(int j = 0;j<5;j++){
			if(cad[i]==vocales[j]){
				cont++;
			}
		}
		
	}
	printf("\n la cantidad de vocales es: %i",cont);
	
}
int main(){
	
	char cadena[] = {"Programacion Procedural 2023"};
	char prog[20];
	copiarPalabra(cadena,prog,11);
	printf("%s\n",cadena);// aca hay que poner "%s\n" para imprimir cadenas modificadas
	printf("la nueva cadena es: %s\n",prog);
	contarVocales(cadena);
	return 0;
}

