#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    int count;
};

class LinkedList {
    private:
        node* head;
        node* tail;
        int counter = 0;

    public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }

    void newNodeSpecific(int v, int i){ //add node to specific index
        node* newTemp = new node;
        newTemp->data = v;
        node* temp = head;

        while(temp!= NULL){

        if(temp->count == i){
            break;
        }
          temp = temp->next;
        }

        newTemp->next = temp->next;
        temp->next = newTemp;

        newTemp->count = temp->count+1;

        node* anotherTemp = head;

        while(anotherTemp != NULL){//I made a counter as the node indexes but had issue with the newNodeSpecific() function when I try to create new node, I cant change the counter of the following nodes. If you dont mind can you help look at my code and tell me what is im wrong
          // if (newTemp->next) {
          //    anotherTemp->count++;
          //  }
          anotherTemp = anotherTemp->next;
        }
    }

    void newNode(int v) { //add node beginning or end
        node* temp = new node;
        temp->count = ++this->counter;
        temp->data = v;
        temp->next = NULL;

        if(head == NULL){
            head = temp;
            tail = temp;
        }

        else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    void deleteNode(node* i) { //delete node
        node* temp = head;

        if(temp->next == i){
            head = temp->next;
        }

        else {
            while(temp != NULL){
                if(temp->next == i){
                    temp->next = i->next;

                    break;
                }

                temp = temp->next;
            }
        }
    }

    int searchNode(int v){ //search for a value in the list
        node* temp = head;

        while(temp != NULL){ //go through all the list

          if(temp->data == v){

            return temp->count;
          }

          temp = temp->next;
        }

        return -1; //if no value in the list return this
    }

    void printList(){
        node* temp = head;

        while(temp!= NULL){
          cout << temp->data << " " << temp->count << endl;

          temp = temp->next;
        }
    }
};

int main()
{

    LinkedList aLink;
    aLink.newNode(1);
    aLink.newNode(2);
    aLink.newNode(3);
    aLink.newNode(4);

    aLink.printList();

    cout << "__________________________________" << endl;
    aLink.newNodeSpecific(7, 2);

    cout << aLink.searchNode(78);
    cout << endl << aLink.searchNode(7);
    cout << endl << aLink.searchNode(36);
    cout << endl << endl;
    aLink.printList();

    return 0;
}
