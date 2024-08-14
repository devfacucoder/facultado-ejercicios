#include  <stdio.h>

void cargar(int arrNums[]) {
    for(int i = 0; i < 20; i++) {
    	
        arrNums[i] = i;
    }
}

void mostrar(int arrNums[]) {
    for(int i = 0; i < 20; i++) {
        printf("\n %i", arrNums[i]);
    }
}
void haycero(int arrNums[]){
	for (int i = 0;i<20;i++){
		if(arrNums[i]==0){
			printf("\n hay un cero efectivamente");
		}
	}
}
void posicionesPares(int arrNums[]){
	for (int i =0;i<20;i+=2){
		printf("\n en la posicion %i esta el numero: %i",i,arrNums[i]);
		
	}
}
void cantidadPares(int arrNums[]){
	int ccp = 0;
	for(int i = 0;i<20;i++){
		if((arrNums[i] % 2 )==0){
			ccp++;
		}
	}
	printf("\n la cantidad de numeros pares es: %i",ccp);
	return;
}
int main() {
    int arrNums[20];
    cargar(arrNums);

    haycero(arrNums);
    printf("\n ----------");
   posicionesPares(arrNums);
   printf("\n----------");
    cantidadPares(arrNums);
   printf("\n----------");

    return 0;
}
