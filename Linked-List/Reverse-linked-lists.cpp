/* Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1] */

// Recursive Approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL||head->next==NULL){
            return head;
        }
        
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};

// Iterative Approach

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr=head;
        ListNode* prev = NULL;
        ListNode* next;
        while(curr != NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
