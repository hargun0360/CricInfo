#include <bits/stdc++.h>
using namespace std;

class node {
    public :
    node *prev;
    int data;
    node *next;

    node(int data){
        this -> prev = NULL;
        this -> data = data;
        this -> next = NULL;
    }

    ~node(){
        int value = this -> data;
        if(next != NULL){
            delete next;
            next = NULL;
        }

         cout<<"Memory is free of node data "<<value<<endl;
    }

};

void print(node * &head){
    node *temp = head;   // on traversal never move head pointer    

    while(temp != NULL){
        cout<< temp -> data <<" ";
        temp = temp -> next;
    }

    cout<<endl;
}

void insertAtHead(node * &head , node * &tail , int data){

    if(head == NULL){
        node *temp = new node(data);
        head = temp;
        tail = temp;
        return;
    }
    
    node *temp = new node(data);

    temp -> next = head;
    head -> prev = temp;
    head = temp;    
}

void insertAtTail(node * &tail , node * &head, int data){

      if(head == NULL){
        node *temp = new node(data);
        head = temp;
        tail = temp;
        return;
    }

    node *temp = new node(data);

    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;

}

void insertAtPosition(node * &head , node * &tail , int pos , int data){

     node *curr = head;
     node *pre = NULL;
     int cnt = 1;

     if( pos == 1){
        insertAtHead(head , tail , data);
        return;
     }

       if(head == NULL){
        node *temp = new node(data);
        head = temp;
        tail = temp;
        return;
    }

     while(cnt < pos){
        pre = curr;
        curr = curr -> next;
        cnt++;
     }

     if(curr -> next == NULL){
        insertAtTail(tail , head ,  data);
        return;
     }

     node *temp = new node(data);

     temp -> next = curr;
     curr -> prev = temp;
     pre -> next = temp;
     temp -> prev = pre;

}

void deleteAtPosition(node * &head , node * &tail , int pos){
    
    // Delete the node from start 

    if(pos == 1){

        node *temp = head;
        temp  -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        delete temp;

    }else{
        
        // Delete middle and last node 

        node *temp = head;
        int cnt = 1;

        while(cnt < pos){
            temp = temp -> next;
            cnt++;
        }
        
        if(temp ->next == NULL){
            temp=temp->prev;
            temp->next=NULL;
            delete temp->next;
        }
        else{
            temp=temp->prev;
            // cout<<temp->data;
            temp -> next  = temp -> next -> next;
            temp -> next -> next -> prev = temp;   
            temp -> next -> prev = NULL;
            temp -> next -> next = NULL;
            delete temp->next; 
        }
    }

}

int main(){


    node *head = new node(10);
    node *tail = head;

    insertAtPosition(head , tail , 1 , 1);
    insertAtPosition(head , tail , 2 , 2);
    insertAtPosition(head , tail , 3 , 3);
    insertAtPosition(head , tail , 4 , 4);
    insertAtPosition(head , tail , 5 , 5);
 

    print(head);

    deleteAtPosition(head , tail , 3);

    print(head);

    return 0;
}