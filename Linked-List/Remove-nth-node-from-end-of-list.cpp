/* Given the head of a linked list, remove the nth node from the end of the list and return its head.
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Approach 1: Make a dummy node and count variable. Move dummy to next until it reaches null and also increment count in each step. Then make another node let's say temp, 
and move it by (count-n) steps, then you will the node which is required to remove, so do temp->next = temp->next->next.
It requires traversal of two nodes two times in a given linked list, so the time complexity for this will be: O(n) + O(n) ~ O(2n).
  
Another Approach: Make a dummy listnode and initialise its next to head.
                  Then initialise slow and fast pointers pointing to dummy initially.
                  Move fast pointer by n steps.
                  Then, while fast->next is not null, move slow and fast both by one step
                  Then, you will see that, you reach at the required n, so, make slow->next = slow->next->next and return dummy->next.
                  */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        for(int i=1; i<=n; i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
