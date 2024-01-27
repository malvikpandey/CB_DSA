#include <iostream>

using namespace std;

class ListNode{
    public:
        int val;
        ListNode* next;

        ListNode(int val){
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

void printLinkedList(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
}

ListNode* reverseLLIB(ListNode*& head, ListNode* left, ListNode* right) {

    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* end = getTailNode(head);

    if(head == left && end == right){

        ListNode* newLL = reverseLL(head);
        return newLL;

    } else if(head == left) {
        ListNode* tempR = head;

        while(tempR != right) {
            tempR = tempR->next;
        }

        ListNode* last = tempR->next;

        tempR->next = NULL;

        ListNode* newLL = reverseLL(head);
        head = newLL;

        while(newLL->next != NULL && newLL != NULL) {
            newLL = newLL->next;
        }
        newLL->next = last;

        return head;

    }else {
        ListNode* tempL = head;
        ListNode* prevL = NULL;

        while(tempL != left) {
            prevL = tempL;
            tempL = tempL->next;
        }
        
        if(prevL!=NULL){
            prevL->next = NULL;
        }

        ListNode* tempR = tempL;

        while(tempR != right) {
            tempR = tempR->next;
        }

        ListNode* last = tempR->next;

        if(tempR!=NULL) {
            tempR->next = NULL;
        }

        ListNode* newLL = reverseLL(tempL);
        
        if(prevL!=NULL){
            prevL->next = newLL;
        }

        while(newLL->next != NULL && newLL != NULL) {
            newLL = newLL->next;
        }
        newLL->next = last;

        return head;
    }

}



int main() {
    ListNode* head = NULL;

    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        insertAtTail(head, a);
    }

    int left;
    cin>>left;
    int right;
    cin>>right;

    ListNode* lft = head;
    ListNode* rt = head;

    while(left != 1) {
        lft = lft->next;
        left--;
    }

    while(right != 1) {
        rt = rt->next;
        right--;
    }

    ListNode*newLL = reverseLLIB(head, lft, rt);

    printLinkedList(newLL);

    return 0;
}