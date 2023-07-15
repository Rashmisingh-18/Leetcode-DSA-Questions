/* You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
  
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4] */

// Approach 1: Using dummy node

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode dummyNode;                  // a dummy first node to hang the result on 
        ListNode* p3 = &dummyNode;           //  tail points to the last result node
        // dummyNode.next = NULL;
        while(p1 != NULL && p2 != NULL){
            if(p1->val < p2->val){
                p3->next = p1;  
                p1 = p1->next; 
            }
            else{
                p3->next = p2;
                p2 = p2->next;
            }
            p3 = p3->next;
        }
        while(p1 != NULL){
            p3->next = p1;
            p1 = p1->next;
            p3 = p3->next;
        }
        while(p2 != NULL){
            p3->next = p2;
            p2 = p2->next;
            p3 = p3->next;
        }
        return (dummyNode.next);
    }
};


// Approach 2: Using Recursion

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result;
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val < list2->val){
            result=list1;
            result->next= mergeTwoLists(list1->next, list2);
        }
        else{
              result=list2;
            result->next= mergeTwoLists(list1, list2->next);
        }
        return result;
    }
};
