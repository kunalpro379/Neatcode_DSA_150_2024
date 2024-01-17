#include<iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int data) {
        this->data = data;
        next = NULL;
        random = NULL;
    }
};
//space optimized solution
Node* CopyRandList(Node* head){
    if(!head)return NULL;
//dublicating each node and inserting it to its next to oringinal node
    Node* current=head;
    while(current){
Node* dublicat=new Node(current ->data);
dublicat->next=current->next;
current->next=dublicat;
current =dublicat->next;
    }
    current=head;
//setting up randome pointers of dublicated nodes
    while(current){
        if(current->random)
        current->next->random=current->random->next;
        current=current->next->next;
    }

    //seperating original and dublicated lists
    Node* original=head;
    Node* copy=head->next; 
    Node* dublicat=copy;
    while(original && dublicat){
        original->next=original->next?original->next->next:NULL;
        dublicat->next=dublicat->next?dublicat->next->next:NULL;
        original=original->next;
        dublicat=dublicat->next;
    }
    return copy;
}
Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> hashMap;
    Node* temp = head;

    while (temp != NULL) {
        Node* newNode = new Node(temp->data);
        hashMap[temp] = newNode;  
        temp = temp->next;
    }

    Node* t = head;
    while (t != NULL) {
        Node* node = hashMap[t];
        node->next = (t->next != NULL) ? hashMap[t->next] : NULL;
        node->random = (t->random != NULL) ? hashMap[t->random] : NULL;
        t = t->next;
    }

    return hashMap[head];
}

void Print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head->next != NULL ? cout << head->next->data : cout << "NULL";
        head->random != NULL ? cout << head->random->data : cout << "NULL";
        cout << endl;
        head = head->next;
    }
}
void Print2(Node* head) {
    while (head) {
        cout << head->data << " ";
        head->next ? cout << head->next->data : cout << "NULL";
        head->random ? cout << head->random->data : cout << "NULL";
        cout << endl;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    Node* node1 = new Node(12);
    Node* node2 = new Node(25);
    Node* node3 = new Node(37);
    Node* node4 = new Node(49);

    head = node1;
    head->next = node2;
    head->next->next = node3;
    head->next->next->next = node4;

    head->random = node4;
    head->next->random = node1;
    head->next->next->random = NULL;
    head->next->next->next->random = node2;

    cout << "Original list:\n";
    Print(head);

    cout << "Copy list (using original copyRandomList function):\n";
    Node* newHeadOriginal = copyRandomList(head);
    Print(newHeadOriginal);

    cout << "Copy list (using optimized CopyRandList function):\n";
    Node* newHeadOptimized = CopyRandList(head);
    Print(newHeadOptimized);

    return 0;
}
