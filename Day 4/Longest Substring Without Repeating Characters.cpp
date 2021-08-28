// Problem link:  https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Approach: SLiding Window  Time complexity: O(2*N) Space Complexity: O(N)

int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int i=0,j=0,ans=0;
        map<char,int> m;
        int cnt=0;
        while(j<n){
            m[s[j]]++;
            if(m.size()<j-i+1){
                while(!m.empty() && m.size()<j-i+1){
                    m[s[i]]--;
                    if(m[s[i]]==0){
                        m.erase(s[i]);
                    }
                    i++;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }


// Approach 2: Time complexity: O(N) Space Complexity: O(N)


