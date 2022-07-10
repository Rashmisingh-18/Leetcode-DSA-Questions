/* You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
  
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7] */

/* Approach: 
The idea is to add zeros to the start of the smaller list (which is allowed since it doesn't tamper with the original structure of the list) such that both the lists become of equal size and then use recursion to perform digit by digit addition (starting from the last digits, obviously).

For example consider the following lists,

l1: 7->2->4->3
l2: 5->6->4
After adding zeros to l2 (the smaller list), the lists become,

l1: 7->2->4->3
l2: 0->5->6->4
We now use recursion to the end of both the lists and start addition from the end. */

class Solution {
public:
    
    ListNode* addTwoDigits(ListNode* l1, ListNode* l2, int &carry){
        if(l1 == NULL && l2 == NULL)
            return NULL;
        ListNode *newNode = new ListNode(-1);
        newNode->next = addTwoDigits(l1->next, l2->next, carry);
        
        newNode->val = (l1->val + l2->val + carry)%10;
        carry = (l1->val +l2->val +carry)/10;
        
        return newNode;
        
    }
    // Adding Zeroes
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        while(ptr1 !=NULL || ptr2!=NULL){
            if(ptr1 == NULL){
                ListNode* newNode = new ListNode(0);
                newNode->next = l1;
                l1 = newNode;
                
                ptr2 = ptr2->next;
            }
            else if(ptr2 == NULL){
                ListNode* newNode = new ListNode(0);
                newNode->next = l2;
                l2 = newNode;
                
                ptr1 = ptr1->next;
            }
            else{
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
        }
        
        // Performing Addition
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        dummy->next = addTwoDigits(l1, l2, carry);
        if(carry != 0){
            ListNode* newNode = new ListNode(carry);
            newNode->next = dummy->next;
            dummy->next = newNode;
        }
        return dummy->next;
    }
};
