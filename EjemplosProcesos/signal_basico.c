#include <stdio.h>
#include <signal.h>

void f_alarma(); // Implementada mas abajo...

void main()
{
    long i;

    // Programo la rutina de atención al signal: f_alarma
    signal(SIGALRM, f_alarma);

    // Y programo una alarma para dentro de 1 segundo
    alarm(1);

    // Ahora se supone que el proceso se dedica a hacer
    // cualquier tarea que no tiene nada que ver con el tiempo.
    // Por ejemplo, aqui hay un bucle infinito que escribe por
    // pantalla.
    while(1) {
	// Le ponemos un retardo, para que de tiempo
	// para ver visualmente los mensajes
	for( i = 0; i < 20000000; i++);
	printf("Estoy haciendo cierta tarea...\n");
    }

    // Para acabar la ejecución, pulsa ^C
}

void f_alarma()
{
    // Escribo mensaje de tiempo
    // y reprogramo la alarma de reloj
    printf("\n**************\n");
    printf("*** TIEMPO ***\n");
    printf("**************\n\n");
    alarm(1);
}
