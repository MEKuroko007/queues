#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

struct Queue {
  struct Node *front;
  struct Node *rear;
};

struct Queue *createQueue() {
  struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
  queue->front = NULL;
  queue->rear = NULL;
  return queue;
}

int isEmpty(struct Queue *queue)
{ 
  return queue->front == NULL; 
}

void enqueue(struct Queue *queue, int item) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = item;
  newNode->next = NULL;

  if (isEmpty(queue)) {
    queue->front = newNode;
    queue->rear = newNode;
  } else {
    queue->rear->next = newNode;
    queue->rear = newNode;
  }
}

int dequeue(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty. Cannot dequeue.\n");
    return -1;
  }

  struct Node *temp = queue->front;
  int removedItem = temp->data;

  queue->front = queue->front->next;
  free(temp);

  return removedItem;
}

int isFull(struct Queue *queue) {
  return 0; 
}

void display(struct Queue *queue) {
  if (isEmpty(queue)) {
    printf("Queue is empty.\n");
    return;
  }

  struct Node *current = queue->front;
  while (current != NULL) {
    printf("%d ", current->data);
    current = current->next;
  }
  printf("\n");
}

int main() {
  struct Queue *queue = createQueue();
  int choice;
  int item;

  while (1) {
    printf("----------------------------------------------------------\n");
    printf("**************** A Simple Program for Queues ***************\n\n");

    printf("Choose your choice for this queue:\n");
    printf("1 - Display queue\n");
    printf("2 - Add to queue\n");
    printf("3 - Remove from queue\n");
    printf("4 - Check if empty\n");
    printf("5 - Check if full\n");
    printf("6 - Quit\n");

    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Queue elements: ");
      display(queue);
      break;

    case 2:
      printf("Enter the item to add: ");
      scanf("%d", &item);
      enqueue(queue, item);
      break;

    case 3:
      printf("Dequeued: %d\n", dequeue(queue));
      break;

    case 4:
      if (isEmpty(queue))
        printf("Queue is empty.\n");
      else
        printf("Queue is not empty.\n");
      break;

    case 5:
      if (isFull(queue))
        printf("Queue is full.\n");
      else
        printf("Queue is not full.\n");
      break;

    case 6:
      free(queue);
      exit(0);

    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
