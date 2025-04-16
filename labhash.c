#include <stdio.h>
#include <stdlib.h>
#define tam_hash 11

typedef struct Celula{
int valor;
struct Celula* proximo;
}Celula;

typedef struct {
Celula* inicio;
}Lista;

typedef struct {
Lista* table[tam_hash];
}Hash;

Hash* start_hash(){
Hash* hash = malloc(sizeof(Hash));
for(int i = 0; i < tam_hash; i++){
Lista* lista = malloc(sizeof(Lista));
lista->inicio = NULL;
hash->table[i] = lista;
}
return hash;
}

void inserir_hash(Hash* hash, int valor){
Celula* nova = malloc(sizeof(Celula));
nova->valor = valor;
int lista = valor % tam_hash;
nova->proximo = hash->table[lista]->inicio;
hash->table[lista]->inicio = nova;
}

void remover_hash(Hash* hash, int valor){
int idx = valor % tam_hash;
Lista* lista = hash->table[idx];
Celula *anterior = NULL;
Celula *atual = lista->inicio;
while(atual != NULL && atual->valor != valor){
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
}

void imprimir(Hash* hash){
printf("---------------------\n");
for(int i = 0; i < tam_hash; i++){
Celula* atual = hash->table[i]->inicio;
printf("%d -> ", i);
while(atual != NULL){
printf("%d ", atual->valor);
atual = atual->proximo;
}
printf("\n");
}
printf("---------------------\n");
}

int main(void) {
Hash* hash = start_hash();
int valor;
while(1){
scanf("%d", &valor);
if(valor == 0)
break;
inserir_hash(hash, valor);
}
imprimir(hash);
while(1){
scanf("%d", &valor);
if(valor == 0)
break;
remover_hash(hash, valor);
}
imprimir(hash);
return 0;
}