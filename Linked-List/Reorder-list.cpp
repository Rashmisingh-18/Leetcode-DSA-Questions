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
	    
        // Find the middle of list
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* cur = slow->next;
        slow->next = NULL;
        
        ListNode* prev = nullptr, *next = NULL;
        
        //reverse second part
        while (cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        //merge
        cur = head;
        while (cur && prev){
            next = cur->next;
            cur->next = prev;
            cur = next;
            
            next = prev->next;
            prev->next = cur;
            prev = next;
	}
    }
};

// Time Complexity: O(N)
// Space COmplexity: O(1)
