// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

//     Starting with any positive integer, replace the number by the sum of the squares of its digits.
//     Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
//     Those numbers for which this process ends in 1 are happy.
//  Return true if n is a happy number, and false if not.

// Naive Approach: Using set- takes extra space
class Solution {
public:
    bool isHappy(int n) {
        set <int> st;
        int sum = 0, index;
        while(1){
            while(n){
                index = n%10;
                sum += index*index;
                n /= 10;
            }
            if(sum==1)
                return true;
            else if(st.find(sum)!=st.end())
                return false;
            
            st.insert(sum);
            n = sum;
        }
        return false;
    }
};


// Using Floyd's Cycle Detection Algorithm

class Solution {
public:
    bool isHappy(int n) {
        int slow = num(n);
        int fast = num(num(n));
        while(slow!=fast){
            slow = num(slow);
            fast = num(num(fast));
        }
        return (slow==1);
    }
    
    int num(int n){
        int res = 0;
        while(n){
            res += pow(n%10, 2);
            n/=10;
        }
        return res;
    }
};
