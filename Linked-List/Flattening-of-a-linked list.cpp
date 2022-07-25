/* Given a linked list where every node represents a linked list and contains two pointers of its type: 

Pointer to next node in the main list (we call it ‘right’ pointer in the code below) 
Pointer to a linked list where this node is headed (we call it the ‘down’ pointer in the code below).  

Write a function flatten() to flatten the lists into a single linked list. The flattened linked list should also be sorted. */


Node* merge (Node* a, Node* b){
    if(a==NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    
    Node* result;
    if(a->data < b->data){
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else{
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    result->next = NULL;
    
    return result;
}

/*  Function which returns the  root of the flattened linked list. */

Node *flatten(Node *root)
{
   if(root == NULL || root->next == NULL){
       return root;
   }
   root->next = flatten(root->next);
   root = merge(root, root->next);
   
   return root;
}
