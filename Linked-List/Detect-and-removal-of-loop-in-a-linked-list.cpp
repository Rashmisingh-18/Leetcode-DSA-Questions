/* Given head, the head of a linked list, determine if the linked list has a cycle in it.
  
 This can be done using Floyd'd Cycle Detection Algorithm / Hare-Tortoise Algorithm. So we first make slow and fast pointers both pointing to head, then slow is moving 
 one node at the time and the fast two nodes at the time. If there is a cycle, sooner or later pointers will meet and we return true. If the fast pointer reached the 
 end of the list, that means there is no cycle and we can return false. */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow){
                return true;
            }
        }
        return false;
    }
};

// Code to remove the loop
class Solution {
public:
    bool removeCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(slow!=fast);
      
        fast = head;
        while(fast!=NULL && fast->next!=NULL){
          slow = slow->next;
          fast = fast->next;  
        }
        slow->next=NULL;
    }
};
