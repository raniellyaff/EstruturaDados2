#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
	int valor;
	struct Celula *proximo;
	struct Celula *anterior;
} Celula;

typedef struct {
	Celula *head;
	Celula *tail;
	int qtde;
} Queue;

Celula *cria_celula(int valor){
	Celula *celula = malloc(sizeof(Celula));
	celula->proximo = NULL;
	celula->anterior = NULL;
	celula->valor = valor;

	return celula;
}

Queue *cria_queue(){
	Queue *queue = malloc(sizeof(Queue));
	queue->head = NULL;
	queue->tail = NULL;
	queue->qtde = 0;

	return queue;
}

void enqueue(Queue *queue, int valor){
	Celula *nova = cria_celula(valor);
        if( queue->qtde == 0){
            queue->head = nova;
        }
        else{
            queue->tail->proximo = nova;
            nova->anterior = queue->tail;
	}
    queue->tail = nova;
    queue->qtde++;
}

int dequeue(Queue *queue){
	if(queue->qtde == 0){
        return 1;
    }
        Celula *liberar = queue->head;
        int valor = queue->head->valor;
        if(queue->qtde == 1){
        queue->head = NULL;
        queue->tail = NULL;
        
        } else{
            queue->head->proximo->anterior = NULL;
            queue->head = queue->head->proximo;
        }
        queue->qtde--;
        free(liberar);
        return valor;
}

void show(Queue *queue){
    Celula *atual = queue->head;
    while(atual != NULL){
    printf("%d", atual->valor);
    atual = atual->proximo;
    }
}

void show_invertido(Queue *queue){
	Celula *atual = queue->tail;
    while(atual != NULL){
    printf("%d", atual->valor);
    atual = atual->anterior;
    }
    printf("\n");
    }

int main(void) {
	Queue *qnum1 = cria_queue();
	Queue *qnum2 = cria_queue();
	Queue *res = cria_queue();
	
	char num1[100];
	char num2[100];
	fgets(num1, sizeof(num1), stdin);
	fgets(num2, sizeof(num2), stdin);

	int i = 0;
	while(num1[i] != '\n'){		
		enqueue(qnum1, (int)(num1[i]) - 48);
		enqueue(qnum2, (int)(num2[i]) - 48);
		i++;
	}
    
    Celula *n1 = qnum1->tail; // comeca de trás para frente
    Celula *n2 = qnum2->tail;

    int soma = 0; //iniciando as variáveis
    int carry = 0;

    while(n1 != NULL){ //se o numero 1 for diferente de nulo
        soma = n1->valor + n2->valor + carry; // soma o valor passado para 1 e o valor passado para 2
        if(soma > 9){ // se a soma for maior que 9, sendo 10 o estouro.
            soma = soma - 10; // pega a soma e subtrai 10
            carry = 1; // adiciona 1 no carry, como se fosse sobe 1
        }
        else{
            carry = 0; //caso não seja 1, o carry permanece em 0
        }
        enqueue(res, soma); //adiciona o valor da soma na lista
        n1 = n1->anterior; //coloca a celula atual como anterior
        n2 = n2->anterior; 
    }
    if(carry == 1){ //se o carry for 1 ele coloca na lista o 1 para completar a soma final.
        enqueue(res, 1); // adiciona na lista
    }

    show_invertido(res); //mostra a lista invertida, já que somamos de tras para frente.
	
}