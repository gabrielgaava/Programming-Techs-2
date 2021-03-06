#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int key;
    char data;
    struct node *next;
} typedef Node;

Node * top;

void push(char data){
    Node * temp;
    temp = (Node*)malloc(sizeof(Node));

    temp->data = data;
    temp->next = top;

    top = temp;
}

char pop(){

    Node * temp;
    char removed;

    if(top != NULL){
        removed = top->data;
        temp = top;
        top = top->next;
        temp->next = NULL;

        free(temp);
    }

    return removed;

}

int verify(char input, char onTop){
    if(input == ')' && onTop == '(') return 1;
    if(input == ']' && onTop == '[') return 1;
    if(input == '}' && onTop == '{') return 1;
    return 0;
}

int main() {

    char input[10000];
    int i = 0;
    int flag = 0;

    scanf("%s", input);


    while(input[i] != '\0' && flag != 1){
        
        if(input[i] == '(' || input[i] == '[' || input[i] == '{'){
            push(input[i]);
        } 

        else if(input[i] == ')' || input[i] == ']' || input[i] == '}'){
            char onTop = pop();
            if(verify(input[i], onTop) == 0) { 
                flag = 1; 
                break; 
            }
        }

        i++;

    }

    if(top != NULL) flag = 1;

    if(flag) {
        printf("N\n");
    } else {
        printf("S\n");
    }
    

    return 0;
}
