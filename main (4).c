#include <stdio.h>

#define MAX_MAQUINAS 5
#define GANANCIA_MINIMA 500

struct Maquina {
    int id;
    long jugadas;
    long ganancias;
    long perdidas;
    long tiempoUso;
};

void cargarDatos(struct Maquina maquinas[], int *cantidad);
void evaluarMaquinas(struct Maquina maquinas[], int cantidad);

void cargarDatos(struct Maquina maquinas[], int *cantidad)
{
    int i;

    do {
        printf("Introduce el numero de maquinas (1-5): ");
        scanf("%d", cantidad);
    } while (*cantidad < 1 || *cantidad > MAX_MAQUINAS);

    for (i = 0; i < *cantidad; i++) {
        printf("\nMAQUINA %d\n", i + 1);

        maquinas[i].id = i + 1;

        printf("Jugadas: ");
        scanf("%ld", &maquinas[i].jugadas);

        printf("Ganancias: ");
        scanf("%ld", &maquinas[i].ganancias);

        printf("Perdidas: ");
        scanf("%ld", &maquinas[i].perdidas);

        printf("Tiempo: ");
        scanf("%ld", &maquinas[i].tiempoUso);
    }
}

void evaluarMaquinas(struct Maquina maquinas[], int cantidad)
{
    int i;
    long promedioCentimos;
    long parteEntera;
    long parteDecimal;
    long totalJugadas = 0;
    long totalGanancias = 0;
    long totalPerdidas = 0;

    printf("\nEVALUACION DE MAQUINAS\n");

    for (i = 0; i < cantidad; i++) {
        promedioCentimos = (maquinas[i].ganancias * 100L) / maquinas[i].jugadas;
        parteEntera = promedioCentimos / 100L;
        parteDecimal = promedioCentimos % 100L;

        printf("\nMaquina %d\n", maquinas[i].id);
        printf("Promedio: %ld.%02ld\n", parteEntera, parteDecimal);

        if (maquinas[i].ganancias >= GANANCIA_MINIMA)
            printf("Clasificacion: Maquina rentable.\n");
        else
            printf("Clasificacion: Revisar rendimiento.\n");

        totalJugadas = totalJugadas + maquinas[i].jugadas;
        totalGanancias = totalGanancias + maquinas[i].ganancias;
        totalPerdidas = totalPerdidas + maquinas[i].perdidas;
    }

    printf("\nRESUMEN GENERAL DEL CASINO\n");
    printf("Total de jugadas: %ld\n", totalJugadas);
    printf("Total de ganancias: %ld\n", totalGanancias);
    printf("Total de perdidas: %ld\n", totalPerdidas);

    if (totalGanancias > totalPerdidas)
        printf("Resultado general: Operacion favorable.\n");
    else
        printf("Resultado general: Revisar estrategia.\n");
}

void main()
{
    struct Maquina maquinas[MAX_MAQUINAS];
    int cantidad;

    printf("SISTEMA DE GESTION DE MAQUINAS DE CASINO\n\n");

    cargarDatos(maquinas, &cantidad);
    evaluarMaquinas(maquinas, cantidad);

    printf("\nPrograma finalizado.\n");
}
