#include <iostream>
using namespace std;

class node{
public:
    int data;
    node* next;
};

class LinkList {
    private:
        node* head;
        // node* tail;

    public:
    LinkList(void){
        head = NULL;
          // tail = NULL;
    }
    
    ~LinkList(void){
	}
	
	bool isEmpty(){
		return head==NULL;
	}
	
	node* insertNode(int x, int index){
		if(index<0) return NULL;
		
		index=index-1;
		
		int currIndex=1;
		node* currNode=head;
		
		while(currNode&&index>currIndex){
			currNode=currNode->next;
			currIndex++;
		}
		
		if(index>0 && currNode == NULL) return NULL;
		
		node* newNode = new node;
		newNode->data=x;
		
		if(index==0){
			newNode->next=head;
			head=newNode;
		}
		else{
			newNode->next=currNode->next;
			currNode->next=newNode;
		}
		
		return newNode;
	}
	
	int searchNode (int x){
		node* currNode=head;
		int currIndex=1;
		
		while(currNode&&currNode->data!=x){
			currNode=currNode->next;
			currIndex++;
		}
		
		if(currNode) return currIndex;
		
		return -1;
	}
	
	int deleteNode (int index){
		int currIndex=1;
		node* currNode=head;
		node* prevNode=NULL;

		while(currNode&&index>currIndex){
			prevNode=currNode;
			currNode=currNode->next;
			currIndex++;
		}
		
		if(currNode){
			if(prevNode){
				prevNode->next=currNode->next;
				delete currNode;
			}
			else{
				head=currNode->next;
				
				delete currNode;
			}
			return currIndex;
		}
		return 0;
	}
	
	void printList(){
		int num=0;
		
		node* currNode=head;
		while(currNode!=NULL){
			cout<<num+1<<". "<<currNode->data<<endl;
			currNode=currNode->next;
			num++;
		}
		
		cout<<"Number of nodes in the list is: "<<num<<endl;
	}
};

int main()
{
	LinkList b;
	b.insertNode(9,1);
	b.insertNode(8,2);
	b.insertNode(7,3);
	b.insertNode(6,4);
	b.insertNode(5,5);
	b.insertNode(9,6);
	b.printList();
	
	b.insertNode(9,4);
	b.printList();
	
	cout<< b.searchNode(4) <<endl;
	cout<< b.searchNode(5) <<endl;
	cout<< b.searchNode(7) <<endl;
	cout<< b.searchNode(3) <<endl;
	cout<< b.searchNode(9) <<endl;
	
	b.deleteNode(4);
	b.printList();
	
    return 0;
}

