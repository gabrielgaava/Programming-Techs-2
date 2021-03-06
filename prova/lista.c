#include <stdio.h>
#include <stdlib.h>


struct node { 
    int key; 
    int age;
    int time;
    struct node* next; 
    struct node* prev; 
} typedef Node;

struct queue { 
    Node *front, *rear; 
} typedef Queue; 

struct person {
    int age; 
    int time;
} typedef Person;

Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue)); 
    
    queue->front = NULL;
    queue->rear = NULL;
    
    return queue;
} 

Node* addNode(int age, int time) {
    Node *temporary = (Node*)malloc(sizeof(Node)); 
    
    temporary->key = 0;
    temporary->age = age;
    temporary->time = time;
    temporary->next = NULL; 
    temporary->prev = NULL; 
    
    return temporary; 
}

void push(Queue* queue, int age, int time) {
    Node* temporary = addNode(age, time);
  
    if (queue->rear == NULL) { 
        queue->front = temporary;
        queue->rear = temporary;

        return;
    }

    if(age > 59) {

        Node *prev = temporary;
        while (temporary != queue->rear) {
            
        }
        
    }

    queue->rear->next = temporary;
    queue->rear->prev = NULL;
    queue->rear = temporary;
} 

void pop(Queue* queue) {
    if (queue->front == NULL) return; 
  
    Node* temporary = queue->front; 
  
    queue->front = queue->front->next;
  
    if (queue->front == NULL) queue->rear = NULL; 
  
    free(temporary); 
}

void print(Queue *queue) {
    Node *node = queue->front;

    while(node != NULL) {
        printf("%d ", node->age);

        node = node->next;
    }
}

int main(int argc, char const *argv[])
{   
    Queue* queue = createQueue();
    int input, age, time;

    scanf("%d", &input);

    Person entryQueue[input];

    for(int i = 0; i < input; i++){
        scanf("%d %d\n", &age, &time);
        entryQueue[i].age = age;
        entryQueue[i].time = time;
    }

    puts("\n");

    for(int i = 0; i < input; i++){
        printf("%d %d\n", entryQueue[i].age, entryQueue[i].time);
    }

    /* code */
    return 0;
}
