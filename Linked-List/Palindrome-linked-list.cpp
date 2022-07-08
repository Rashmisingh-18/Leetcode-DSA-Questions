/* Given the head of a singly linked list, return true if it is a palindrome.

Input: head = [1,2,2,1]
Output: true */

/* Approach 1: 
First approach is to use a stack of list nodes. 
  Traverse the given list from head to tail and push every visited node to stack.
  Again traverse the list, for every visited node, pop a node from the stack and compare data of popped node with the currently visited node.
  If all nodes matched, then return true, else false. */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        stack <int> st;
        while(slow != NULL){
            st.push(slow->val);
            slow = slow->next;
        }
        while(head != NULL){
            int i=st.top();
            st.pop();
            if(head->val != i){
                return false;
            }
            head = head->next;
        }
        return true;
    }
};

// Time complexity: O(n)
// Auxiliary Space: O (n) since we are using an auxiliary stack


/* Approach 2:
Second approach is to reversing the list nodes. 
   Find the middle of the linked list. 
   Then, reverse the second half of the linked list. 
   Compare if the first half and second half are identical. 
   Construct the original linked list by reversing the second half again and attaching it back to the first half */
   
class Solution {
public:
    ListNode* mid_element(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast) 
                fast=fast->next;
        }
        return slow;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* temp=NULL;
        while(curr != NULL){
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    bool compareList(ListNode* headA, ListNode* headB){
        while(headA!=NULL && headB!=NULL){
            if(headA->val != headB->val) 
                return false;
            headA=headA->next;
            headB=headB->next;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL) 
            return true;
        
        ListNode* curr_head1 =head;
        
        ListNode* mid = mid_element(curr_head1);
        ListNode* nxt_head2=reverseList(mid);
        
        return compareList(head,nxt_head2);
    }
};

// Time complexity: O(n)
// Auxiliary Space: O (1)
   
   
