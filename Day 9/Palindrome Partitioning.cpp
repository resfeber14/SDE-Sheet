// Problem Link: https://leetcode.com/problems/palindrome-partitioning/

// Approach : Time Complexity: O(2^k * k)  Space Complexity: O(k*n)

// Iterate over all the indexes check if i...j is a palindrome or not.If yes then push that substring into a vector.and make a recursive call on the remaining sustring
// If i==n then push that vector into the vector<vector<>>

bool isPalindrome(string s){
        int i=0,j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    void solve(int i,string &s,vector<string> &vec,vector<vector<string> > &v){
        if(i==s.length()){
            v.push_back(vec);
            return;
        }
        for(int j=i;j<s.length();j++){
            string temp=s.substr(i,j-i+1);
            if(isPalindrome(temp)){
                vec.push_back(temp);
                solve(j+1,s,vec,v);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> v;
        vector<string> vec;
        solve(0,s,vec,v);
        return v;
    }
