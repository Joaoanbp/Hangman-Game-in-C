#include <stdio.h>
#include <string.h>

void abertura(){
    printf("/***************/\n");
    printf("/ Hangman Game /\n");
    printf("/***************/\n");
}
void chuta(char chutes[], int* tentativas){
    char chute;
    printf("Qual a letra? ");
    scanf(" %c", &chute);

    chutes[*tentativas] = chute;
    (*tentativas)++;
}
void jachutou(char letra, char* chutes, int tentativas){
    for(int j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
}
int main() {

    abertura();

    char palavrasecreta[20];
    sprintf(palavrasecreta, "MELANCIA");
 
    int acertou = 0, enforcou = 0, tentativas = 0;
    char chutes[26];

    do {//imprime a palavra secreta
        for(int i = 0; i < strlen(palavrasecreta); i++) {
            int achou = 0;

           jachutou(palavrasecreta[i], chutes, tentativas);
           
            if(achou) {//se achou = 1 = verdade logo printa a letra chutada
                printf("%c ", palavrasecreta[i]);
            } else {
                printf("_ ");
            }
        }
        printf("\n");

        chuta(chutes, tentativas);

        printf("Voce ja deu %d chutes\n", tentativas);

    } while (!acertou && !enforcou);

    return 0;
}