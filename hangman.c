#include <stdio.h>
#include <string.h>

void abertura(){
    printf("/***************/\n");
    printf("/ Hangman Game /\n");
    printf("/***************/\n");
}
 
int main() {

    abertura();

    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");
 
    int acertou = 0, enforcou = 0, tentativas = 0;
    char chutes[26];

    do {//lógica de percorrer o alfabeto e comparar com a palavra e os chutes
        for(int i = 0; i < strlen(palavrasecreta); i++) {
            
            int achou = 0;

            for(int j = 0; j < tentativas; j++){ //a letra ja foi chutada?
                if(chutes[j] == palavrasecreta[i]){
                    achou = 1;
                    break;
                }
            }
            if(achou) {//se achou = 1 = verdade logo printa a letra chutada
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");
 
        char chute; //captura um novo chute
        printf("Qual letra? ");
        scanf(" %c", &chute);
 
        chutes[tentativas] = chute;
        tentativas++;
    } while (!acertou && !enforcou);

    return 0;
}