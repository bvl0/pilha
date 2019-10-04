#include<stdio.h>
#include<stdlib.h>
#include"fila.h"
#include"pilha.h"

struct fila{
    Pilha *princ,*aux;
};

// typedef struct fila Fila;

Fila* cria_fila(void){
    Fila *nova;
    nova = malloc(sizeof(Fila));
    nova -> princ = cria_pilha();
    nova -> aux = cria_pilha();
    return nova;

}
void insere (Pessoa* pessoa, Fila* f){
    if(f != NULL && pessoa != NULL){
        push(pessoa,f -> princ);
    }
}
Pessoa* retira (Fila* f){
    Pessoa *retirado;
    if (f!= NULL){
        while(!vazia_pilha(f -> princ)){
        push(pop(f -> princ),f -> aux);
    }
        retirado = pop(f->aux);
        while(!vazia_pilha(f ->aux)){
            push(pop(f -> aux),f -> princ); 
        }

        return retirado;
    }
    
    return NULL;
}

void imprime_fila(Fila* f){
    if(f!=NULL){
        while(!vazia_pilha(f -> princ)){
            push(pop(f -> princ),f -> aux);
        }
        imprime_pilha(f->aux);
        while(!vazia_pilha(f ->aux)){
         
            push(pop(f -> aux),f -> princ);
        }
    }
}

int Vazia_fila (Fila* f){
    if(vazia_pilha(f -> princ)&&vazia_pilha(f -> aux)){
        return 1;
    }
    else
        return 0;
}

void separa_filas (Fila* f, Fila* f_maiores, Fila* f_menores){
    Pessoa *aux;
    while(!vazia_pilha(f -> princ)){
        push(pop(f -> princ),f -> aux);
    }
    aux= pop(f -> aux);
    while(!vazia_pilha(f -> aux)){
        aux= pop(f -> aux);

        if(retorna_idade(aux) >60){
            insere(aux,f_maiores);
        }
        else 
            insere(aux , f_menores);
    }
}
Fila* destroi_fila (Fila* f){
  destroi_pilha(f -> princ);
  destroi_pilha(f -> aux);
  free(f);
}
