#include <iostream>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val) {
            this->next = NULL;
            this->val = val;
        }
};

void insertAtHead(ListNode*& head, int val){
    ListNode* n = new ListNode(val);

    n->next = head;
    head = n;
}

ListNode* getTailNode(ListNode* head){

    while(head->next != NULL){
        head=head->next;
    }
        
    return head;    
}

void insertAtTail(ListNode*& head, int val){

    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    ListNode* n = new ListNode(val);

    ListNode* tail = getTailNode(head);
    tail->next = n;
}

void printLinkedList(ListNode* head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}

void arrangeOE(ListNode*& head, int n) {
    if(head == NULL || head->next == NULL) {
        return;
    }

    ListNode* temp = head;
    ListNode* temp2 = head->next;
    ListNode* newStart = temp2;
    
    while(temp->next != NULL && temp2->next != NULL) {
        temp->next = temp2->next;
        temp = temp->next;
        temp2->next = temp->next;
        temp2 = temp2->next;
    }

    if(temp->next != NULL) {
        temp2->next = NULL;
    }
    
    temp->next = newStart;
}

int main() {
    ListNode* head = NULL;

    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        insertAtTail(head, a);
    }
    cout<<"Original List: ";
    printLinkedList(head);
    arrangeOE(head, n);

    cout<<endl;
    cout<<"Modified List: ";
    printLinkedList(head);

    return 0;
}