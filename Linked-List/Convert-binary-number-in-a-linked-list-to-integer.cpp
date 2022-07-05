/* Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

So, if we try to understand it, then first find the length of linked list, as we know to convert any number in decimal, let say, 101 = 2^2 * 1 + 2^1 * 0 + 2^0 * 1 = 5, 
so basically in every step we are decrementing the length by 1, then taking power of 2, then summing.
So we can simply implement it as: */

class Solution {
public:
 
    int getDecimalValue(ListNode* head) {
	
	    // Finding the length of linked list as count
        int count = 0;
        ListNode* p = head;
        while(p->next != NULL){
            p= p->next;
            count++;
        }
		
		// Finding the decimal of the given binary Number
        int decimal = 0;
        while(count >= 0){
            decimal += pow(2, count)*head->val;
            head = head->next;
            count--;
        }
        return decimal;
    }
};
