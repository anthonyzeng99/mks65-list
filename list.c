#include <stdio.h>
#include <stdlib.h>

struct node {
  int i;
  struct node *next;
};
  
void print_listHelper(struct node *n, int ctr) {
  printf("%d:%d\n", ctr, n -> i);
  struct node *next = n -> next;
  if (next) {
    print_listHelper(next, ctr + 1);
  }
}

void print_list(struct node *n) {
  print_listHelper(n, 0);
}

struct node* insert_front(struct node *n, int i) {
  struct node *newNode = (struct node*) malloc(sizeof(struct node));
  newNode -> i = i;
  newNode -> next = n;
  return newNode;
}

struct node* free_list(struct node *n) {
  struct node *next = n -> next;
  if (next) {
    free_list(next);
  }
  free(n);
  return n;
}

int main() {
  struct node *x = (struct node*) malloc(sizeof(struct node));
  int i = 1;
  for (; i < 10; i++) {
      x = insert_front(x,i);
    }

  print_list(x);

  printf("\nAfter list freed\n");
  free_list(x);
  print_list(x);
}

