// Problem Link: https://leetcode.com/problems/powx-n/


// Approach 1:  Time Complexity: O(N) Space Complexity: O(1)

// Take ans=1,Run a loop from 1 to n ans=*x
// If n<0 then do x=1/x, n=-1*n,here overflow can happen, as when x=1 and n=-2147483648 ,then overflow will happen as any integer can go upto 2147483647.
// So to avoid this, use long long n

double myPow(double x, int n) {
        long long nn=n;
        if(n<0){
            nn=-1*nn;
            x=1/x;
        }
        double ans=1;
        for(long long int i=1;i<=nn;i++){
            ans= ans*x;
        }
        return ans;
    }

// Approach 2: Binary Exponentiation  Time Complexity: O(logN) Space Complexity: O(1) 
// We can also use long long here.But in the below solution we will not use and do something else to avoid overflow

double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double p,ans;
        if(n%2){
            if(n<0){
                p=myPow(1/x,(n/2)*-1);
                ans= (1/x)*p*p;
            }
            else{
                p=myPow(x,n/2);
                ans= x*p*p;
            }
            return ans;
        }
          
            if(n<0){
                p=myPow(1/x,(n/2)*-1);
                ans= p*p;
            }
            else{
                p=myPow(x,n/2);
                ans= p*p;
            }
            return ans;
    }
