// To check if Stack is empty or not
void IsEmpty(){
  if(top==NULL)
    return 1;
  else
    return 0;
}

// Push a value in the Stack
struct Node* n = (struct Node* )malloc(sizeof(Node));
  if(n==NULL)
    cout<<"Stack Overflow";
  else
    n->data = x;
    n->next = top;
    top = n;
}

// To check if Stack is full
struct Node* n = (struct Node* )malloc(sizeof(Node));
if(n == NULL
   return 1;
else
   return 0;
  
// To pop element from Stack
struct Node* ptr;
for(int i=; (i<pos-1 && ptr!=NULL); i++){
  ptr=ptr->next;
}
if(ptr!=NULL)
   return ptr->data;
else
   return -1;
