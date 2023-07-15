// Maintaining a count of nodes, and then traversing for second time for n/2 nodes to get to the middle of the list.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        temp = head;
        for(int i=0; i< len/2; i++){
            temp = temp->next;
        }
        return temp;
    }
};


// Hare-Tortoise-Approach

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
