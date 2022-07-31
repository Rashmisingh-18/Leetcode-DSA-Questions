// Given a linked list of size N where each node has two links: one pointer points to the next node and the second pointer points to any node in the list.
  
// Naive Approach: Using Hashmap
//   First create a single linked list with only the ‘next’ pointer and use a mapping to map the new nodes to their corresponding nodes in the given linked list. 
//   Now use this mapping to point the arbitrary node from any node in the newly created list. 

             // ALL TEST CASES RUN BUT STILL SHOWING RUN TIME ERROR
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
        
//         unordered_map<Node*, Node*>mp;
//         Node *temp, *newHead;
        
//         temp = head;
//         newHead = new Node(temp->val);
//         mp[temp] = newHead;
//         while(temp->next != NULL){
//             newHead->next = new Node(temp->next->val);
//             temp = temp->next;
//             newHead = newHead->next;
//             mp[temp] = newHead;
//         }
//         temp = head;
//         while(temp != NULL ){
//             mp[temp]->random = mp[temp->random];
//             temp = temp->next;
//         }
//         return mp[head];
//     }
// };

// Optimal Approach:
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter = head;
        Node* front = head;
        while(iter != NULL){
            front = iter->next;
            Node* copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        iter = head;
        while(iter!=NULL){
            if(iter->random!=NULL){
                iter->next->random=iter->random->next;
            }
            iter = iter->next->next;
        }
        iter=head;
        Node *pseudo_head = new Node(0);
        Node *copy = pseudo_head;
        while(iter!=NULL){
            front = iter->next->next;
            copy->next = iter->next;
            iter->next=front;
            copy = copy->next;
            iter = front;
        }
        return pseudo_head->next;
    }
};
