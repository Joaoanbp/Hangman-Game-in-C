#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura(){
    printf("/***************/\n");
    printf("/ Hangman Game /\n");
    printf("/***************/\n");
}

void chuta(){
    char chute;
    printf("Qual a letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

int jachutou(char letra){
    int achou = 0;                                                                                                  
    for(int j = 0; j < chutesdados; j++){
        if(chutes[j] == letra){
            achou = 1;
            break;
        }
    }
    return achou;
}

void desenhaforca(){
    printf("Voce ja deu %d chute\n", chutesdados);

    for(int i = 0; i< strlen(palavrasecreta); i++){
        if(jachutou(palavrasecreta[i])){
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void adcionapalavra(){
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &quer);

    if(quer == 'S'){
        char novapalavra[20];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novapalavra);

        //abre o arquivo de texto para escrita de dados
        
        FILE* f;
        
        f = fopen("palavras.txt", "r+");

        if(f == 0){
            printf("Banco de dados de palavras não disnpon´ivel\n\n");
            exit(1);
        }

        int qtd;
        fscanf(f, "%d", &qtd);
        qtd++;
        fseek(f, 0, SEEK_SET);
        fprintf(f,"%d",qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", novapalavra);

        fclose(f);
    }
}

void escolhepalavra(){
    FILE* f;

    f = fopen("palavras.txt", "r");
    if(f == 0){
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }
    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++){
        fscanf(f, "%s", palavrasecreta);
    }
    fclose(f);
}

int enforcou(){
    int erros = 0;

    for(int i = 0; i < chutesdados; i++){
        int existe = 0;
        for(int j = 0; j < strlen(palavrasecreta); j++){
            if(chutes[i] == palavrasecreta[j]){
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros >= 5;
}

int ganhou(){
    for(int i = 0; i < strlen(palavrasecreta); i++){
        if(!jachutou(palavrasecreta[i])){
            return 0;
        }
    }
    return 1;
}

int main() {    
    abertura();
    escolhepalavra();

    do {        
        desenhaforca();
        chuta();
        enforcou();

    } while (!ganhou() && !enforcou());
    
    adcionapalavra();

    return 0;
}