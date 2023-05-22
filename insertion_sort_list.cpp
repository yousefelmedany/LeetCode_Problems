#include <bits/stdc++.h>

using namespace std;





struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* insertionSortList(ListNode* head) {
    ListNode* current=head;
    ListNode* newhead=nullptr;
    while(current!=nullptr){
        ListNode* temp =current->next;
        newhead=insertSorted(newhead,current);
        current=temp;
    }
    return newhead;
}

ListNode* insertSorted(ListNode* newhead,ListNode* newnode){
    if(newhead==nullptr || newhead->val >= newnode->val){
        newnode->next =newhead;
        newhead=newnode;
        return newhead;
    }
    else{
        ListNode* temp =newhead;
        while(temp->next != nullptr && temp->next->val < newnode->val){
            temp =temp->next;
        }
        newnode->next =temp->next;
        temp->next =newnode;
    }
    return newhead;
}




int main(){




}