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

// Using the count of linked lists
class Solution {
public:
    int count_of_nodes(Node* head){
    int count=0;
    while(head){
        count++; 
        head=head->next;
    }
    return count;
}

  //Function to find intersection point in Y shaped Linked Lists.
  int intersectPoint(Node* head1, Node* head2)
  {
      // Your Code Here
      int c1 = count_of_nodes(head1);
      int c2 = count_of_nodes(head2);
      int d;
      if(c1>c2){
          d=c1-c2;
          for(int i=0; i<d; i++){
              head1=head1->next;
          }
      }
      else if(c2>c1){
          d=c2-c1;
          for(int i=0; i<d; i++){
              head2=head2->next;
          }
      }
      while(head1!=NULL && head2!=NULL && head1!=head2){
          head1=head1->next;
          head2=head2->next;
      }
      return head1->data;
    }
  }
};
