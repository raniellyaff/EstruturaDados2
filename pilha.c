#include <stdio.h>
#include <stdlib.h>
typedef struct Celula {
struct Celula *anterior;
int valor;
struct Celula *proximo;
} Celula;

typedef struct {
Celula *topo;
int qtd;
} Pilha;

Celula *criar_celula(int valor){
Celula *nova = malloc(sizeof(Celula));
nova->anterior = NULL;
nova->proximo = NULL;
nova->valor = valor;
return nova;
}

Pilha *criar_pilha(){
Pilha *pilha = malloc(sizeof(Pilha));
pilha->qtd = 0;
pilha->topo = NULL;
return pilha;
}

void push(Pilha *pilha, int valor){
Celula *nova = criar_celula(valor);
if(pilha->qtd > 0){
pilha->topo->proximo = nova;
nova->anterior = pilha->topo;
}
pilha->topo = nova;
pilha->qtd++;
}

void pop(Pilha *pilha){
if(pilha->qtd == 0){
return;
}
else if(pilha->qtd == 1){
pilha->topo = NULL;
}
else{
pilha->topo->anterior->proximo = NULL;
pilha->topo = pilha->topo->anterior;
pilha->qtd--;
}
}

void mostrar(Pilha *pilha){
Celula *atual = pilha->topo;
printf("TOPO -> ");
while(atual != NULL){
printf("%d ", atual->valor);
atual = atual->anterior;
}
printf(" <- BASE\n");
}

int main(){
Pilha *pilha = criar_pilha();
for(int i = 0; i < 10; i++){
push(pilha, i);
mostrar(pilha);
}
for(int i = 0; i < 10; i++){
pop(pilha);
mostrar(pilha);
}
return 0;
}