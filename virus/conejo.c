#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int max_procesos = 20;
    
    printf("=== INICIANDO PROCESO PADRE PRINCIPAL (PID: %d) ===\n", getpid());

    for (int i = 1; i <= max_procesos; i++) {
        pid_t pid = fork(); // Aquí ocurre la magia: el proceso se duplica

        if (pid < 0) {
            // Si devuelve un número negativo, hubo un error al crear el proceso
            perror("Error al bifurcar (fork)");
            exit(1);
        } 
        else if (pid == 0) {
            // === CÓDIGO DEL PROCESO HIJO ===
            // Cada vez que nace un hijo, imprime su información y termina.
            printf("[Hijo %d] ¡Nací! Mi PID es %d y mi padre es %d\n", i, getpid(), getppid());
            
            // Importante: El hijo DEBE terminar aquí con exit() para no seguir 
            // en el ciclo for y empezar a crear sus propios hijos de forma descontrolada.
            exit(0); 
        } 
        else {
            // === CÓDIGO DEL PROCESO PADRE ===
            // El padre solo espera 1 segundo antes de iterar y crear al siguiente hijo.
            printf("[Padre] Creado hijo número %d con PID: %d\n", i, pid);
            sleep(1); // Cumple el requisito: 1 proceso por segundo
        }
    }

    // Al final del ciclo, el padre espera a que todos sus hijos terminen
    for (int i = 0; i < max_procesos; i++) {
        wait(NULL);
    }

    printf("=== Proceso padre finalizado de forma segura. ===\n");
    return 0;
}