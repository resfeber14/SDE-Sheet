// Problem Link:  https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1#

// Problem Statement

// Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
// Find these two numbers.

// Approach 1: Time Complexity: O(N), Space Complexity: O(N)

// To get the repeating element, store the frequency of array in a map.
// For getting the missing element, find the sum of 1...N and find the sum of the array. Then the missing element will be abs(sum of array-repeating element-sum(1..N))

int *findTwoElement(int *arr, int n) {
        // code here
        int *a= new int(2);
        map<int,int> m;
        long long int sum=0;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
            if(m[arr[i]]==2){
                a[0]=arr[i];
            }
            sum+=arr[i];
        }
        long long int curr= (1LL*n*(n+1))/2;
        a[1]= abs(sum-a[0]-curr);
        return a;
    }

// Approach 2:  Time Complexity: O(N) , Space Complexity: O(N)

// We will take a frequency array of size n which will store the frequency of 1....N.
// traverse the frequnecy array again, the index at which freq[i]==0 then that i is the missing element and if freq[i]==2,then i is the repeating element.


   int *findTwoElement(int *arr, int n) {
        int *a= new int(2);
        int freq[n+1];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(freq[i]==0){
                a[1]=i;
            }
            else if(freq[i]==2){
                a[0]=i;
            }
        }
        return a;
    }
    
// Approach 3: Time Complexity: O(N) , Space Complexity: O(N)

// Find Sum of all the the ekements of the array and sum of sqauares of these elements of an array in two variable
// Add summation of (1...N) in the first variable and sum of squares from (1...N) in the 2nd variable
// Now subtract sum of squares and also sum  (x+y), (x^2 -y^2)
// now (x^2-y^2)= (x+y)*(x-y)
// substitute (x-y) and get (x+y)
// Now we know (x-y) and (x+y), find x,y
// check if x is present in array or not.If it is then it is a repeating no and y is missing no else vice versa.






// Approach 4: Time Complexity: O(N) , Space Complexity: O(1)

// Step 1: Find XOR of all the elements of an array,say x.
// Step 2: Find XOR of x with xor of(1......N),say Y
// Step 3: Hence, Missing element ^ Repeaated Element = Y (As all the elements will be in even no. if we combine the array and (1...N) except the repeated element(whose frequency
// will be 3 and the missing elemnt whose frequency will be 1)
// Step 4:  Hence we get  Missing element ^ Repeaated Element = Y
// Step 5: Separate the array in 2 buckets,such that if some bit is set in Y then in one bucket keep those elements whose that bit is set and in another bucket,keep those
// elements whose that bit is not set,as we know if in Y some bit is set then there will be one no whose bit will be set and another whose is not as we have done the XOR.

// Step 6: Now do the same with the elements from (1....N)(i.e. segregate them into the same buckets).
// step 7: Take the XOR of each bucket.now one of them will be missing element and other will be the repeating element.
// Step 8: Now to get which of them is repeating,traverse the array to check if one of them is present or not.If not then that is the Missing element and other is Repeating
// element and vice versa.

int *findTwoElement(int *arr, int n) {
        // code here
        int x=0;
        
        for(int i=0;i<n;i++){
            x = (x ^ arr[i]);
        }
        for(int i=1;i<=n;i++){
            x = (x ^ i);
        }
        int y=1;
        while(1){
            if((y & x) !=0){
                break;
            }
            y=y<<1;
        }
        int p=0,q=0;
        for(int i=0;i<n;i++){
            if((arr[i] & (y))==0){
                p= (p ^ arr[i]);
            }
            else{
                q = (q ^ arr[i]);
            }
            if(((i+1) & y)==0){
                p=(p ^ (i+1));
            }
            else{
                q = (q ^ (i+1));
            }
        }
        
        int *a=new int(2);
        for(int i=0;i<n;i++){
            if(q==arr[i]){
                a[0]=q;
                a[1]=p;
                return a;
            }
        }
        a[0]=p,a[1]=q;
        return a;
    }
