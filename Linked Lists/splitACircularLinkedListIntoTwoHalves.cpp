#include <iostream>

using namespace std;

class ListNode {
    public:
        int val;
        ListNode* next;

        ListNode(int val){
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

void splitCycle(ListNode*& head, int n) {

    if(head == NULL || head->next == NULL) {
        printLinkedList(head);
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(true) {
        slow = slow->next;
        fast = fast->next->next;
        //cout<<"# ";
        if(slow == fast) {
            break;
        }
    }
    //cout<<endl;
    slow = head;

    while(slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
        //cout<<"& ";
    }

    fast->next = NULL;
    
    slow = head;
    fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* first = head;
    ListNode* second = slow->next;
    slow->next = NULL;

    printLinkedList(first);
    cout<<endl;
    printLinkedList(second);
}

int main() {
    ListNode* head = NULL;

    int n;
    cin>>n;

    ListNode* cir;

    for(int i=0; i<n; i++) {
        int a;
        cin>>a;
        insertAtTail(head, a);

        if(i == 1) {
            cir = head->next;
        }

        if(i == n-1) {
            ListNode* end = getTailNode(head);
            end->next = cir;
        }
        
    }

    //printLinkedList(head);

    splitCycle(head, n);



    return 0;
}