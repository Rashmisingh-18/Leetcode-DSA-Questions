/* Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, 
return null.
  
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes 
before the intersected node in B.
*/

// Naive Approach

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headB != NULL){
            ListNode* temp = headA;
            while(temp != NULL){
                if(temp == headB){
                    return headB;
                }
                temp = temp->next;
            }
            headB = headB->next;
        }
        return NULL;
    }
};
// Time Complexity: O( m*n )    ------->   m, n : Size of linked lists     


// Two - pointer Approach
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;
        if(ptr1 == NULL || ptr2 == NULL){
            return NULL;
        }
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            
            if(ptr1 == ptr2){
                return ptr1;
            }
            if (ptr1 == NULL)
                ptr1 = headB;
            
            if (ptr2 == NULL)
                ptr2 = headA;
        }
        return ptr1;
    }
};

// Time Complexity: O( m + n )      ------>     m, n : Size of linked lists
