#include <bits/stdc++.h>
using namespace std;

class node {
    public : 
    int data;
    node *next;

    // constructor 
    node(int data){
        this -> data = data ;
        this -> next = NULL;
    }

    ~node(){
        int value = this -> data;

        if(this -> next != NULL){
            delete next; // remove the node from heap 
            this -> next = NULL; // free the next pointer 
        }

        cout<<"Memory is free of node data "<<value<<endl;
    }

};


// Deletion in linked list 

void deleteAtPosition(node * &head , node * &tail , int pos){

    // delete first node / head node    
    if(pos == 1){

        node *temp = head;
        head = head -> next;
        // free the first node / free memory 
        temp -> next = NULL;
        delete temp;

    }else{
        
        // delete middle node or last node from LL

        node *prev = NULL; // two pointer for delete
        node *curr = head;
        int cnt = 1;
        while(cnt < pos){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        prev -> next = curr -> next;
        if(curr == NULL){ // update tail
            tail = prev;
        }
        curr -> next = NULL; // free the next pointer from pointing on node 
        delete curr; // free memory

    }
}

// head as a refrence / change in original linked list / copy nahi ho raha head 
void insertAtHead(node * &head , int data){
    
    node *temp = new node(data);
    temp -> next = head;
    head = temp;

}

// passing tail as refrence 

void insertAtTail(node * &tail , int data){

    node *temp = new node(data);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(node * &tail , node *&head , int pos , int data){
    node *temp = head;
    int cnt = 1;

    if(pos == 1){   // handle the case of inserting the 1st position
        insertAtHead(head , data);
        return;
    }
 
    while(cnt < pos-1){ 
        temp = temp -> next;
        cnt++;
    }

    node *node1 = new node(data); // new node create

     if(temp == NULL){  // updating tail when inserting the element at last position 
        tail = node1; 
        // or
        // insertAtTail(tail,data);
        // return ;
    }

    node1 -> next = temp -> next;
    temp -> next = node1;

}

void printLL(node * &head){
    node *temp  = head; 
    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){

    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    // insertAtHead(tail , 12);
    // insertAtHead(tail , 15);

    insertAtTail(tail , 12);
    insertAtTail(tail , 15);
    insertAtPosition(tail , head , 4 , 22);

    printLL(head);
    deleteAtPosition(head , tail , 4);
    printLL(head);

    // cout<< node1 -> data <<endl;
    // cout<< node1 -> next <<endl;

    return 0;
}
