#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    
ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> data;
    ListNode* dummy = head;
    while(1){
        //cout << dummy->val << endl;
        data.push_back(dummy);
        if (dummy -> next != nullptr){
            dummy = dummy->next;
        }else break;
    }
    n = data.size() - n - 1;
    if (n < 0){
        head = head -> next;
    }
    else if(n == data.size() - 2){
        data[data.size() - 2]->next = nullptr;
    }else{
        data[n]->next = data[n+2];
    }
    while(1){
        cout << head->val << endl;
        data.push_back(head);
        if (head -> next != nullptr){
            head = head->next;
        }else break;
    }
    return head;
}

int main(){
    ListNode head(12);
    ListNode node1(3);
    ListNode node2(7);
    ListNode node3(10);
    ListNode node4(2);
    head.next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    ListNode* test  = &head;
    removeNthFromEnd(test,1);
    return 1;
}