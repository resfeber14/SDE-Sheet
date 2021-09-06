// Problem Link: https://leetcode.com/problems/longest-common-prefix/

// N=size of vector M=max length of any string

// Approach 1: Time complexity: O(N*M) Space complexity: O(1)

// Just consider the first string as the longest-common-prefix.And then Check if that string is present in every other strings or not
// If not then simply make the longest common as answer

    string longestCommonPrefix(vector<string>& s) {
        string ans=s[0];
        for(int i=1;i<s.size();i++){
            string temp="";
            for(int j=0;j<min(s[i].length(),ans.length());j++){
                if(ans[j]==s[i][j])
                    temp+=ans[j];
                else
                    break;
            }
            ans=temp;
        }
        return ans;
    }
