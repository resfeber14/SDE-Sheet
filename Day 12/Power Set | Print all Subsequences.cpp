// Problem Link: NA

// Approach 1: Inclusion Exclusion: See Recursion day's repo

// Approach 2: Iterative


// Input = “abc” 
//Binary representation to consider 1 to (2^3-1), i.e 1 to 7. 
// Start from left (MSB) to right (LSB) of binary representation and append characters from input string which corresponds to bit value 1 in binary representation to Final
// subsequence string sub.

// Example: 
// 001 => abc . Only c corresponds to bit 1. So, subsequence = c. 
// 101 => abc . a and c corresponds to bit 1. So, subsequence = ac.
// binary_representation (1) = 001 => c 
// binary_representation (2) = 010 => b 
// binary_representation (3) = 011 => bc 
// binary_representation (4) = 100 => a 
// binary_representation (5) = 101 => ac 
// binary_representation (6) = 110 => ab 
// binary_representation (7) = 111 => abc


int main() {
	  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n=s.length();
    vector<string> subsequences;
    for(int mask=0;mask<(1<<n);mask++){
    	string temp="";
    	for(int j=0;j<n;j++){
    		if((mask&(1<<j))!=0){
    			temp+=s[j];
    		}
    	}
    	subsequences.push_back(temp);
    }
    for(int i=0;i<subsequences.size();i++){
    	cout<<subsequences[i]<<"\n";
    }
    
    return 0;
}
