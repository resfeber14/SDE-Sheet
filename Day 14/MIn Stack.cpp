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

// PUSH OPERATION
// If the stack is empty,then simply push into the stack and update minn=val
// else if minn is lesser than the val,then simply push that into the stack
// else if minn is greater than val,then we will push 2*val-minn into the stack.
// 2*val-minn will always be lesser than the minn because:
// val<minn  => 2*val < 2*minn => 2*val-minn< 2*minn - minn   => 2*val-minn< minn (Proved)
// Hence we are pushing the smaller element than minn.So,This will indicate that currently the top no is the minn not what is on s.top() 

// POP OPERATION
// If the stack is empty,then simply update minn=val
// else if minn<val ,then do not update the minn
// else if minn>=val,then update minn= 2*minn-s.top()
// WHY?
// because : minn=2*minn-s.top() (WHat we have considered)
// So the minn is val which was given to us
// And here,s.top() is the 2*val- (prev_Minimum)
// And also this val is equal to minn bcoz the val was pushed earlier then minn was updated to val bcoz minn was greater than val
// Hence now we can write minn= 2*minn-(2*val-prevMinimum)
// minn= 2*minn-(2*minn-prevMinimum)
// minn=prevMinimum(Proved)
// That's how we can restore it prevMinimum:)


stack<long long int> s;
    long long int minn=INT_MIN;
    MinStack() {
        while(!s.empty())
            s.pop();
        minn=INT_MIN;
    }
    
    void push(int val) {
        if(s.empty()){
            s.push(val);
            minn=val;
        }
        else{
            if(minn<val){
                s.push(val);
            }
            else{
                s.push(1LL*2*val-minn);
                minn=val;
            }
        }
    }
    
    void pop() {
        if(s.top()>=minn){
            s.pop();
        }
        else{
            minn=2*minn-s.top();
            s.pop();
        }
    }
    
    int top() {
        if(s.top()<minn){
            return minn;
        }
        return s.top();
    }
    
    int getMin() {
        return minn;
    }
