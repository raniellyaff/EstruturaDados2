#include <stdio.h>
#include <stdlib.h>

typedef struct Celula{
    struct Celula *anterior;
    struct Celula *proximo;
    int valor;
} Celula;

typedef struct {
    Celula *primeiro;
    int qtd;
} LDDE;

Celula *criar_celula(int valor){
    Celula *novo = malloc(sizeof(Celula));
    novo->anterior = NULL;
    novo->proximo = NULL;
    novo->valor = valor;
    return novo;
}

LDDE *criar_lista(){
    LDDE *lista = malloc(sizeof(LDDE));
    lista->primeiro = NULL;
    lista->qtd = 0;
    return lista;
}

void inserir(LDDE *lista, int valor){
    Celula *novo = criar_celula(valor);
    Celula *anterior = NULL;
    Celula *atual = lista->primeiro;

    while (atual != NULL && atual->valor < novo->valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(anterior == NULL){ //INSERIR NO INICIO
        lista->primeiro = novo;
        if(atual != NULL){
            novo->proximo = atual;
            atual->anterior = novo;
        }
    } else if(atual == NULL){ //INSERIR NO FINAL
        anterior->proximo = novo;
        novo->anterior = anterior;
    } else{ //INSERIR NO MEIO
        anterior->proximo = novo;
        novo->anterior = anterior;
        novo->proximo = atual;
        atual->anterior = novo;
    }
    lista->qtd++;
}

void mostrar(LDDE *lista){
    Celula *atual = lista->primeiro;

    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main(){
    LDDE *lista = criar_lista();
    inserir(lista, 12); //inicio em lista vazia
    mostrar(lista);
    inserir(lista, 8); //inicio em lista não vazia
    mostrar(lista);
    inserir(lista, 18);// final
    mostrar(lista);
    inserir(lista, 15);
    mostrar(lista);

    return 0;
}