// Problem Link: https://leetcode.com/problems/majority-element-ii/

// Approach 1: Time Complexity: O(Nlog(N)) Space Complexity: O(N)

// Store the frequnecy of each element in a map and iterate on map to check which element's frequency is > n/3

    vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            
        }
        for(auto it: m){
            if(it.second>n/3){
                v.push_back(it.first);
            }
        }
        return v;
    }

// Approach 2: Time Complexity: O(N) Space Complexity: O(1)
// Bayer Moore's algo
// Take 2 variables num1,num2,cnt1=0,cnt2=0
// if(arr[i]==num1) cnt1++ else if(arr[i]==num2) cnt2++ else if(cnt1==0) num1=arr[i],cnt1++ else if(cnt2==0) num2=arr[i] else cnt1--,cnt2--
// Now check for both num1 and num2 if they are present in arr >n/3 times

vector<int> majorityElement(vector<int>& arr) {
        int n=arr.size();
        vector<int> v;
        int cnt1=0,cnt2=0,num1,num2;
        for(int i=0;i<n;i++){
            if(arr[i]==num1){
                cnt1++;
            }
            else if(arr[i]==num2){
                cnt2++;
            }
            else if(cnt1==0){
                num1=arr[i];
                cnt1++;
            }
            else if(cnt2==0){
                num2=arr[i];
                cnt2++;
            }
            else {
                cnt1--,cnt2--;
            }
        }
        int x1=0,x2=0;
        for(int i=0;i<n;i++){
            if(arr[i]==num1){
                x1++;
            }
            else if(arr[i]==num2){
                x2++;
            }
        }
        if(x1>n/3){
            v.push_back(num1);
        }
        if(x2>n/3){
            v.push_back(num2);
        }
        return v;
    }

