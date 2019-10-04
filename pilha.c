#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"pilha.h"
struct pessoa{
    char *nome;
    int idade;
    char *endereco;
};

struct pilha{
    Pessoa* VetPilha[10];
    int topo;
};

Pilha* cria_pilha(){
    Pilha *nova;
    nova = malloc(sizeof(Pilha));
    nova -> topo=0;
    return nova;
}
Pilha* FpVazia(Pilha *pilha){
    pilha -> topo = 0;
}
void push(Pessoa *pessoa, Pilha *pilha){
    if(pilha != NULL && pilha -> topo < 10){
        pilha -> VetPilha[pilha -> topo]=pessoa;
        pilha -> topo++;
    }
    
}
Pessoa* pop(Pilha* pilha){
    if(pilha != NULL){
        pilha -> topo--;
        return pilha->VetPilha[pilha->topo];
    }
    return NULL;
}
Pilha* destroi_pilha(Pilha* pilha){
    if(pilha != NULL){
        for(int i=0;i<pilha -> topo;i++){
            free(pilha -> VetPilha[i]->nome);
            free(pilha -> VetPilha[i]->endereco);
        }
        free(pilha);
    
    }
return pilha;
}
int vazia_pilha(Pilha* pilha){
    if(pilha != NULL){
        if(pilha -> topo == 0)
        {
            return 1;
        }
        else return 0;
    }
}
int tamanho_pilha(Pilha* pilha){
    return pilha -> topo;
}
Pessoa* inicializaPessoa(char* nome, int idade, char* endereco){
    Pessoa *pessoa;
    pessoa=malloc(sizeof(Pessoa));
    pessoa -> nome = strdup(nome);
    pessoa -> idade = idade;
    pessoa -> endereco = strdup(endereco);
    return pessoa;

}

void imprime_pilha(Pilha* pilha){
    for(int i=0;i<pilha-> topo;i++){
        puts(pilha->VetPilha[i]->nome);
    }
}
void imprimepessoa(Pessoa* p){
    if(p != NULL){
        puts(p->nome);
        printf("idade : %i",p->idade);
        puts(p->endereco);
    }
}
int retorna_idade (Pessoa* p){
    if(p!=NULL){
        return p -> idade;
    }
}


