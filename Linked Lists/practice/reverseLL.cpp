#include <iostream>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val) {
            this->val = val;
            this->next = NULL;
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

ListNode* reverseLL(ListNode*& head) {
    ListNode* prev = NULL;
    ListNode* temp;
    ListNode* curr = head;

    while(curr != NULL) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    return prev;
}

int main() {
    int n;
    cin>>n;

    ListNode* head = NULL;

    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        insertAtTail(head, a);
    }

    // int start;
    // cin>>start;
    // int end;
    // cin>>end;
    printLinkedList(head);
    cout<<endl;

    head = reverseLL(head);

    printLinkedList(head);

    return 0;
}