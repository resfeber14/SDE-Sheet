// Problem Link: https://leetcode.com/problems/reverse-words-in-a-string/

// Approach: Time complexity: O(N) Space Complexity: O(N)

// Just store all the strings without the space in a vector
// And make a string out of it

    string reverseWords(string s) {
        int n=s.length();
        vector<string> v;
        string temp="";
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(temp=="")
                    continue;
                else{
                    v.push_back(temp);
                    temp="";
                }
            }
            else{
                temp=s[i]+temp;
            }
        }
        if(temp!=""){
            v.push_back(temp);
        }
        cout<<v.size()<<" ";
        string ans="";
        for(int i=0;i<v.size();i++){
            if(ans==""){
                ans+=v[i];
            }
            else ans= ans+" "+v[i];
        }
        return ans;
    }
