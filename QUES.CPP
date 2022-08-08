//Function to push an integer into the stack.
void MyStack :: push(int x)
{
    // Your Code
    top++;
    arr[top] = x;
    
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    // Your Code  
    if(top==-1)
        return -1;
    return arr[top--];
}

//Function to find top element of the stack.
int MyStack::peek()
{
    if(top==-1)
        return -1;
    else {
        return a[top];
    }
}
Footer
© 2022 GitHub, Inc