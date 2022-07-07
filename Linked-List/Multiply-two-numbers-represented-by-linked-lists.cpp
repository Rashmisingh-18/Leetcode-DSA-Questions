/* Given two numbers represented by linked lists, write a function that returns the multiplication of these two linked lists.
Input : 9->4->6
        8->4
Output : 79464
  
Approach: Traverse both lists and generate the required numbers to be multiplied and then return the multiplied values of the two numbers. 
Algorithm to generate the number from linked list representation: 

1) Initialize a variable to zero
2) Start traversing the linked list
3) Add the value of first node to this variable
4) From the second node, multiply the variable by 10
   and also take modulus of this value by 10^9+7
   and then add the value of the node to this 
   variable.
5) Repeat step 4 until we reach the last node of the list. */


long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long long N = 1000000007;
  long long num1 = 0, num2 = 0;
  while(l1!=NULL || l2!=NULL){
      if(l1){
          num1 = (num1*10)%N + l1->data;
          l1 = l1->next;
      }
      if(l2){
          num2 = (num2*10)%N + l2->data;
          l2 = l2->next;
      }
  }
  return ((num1%N)*(num2%N))%N;
}
