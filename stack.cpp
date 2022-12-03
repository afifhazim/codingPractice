#include<iostream>
using namespace std;

struct Node{
  char data;
  struct Node *next;
}*top == NULL;

// insert at the beginning
void push(char op) {

  // create new node temp and allocate memory
  struct Node* temp = new Node();

  // check if stack (heap) is full. Then inserting an element would
  // lead to stack overflow
  if (!temp)
    cout << "Stack Overflow.\n";

  else
    temp->data = op;
    temp->next = top; // put top pointer reference into temp link
    top = temp; // make temp as top of Stack
}

char pop(){
  struct Node* temp;

  if (top==NULL) {
    cout << "Stack Underflow\n";

    exit(1);
  }
  else
    temp = top;
    top = top->next;
    temp->next = NULL;
    free(temp);

    return temp->data;
}

int isOperator(char op){
  if (op == '+' || op == '-' || op == '*' || op == '/' || op == '^') {
    return 1;
  }
  else
    return 0;
}

int precedence(char op){
  if (op == '^') {
    return 3;
  }
  else if (op == '*' || op == '/') {
    return 2;
  }
  else if (op == '+'  || op == '-') {
    return 1;
  }
  else
   return 0;
}

void InfixToPostfix(Node* infix, Node* postfix){

  int i, j;
  char item;
  char x;

  push('(');
  strcat(infix, ')');
}

int main() {

  return 0;
}
