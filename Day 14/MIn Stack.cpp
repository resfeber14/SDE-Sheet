// Problem Link:  https://leetcode.com/problems/min-stack/

// Approach: Time complexity: O(1)  Space complexity: O(2*N)

// Store element in a stack
// To find minimum element in O(1) Time,use another stack in which we will push minimum element till now into that
// When we push an element in the stack we check if in the second stack if its top is greater than the element whoch we are gonna push
// If it greater then,we need to push the element in the both stacks


stack<int> s,s1;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(s1.empty()){
            s1.push(val);
        }
        else if(s1.top()>=val){
            s1.push(val);
        }
    }
    
    void pop() {
        if(s1.top()==s.top()){
            s1.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s1.top();
    }

// Approach 2: Time complexity: O(1)  Space complexity: O(2*N)
// Instead of taking 2 stacks,take only one stack which will store current value and minimum element till now


 stack<pair<int,int> > s;
    MinStack() {
        
    }
    
    void push(int val) {
        if(s.empty()){
            s.push({val,val});
        }
        else{
            if(s.top().second>=val){
                s.push({val,val});
            }
            else{
                s.push({val,s.top().second});
            }
        }
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};


// Approach 2: Time complexity: O(1)  Space complexity: O(N)


