// Problem Link: https://leetcode.com/problems/power-of-two/


// Approach 1: Time complexity: O(32) Space Complexity: O(1)

bool isPowerOfTwo(int n) {
        bool flag=false;
        for(int i=0;i<=30;i++){
            if(1<<i==n){
                flag=true;
                break;
            }
        }
        return flag;
    }

// Approach 2: Time complexity: O(log(N)) Space Complexity: O(1)

//  keep dividing the number by two, i.e, do n = n/2 iteratively. In any iteration, if n%2 becomes non-zero and n is not 1 then n is not a power of 2. 
// If n becomes 1 then it is a power of 2. 

bool isPowerOfTwo(int n) {
        if(n==0)
            return false;
        while(n!=1){
            if(n%2!=0)
              return false;
          n=n/2;
        }
        return true;
    }



// Approach 3: Time complexity: O(1) Space Complexity: O(1)

bool isPowerOfTwo(int n) {
    return n>0 && (n&(n-1))==0;
}
