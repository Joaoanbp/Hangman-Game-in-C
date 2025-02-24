#include <stdio.h>
#include <string.h>
char palavrasecreta[20];
char chutes[26];
int tentativas = 0;

void abertura(){
    printf("/***************/\n");
    printf("/ Hangman Game /\n");
    printf("/***************/\n");
}
void chuta(){
    char chute;
    printf("Qual a letra? ");
    scanf(" %c", &chute);

    chutes[tentativas] = chute;
}
int jachutou(char letra){
    int achou = 0;                                                                                                  
    for(int j = 0; j < tentativas; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}
void desenhaforca(){
    printf("Voce ja deu %d chute\n", tentativas);

    for(int i = 0; i< strlen(palavrasecreta); i++){
        if(jachutou(palavrasecreta[i])){
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}
void escolhepalavra(){
    sprintf(palavrasecreta, "MELANCIA");
}

int main() {    
    int acertou = 0, enforcou = 0;
    
    abertura();
    escolhepalavra();

    do {        
        desenhaforca();
        chuta();

        tentativas++;
    } while (!acertou && !enforcou);

    return 0;
}