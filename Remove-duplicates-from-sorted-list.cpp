/* Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

Input: head = [1,1,2]
Output: [1,2] */

/* Approach:  Start traversing from the head node. While traversing, compare each node with its next node. If the data of the next node is the same as the current node 
   then delete the next node and before deleting a node store the next pointer of the node. */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* nextTonext;
        ListNode* p= head;
        while(p!=NULL && p->next != NULL){
            if(p->val == p->next->val){
                nextTonext = p->next->next;
                delete(p->next);
                p->next = nextTonext;
            }
            else{
                p = p->next;
            }
        }
        return head;
    }
};
