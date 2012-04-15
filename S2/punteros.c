#include <stdio.h>
#include <stdlib.h>
#define SIZE_BUFF 4

void imprime_buff(void *aux, int size)
{
	int i;
	// Ya que "aux" es un tipo de datos void y por tanto nos permite
	// pasar cualquier tipo de datos debemos mantener una coherencia 
	// en el cast que se realice para usar dicho parámetro
	int *buff = (int *)aux;
	// Al ser un puntero, en C siempre podemos usarlo como un vector
	// EL compilador sabe que es un puntero a entero, por lo tanto 
	// calcula el tamaño de cada elemento
	printf("Accedemos a traves de buff[i]\n");
	for (i = 0; i < size; i++)
		printf("En la posicion %d hay %d\n", i, buff[i]);

	// Y es lo mismo que hacer esto. Al ser un puntero el compilador no 
	// le suma 1, sino el tamaño de cada elemento
	// EL operados * accede a lo apuntado por el puntero, el contenido
	printf("Accedemos a traves de *buff\n");
	for (i = 0; i < size; i++) {
		printf("En la posicion %d hay %d\n", i, *buff);
		buff++;
	}
}

int main(int argc, char *argv[])
{
	int a;			// a es un entero
	int buff_int[SIZE_BUFF];	//buff_int un vector de enteros
	int *pbuff_int;		//pbuff_int es un puntero a entero( o enteros) SIN INICIALIZAR
	char b;			// b es un caracter
	char *pb;		// pb es puntero a caracter SIN INICIALIZAR
	char buff_c[SIZE_BUFF];	// buff_c es un vector de carateres

	int i;

	// Inicializamos el vector
	for (a = 0; a < SIZE_BUFF; a++)
		buff_int[a] = a;

	// Accederemos a traves del puntero
	// esto es igual a pbuff_int=&buff_int[0], el compilador 
	// lo hace automatiamente, el simbolo & es para obtener la direccion
	// pero en el caso de los vectores no es necesario ponerlo
	pbuff_int = buff_int;

	// Comprobad que es lo mismo
	printf("Puntero %x buff_int=%x &buff_int[0]=%x\n", pbuff_int, buff_int, &buff_int[0]);
	printf("Usamos el puntero pbuff_int-------------------\n");
	imprime_buff((void *)pbuff_int, SIZE_BUFF);
	printf("Usamos el vector buff_int-------------------\n");
	imprime_buff((void *)buff_int, SIZE_BUFF);

	// CUando los punteros no estan inicializados , podrian valer 
	// cualquier cosa, desde una direccion valida, de casualidad, a 0 
	// y provocar un fallo en el programa
	printf("Puntero sin inicializar pb=%x\n", pb);
	printf("Apuntamos a una zona segura pb=&b \n");
	pb = &b;
	b = 'H';
	printf("Puntero inicializado pb=%x, &b=%x b=%c *pb=%c\n", pb, &b, b, *pb);

	printf("Veamos como el compilador interpreta el tipo de los punteros....\n");
	printf("Los punt a enteros se incrementan en 4 y los de chars en 1 automaticamente\n");
	pb = buff_c;
	printf("ENTEROS\n");
	for (i = 0; i < SIZE_BUFF; i++) {
		printf("Direccion %d de buff de enteros %x\n", i, pbuff_int);
		pbuff_int++;
	}
	printf("CHARS \n");
	for (i = 0; i < SIZE_BUFF; i++) {
		printf("Direccion %d de buff de caracteres %x\n", i, pb);
		pb++;
	}

}
