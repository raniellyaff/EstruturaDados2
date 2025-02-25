#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó na lista duplamente encadeada
typedef struct no {
    int valor;
    struct no *anterior;
    struct no *proximo;
} No;

// Definição da estrutura da lista duplamente encadeada
typedef struct lista_duplamente_encadeada {
    int quantidade;
    No *inicio;
} ListaDuplamenteEncadeada;

/**
 * Cria uma nova lista duplamente encadeada e a inicializa.
 *
 * @return Um ponteiro para a nova lista criada.
 */
ListaDuplamenteEncadeada *criar_lista() {
    ListaDuplamenteEncadeada *lista = malloc(sizeof(ListaDuplamenteEncadeada));
    lista->inicio = NULL;
    lista->quantidade = 0;
    return lista;
}

/**
 * Cria um novo nó contendo o valor especificado.
 *
 * @param valor O valor a ser armazenado no nó.
 * @return Um ponteiro para o novo nó criado.
 */
No *criar_no(int valor) {
    No *novo_no = malloc(sizeof(No));
    novo_no->valor = valor;
    novo_no->anterior = NULL;
    novo_no->proximo = NULL;
    return novo_no;
}

/**
 * Insere um valor na lista de forma ordenada.
 *
 * @param lista Ponteiro para a lista onde o valor será inserido.
 * @param valor O valor a ser inserido na lista.
 */
void inserir_valor(ListaDuplamenteEncadeada *lista, int valor) {
    No *novo = criar_no(valor);
    No *anterior = NULL;
    No *atual = lista->inicio; 

    while (atual != NULL && atual->valor < novo->valor){
        anterior = atual;
        atual = atual->proximo;
    }
    if(anterior == NULL){ //INSERIR NO INICIO
        lista->inicio = novo;
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
    lista->quantidade++;
}

/**
 * Exibe os valores da lista em ordem crescente.
 *
 * @param lista Ponteiro para a lista a ser exibida.
 */
void exibir_lista(ListaDuplamenteEncadeada *lista) {
    No *atual = lista->inicio;
    printf("Início -> ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("<- Final");
    printf("\n");
}

/**
 * Exibe os valores da lista em ordem decrescente.
 *
 * @param lista Ponteiro para a lista a ser exibida.
 */
void exibir_lista_invertida(ListaDuplamenteEncadeada *lista) {
    No *atual = lista->inicio;
    while(atual != NULL && atual->proximo != NULL){
        atual = atual->proximo;
    }
    printf("Final -> ");
    while(atual != NULL){
        printf("%d ", atual->valor);
        atual = atual->anterior;
    }
    printf("<- Início");
    printf("\n");
}

/**
 * Remove o nó que contém o valor especificado da lista.
 *
 * @param lista Ponteiro para a lista de onde o valor será removido.
 * @param valor O valor a ser removido da lista.
 */
void remover_valor(ListaDuplamenteEncadeada *lista, int valor) {
    No *anterior = NULL;
    No *atual = lista->inicio;
    while(atual != NULL && atual->valor < valor){
        anterior = atual;
        atual = atual->proximo;
        }
        if(atual == NULL){
        return;
        }
        if(anterior == NULL){
        lista->inicio = atual->proximo;
        }
        else{
        anterior->proximo = atual->proximo;
    }
    free(atual);
    lista->quantidade--;
    }

int main(void) {
    ListaDuplamenteEncadeada *lista = criar_lista();

    inserir_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 5);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 20);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 15);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 5);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 15);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 20);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    for (int i = 1; i <= 10; i++) {
        inserir_valor(lista, i);
    }
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    for (int i = 1; i <= 10; i++) {
        remover_valor(lista, i);
    }
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    remover_valor(lista, 100);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    inserir_valor(lista, 10);
    inserir_valor(lista, 10);
    inserir_valor(lista, 10);
    exibir_lista(lista);
    exibir_lista_invertida(lista);

    return 0;
}
