/*
We are given a linked list. There are Q queries. Each query is represented by a index x which represents the position from which the element has to be deleted. After every query print the linked list.

Input Format
First line contains the number of nodes in the linked list n and queries q and then next line contains n space separated integers representing the node values of the linked list and then q lines follow containing the indices to be deleted.

Constraints
n < 1000

Output Format
Output the linked list after every query. Print the node values in a single line separated by spaces.

Sample Input
5 2
1 2 3 4 5
0
1

Sample Output
2 3 4 5
2 4 5

Explanation
Initially the node at index 0 is deleted and list becomes 2 3 4 5. Then node at index 1 is deleted and the list becomes 2 4 5.
*/

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

ListNode* getIndexNode(ListNode* head, int i){
    int k=0;
    while(k<i && head->next != NULL){
        head = head->next;
        k++;
    }

    return head;
}

void deleteAtHead(ListNode*& head){
    ListNode* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtIndex(ListNode*& head, int i){
    if(head == NULL){
        cout<<"LL is Empty";
        return;
    }

    if(i==0) {
        deleteAtHead(head);
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

void printLinkedList(ListNode* head){
        while(head){
            cout<<head->val<<" ";
            head=head->next;
        }
}

int main() {
    ListNode* head = NULL;
    int n;
    cin>>n;
    int q;
    cin>>q;

    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        insertAtTail(head, a);
    }

    for(int j=0; j<q; j++) {
        int index;
        cin>>index;
        deleteAtIndex(head, index);
        printLinkedList(head);
    }

    return 0;
}