
// Problem Link:  https://leetcode.com/problems/majority-element/

// Approach 1: Time Complexity: O(N*logN) Space Complexity: O(N)
// Take a hash map and store into it frequnecy of each element and return the element whose frequnecy is >n/2

// Approach 2: Time Complexity: O(N*32) Space Complexity: O(N)

// count the no of bits at each position and form a no by taking the bits from the position whose count> n/2

int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int bits[32];
        memset(bits,0,sizeof(bits));
        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if((nums[i] &(1<<j))!=0){
                    bits[j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<32;i++){
            if(bits[i]>n/2){
                ans= ans | (1<<i);
            }
        }
        return ans;
    }

// Approach 3: Time Complexity: O(N*logN) Space Complexity: O(N)
// Sort the array and return the mid element as the frequency of majority is >n/2. So,this will give correct answer.

// Approach 4: Moore's Voting Algorithm

// take a count and ans variable.If cnt==0,it means all the count elements till now have cancelled each other,so consider the current element as the majority element and
// increment the count variable
// if count>0 then if arr[i]==ans cnt++ else cnt--

 int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int cnt=0,ans=0;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt++;
                ans=arr[i];
            }
            else{
                if(arr[i]==ans){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }
        return ans;
    }
