/* Approach:

Find the middle point using tortoise and hare method.
Split the linked list into two halves using found middle.
Reverse the second half.
Do alternate merging of first and second halves. */

class Solution {
public:

    //  Function to Reverse the list 
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
	
        // Finding the middle of list		
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Assigning the head1 as the head of the first halve and 
        // head2 as the head of the second halve which is slow->next;
        ListNode* head1 = head;
        ListNode* head2 = slow->next;
        slow->next = NULL;
        
        // Reversing the second half of the list
        reverseList(head2);
        
        // Alternate merging of the two halves
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(head1!=NULL || head2!=NULL){
            if(head1){
                curr->next = head1;
                curr = curr->next;
                head1 = head1->next;
            }
            if(head2){
                curr->next = head2;
                curr = curr->next;
                head2 = head2->next;
            }
        }
        dummy = dummy->next;
    }
};

// Time Complexity: O(N)
// Space COmplexity: O(1)
