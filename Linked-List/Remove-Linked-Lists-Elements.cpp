/* Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
 
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5] */

// Using two pointer approach: current and previous

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val == val){
            head=head->next;
        }
        ListNode* curr=head;
        ListNode* prev;
        while(curr!=NULL){
            if(curr->val == val){
                prev->next = curr->next;
            }
            else{
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};


// Using only one, current pointer:

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val == val){
            head=head->next;
        }
        ListNode* curr=head;
        
        while(curr!=NULL && curr->next!=NULL){
            if(curr->next->val == val){
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};
