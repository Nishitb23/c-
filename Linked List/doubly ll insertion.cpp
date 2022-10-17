// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

class List{
  public:
  int data;
  List* next;
  List* prev;
  
  List(int data){
      this->data = data;
      next= NULL;
      prev= NULL;
  }
};

List* insertEnd(List *head, int data){
    List* node = new List(data);
    if(head==NULL){
        return node; 
    }
    else{
        List* temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
    
    return head;
}

List* insertStart(List* head,int data){
    List* node = new List(data);
    
    if(!head){
        return node;
    }else{
        head->prev=node;
        node->next = head;
        head = node;
    }
    return head;
}

List* insertPos(List* head, int data, int pos){
    List* node = new List(data);
    List* temp = head;
    pos--;
    while(pos){
        pos--;
        temp = temp->next;
    }

    node->next = temp->next;
    temp->next->prev = node;
    node->prev= temp;
    temp->next = node;
    
    return head;
}

void printList(List* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main() {
    List* head = NULL;
    head = insertStart(head,3);
    head = insertStart(head,2);
    head = insertStart(head,1);
    head = insertEnd(head,5);
    head = insertEnd(head,6);
    head = insertEnd(head,7);
    head = insertPos(head,4,3);
    
    printList(head);

    return 0;
}