#include <stdio.h>

int main() {
    int meses;
    double aporte, taxa, montante;

    
    scanf("%d", &meses);

    
    scanf("%lf", &aporte);

    
    scanf("%lf", &taxa);

    if (meses < 1 || meses > 240 || aporte < 1 || aporte > 5000 || taxa < 0.01 || taxa > 0.2) {
        printf("Valores fora das faixas especificadas.\n");
        return 1;  
    }

    for (int i = 1; i <= meses; i++) {
        montante += aporte;
        montante *= (1 + taxa);

        printf("Montante ao fim do mes %d: R$ %.2lf\n", i, montante);
    }

    return 0;
}
