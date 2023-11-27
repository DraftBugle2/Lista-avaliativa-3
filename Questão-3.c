#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower(*str);
        str++;
    }
}

int ultimoDigitoPlaca(char placadocarro[10]){
    return placadocarro[strlen(placadocarro) - 1] - '0';
}

void quantidadedeletraNumeros(char placadocarro[10], int* quantidadedeletra, int* quantidadenum){
    for (int i = 0; i < strlen(placadocarro); ++i) {
        if(isalpha(placadocarro[i])){
            *quantidadedeletra = *quantidadedeletra + 1;
        } if(isdigit(placadocarro[i])){
            *quantidadenum = *quantidadenum + 1;
        }
    }
}

void validaPlaca(char placadocarro[10], int quantidadedeletra, int quantidadenum, int* placasehvalida){
    char *contemhifem = strchr(placadocarro, '-');
    if(contemhifem != NULL){
        if(quantidadedeletra == 3 && quantidadenum == 4 && strlen(contemhifem) == 5){
            *placasehvalida = 1;
        }
    } else{ 
        if(quantidadedeletra == 4 && quantidadenum == 3){
            *placasehvalida = 1;
        }
    }
}

void validaSemana(char diadasemana[][14], char *diaSemana, int *diaehvalido){
    for (int i = 0; i < 7; i++) {
        if (strstr(diaSemana, diadasemana[i]) != NULL) {
            *diaehvalido = 1;
        }
    }
}

void verificaPlacaEDia(int diaehvalido, int placasehvalida){
    if(diaehvalido == 0 || placasehvalida == 0){
        if(placasehvalida == 0){
            printf("Placa invalida\n");
        }
        if(diaehvalido == 0){
            printf("Dia da semana invalido\n");
        }
        exit(0);
    }
}


int main(){
    char placadocarro[10], diaSemana[14], dianaopermitido[14];
    char diadasemana[][14] = {
          "DOMINGO", 
          "SEGUNDA-FEIRA", 
          "TERCA-FEIRA",
          "QUARTA-FEIRA",
           "QUINTA-FEIRA", 
          "SEXTA-FEIRA", 
            "SABADO"
    };
    int placasehvalida = 0, diaehvalido = 0, quantidadedeletra = 0, quantidadenum = 0;

    fgets(placadocarro, sizeof(placadocarro), stdin);
    placadocarro[strcspn(placadocarro, "\n")] = '\0';
    scanf("%s", diaSemana);


    quantidadedeletraNumeros(placadocarro, &quantidadedeletra, &quantidadenum);

        validaPlaca(placadocarro, quantidadedeletra, quantidadenum, &placasehvalida);


            validaSemana(diadasemana, diaSemana, &diaehvalido);

                 verificaPlacaEDia(diaehvalido, placasehvalida);

    switch (ultimoDigitoPlaca(placadocarro)) {
        case 0:
        case 1:
            strcpy(dianaopermitido, diadasemana[1]);
            break;
        case 2:
        case 3:
            strcpy(dianaopermitido, diadasemana[2]);
            break;
        case 4:
        case 5:
            strcpy(dianaopermitido, diadasemana[3]);
            break;
        case 6:
        case 7:
            strcpy(dianaopermitido, diadasemana[4]);
            break;
        case 8:
        case 9:
            strcpy(dianaopermitido, diadasemana[5]);
            break;
    }

    if (strcmp(diaSemana, diadasemana[0]) == 0 || strcmp(diaSemana, diadasemana[6]) == 0){
        printf("Nao ha proibicao no fim de semana\n");
    } else if(strcmp(diaSemana, dianaopermitido) != 0){
        toLowerCase(diaSemana);
        printf("%s pode circular %s\n", placadocarro, diaSemana);
    } else{
        toLowerCase(diaSemana);
        printf("%s nao pode circular %s\n", placadocarro, diaSemana);

    }
    return 0;
}