#include <iostream>

using namespace std;

class ListNode {
    public :
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



void foldLL(ListNode*& head, int n) {

    if(head->next == NULL || head == NULL) {
        return;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    ListNode* second = reverseLL(slow->next);
    slow->next = NULL;
    ListNode* first = head;


   while(second != NULL) {
        ListNode* temp2 = first->next;
        ListNode* temp3 = second->next;

        first->next = second;
        second->next = temp2;

        second = temp3;
        first = temp2;

        if(temp3!=NULL && temp3->next!=NULL){
            temp3 = temp3->next;
        }
        if(temp2!=NULL && temp2->next!=NULL){
            temp2 = temp2->next;
        }
        
   }

}

int main() {
    int T;
    cin>>T;

    for(int i=0; i<T; i++) {
        ListNode* head = NULL;

        int n;
        cin>>n;

        for(int i=0; i<n; i++){
            int a;
            cin>>a;
            insertAtTail(head, a);
        }

        
        foldLL(head, n);


        printLinkedList(head);

        cout<<endl; 
    }



    return 0;
}