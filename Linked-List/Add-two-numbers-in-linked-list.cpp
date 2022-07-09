/* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Psuedocode:

  * Create a dummy node which is the head of new linked list.
  * Create a node temp, initialise it with dummy.
  * Initialize carry to 0.
  * Loop through lists l1 and l2 until you reach both ends, and until carry is present.
  * Set sum=l1.val+ l2.val + carry.
  * Update carry=sum/10.
  * Create a new node with the digit value of (sum%10) and set it to temp node’s next, then advance temp node to next.
  * Advance both l1 and l2.
  * Return dummy’s next node.
Note that we use a dummy head to simplify the code. Without a dummy head, you would have to write extra conditional statements to initialize the head’s value. */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum = 0;
            if(l1!=NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return dummy->next;
    }
};
