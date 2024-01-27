#include<iostream>

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

ListNode* getIndexNode(ListNode* head, int i){
    int k=0;
    while(head->next != NULL && k<i){
        head = head->next;
        k++;
    }

    return head;
}

void insertAtIndex(ListNode*& head, int i, int val){
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    ListNode* n = new ListNode(val);

    ListNode* prev = getIndexNode(head, i-1);

    if(prev == NULL){
        insertAtTail(head, val);
        return;
    }

    n->next = prev->next;
    prev->next = n;
}

void deleteAtHead(ListNode*& head){
    ListNode* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtTail(ListNode*& head){
    if(head == NULL){
        cout<<"LL is Empty";
        return;
    }

    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }

    ListNode* tail = head;
    ListNode* prev = NULL;
    while(tail->next != NULL){
        prev = tail;
        tail = tail->next;
    }

    prev->next = NULL;
    delete tail;

}

void deleteAtIndex(ListNode*& head, int i){
    if(head == NULL){
        cout<<"LL is Empty";
        return;
    }

    ListNode* curr = getIndexNode(head, i);
    if(curr == NULL){
        cout<<"Invalid Index Number Entered!";
        return;
    }

    ListNode* prev = getIndexNode(head, i-1);
    prev->next = curr->next;
    delete curr;

}

int searchLLRecursive(ListNode* head, int target, int count){
    if(head->next == NULL && head->val == target){
        return count+1;
    }else if(head->next == NULL){
        return 0;
    }

    if(head->val == target){
        return count+1;
    }

    int pos = searchLLRecursive(head->next, target, count+1);

    return pos;
}

void printLinkedList(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
}
int main(){
    ListNode* head = NULL;
    int n;
    cout<<"Enter Size Of LL: ";
    cin>>n;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        insertAtTail(head, a);
    }
    printLinkedList(head);

    cout<<endl;

    int val;
    cout<<"Enter value to be inserted: ";
    cin>>val;

    int idx;
    cout<<"Enter Index number: ";
    cin>>idx;
    insertAtIndex(head, idx, val);

    printLinkedList(head);

    cout<<endl;
    deleteAtHead(head);

    printLinkedList(head);
    
    cout<<endl;
    deleteAtTail(head);

    printLinkedList(head);

    cout<<endl;
    int idxd;
    cout<<"Enter Index number To Be Deleted: ";
    cin>>idxd;
    deleteAtIndex(head, idxd);

    printLinkedList(head);

    cout<<endl;
    for(int i=60; i<90; i+=10){
        insertAtTail(head, i);
    }
    cout<<"Newly Re-formed LL: ";
    printLinkedList(head);

    cout<<endl;
    int seVal;
    cout<<"Enter number To Be Searched: ";
    cin>>seVal;
    int pos = searchLLRecursive(head, seVal, 0);

    if(pos > 0){
        cout<<"Element Found at "<<pos<<"th position in LL.";
    }else{
        cout<<"Element not found.";
    }
        
    return 0;
}