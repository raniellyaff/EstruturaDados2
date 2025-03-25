#include <stdio.h>
#include <stdlib.h>
typedef struct Cell {
struct Cell *anterior;
struct Cell *proximo;
char valor;
} Cell;

typedef struct {
Cell *top;
int qtde;
} Stack;

Cell *start_cell(char valor) {
Cell *nova = malloc(sizeof(Cell));
nova->anterior = NULL;
nova->proximo = NULL;
nova->valor = valor;
return nova;
}

Stack *start_stack() {
Stack *stack = malloc(sizeof(Stack));
stack->qtde = 0;
stack->top = NULL;
return stack;
}

void push(Stack *stack, char valor) {
Cell *nova = start_cell(valor);
if (stack->qtde != 0) {
nova->proximo = stack->top;
stack->top->anterior = nova;
}
stack->top = nova;
stack->qtde++;
}

char pop(Stack *stack) {
if (stack->qtde > 0) {
char valor = stack->top->valor;
Cell *top = stack->top;
stack->top = stack->top->proximo;
if (stack->top != NULL)
stack->top->anterior = NULL;
stack->qtde--;
free(top);
return valor;
} else {
return 'x';
}
}

int main(void) {
Stack *parenteses = start_stack();
Stack *colchetes = start_stack();
Stack *chaves = start_stack();

int flag_parenteses = 0;
int flag_colchetes = 0;
int flag_chaves = 0;

char expr[100];
fgets(expr, sizeof(expr), stdin);
for(int i = 0; expr[i] != '\0'; i++) {
if(expr[i] == '('){
push(parenteses, expr[i]);
}
else if(expr[i] == ')'){
if(pop(parenteses) == 'x'){
flag_parenteses = 1;
break;
}
else{
pop(parenteses);
flag_parenteses = 0;
}
}
if(expr[i] == '[' && parenteses->qtde == 0){
push(colchetes, expr[i]);
}
else if(expr[i] == ']'){
if(pop(colchetes) == 'x' || parenteses->qtde != 0){
flag_colchetes = 1;
break;
}
else{
pop(colchetes);
flag_colchetes = 0;
}
}
if(expr[i] == '{' && colchetes->qtde == 0){
push(chaves, expr[i]);
}
else if(expr[i] == '}'){
if(pop(chaves) == 'x'){
flag_chaves = 1;
break;
}
else{
pop(chaves);
flag_chaves = 0;
}
}
}
if(flag_parenteses == 0 && flag_colchetes == 0 && flag_chaves == 0){
printf("correto");
}
else{
printf("incorreto");
}

return 0;
}