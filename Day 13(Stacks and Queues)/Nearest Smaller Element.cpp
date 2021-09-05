// Problem Link:  https://www.interviewbit.com/problems/nearest-smaller-element/

vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n=arr.size();
    stack<int> s;
    vector<int> v;
    for(int i=0;i<n;i++){
        
        while(!s.empty() && s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty()){
            v.push_back(-1);
        }
        else{
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }
    return v;
}
