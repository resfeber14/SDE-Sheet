// Same as Reverse a Stack

// The idea of the solution is to hold all values in Function Call Stack until the stack becomes empty. When the stack becomes empty, 
// insert all held items one by one in sorted order. Here sorted order is important.

void sort(stack<int> &s,int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	else if(s.top()<=x){
		s.push(x);
		return;
	}
	int y=s.top();
	s.pop();
	sort(s,x);
	s.push(y);
}

void solve(stack<int> &s){
	if(s.size()>0){
		int x=s.top();
		s.pop();
		solve(s);
		sort(s,x);
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    stack<int> s;
    for(int i=0;i<n;i++){
    	int x;
    	cin>>x;
    	s.push(x);
    }
    solve(s);
    while(!s.empty()){
    	cout<<s.top()<<" ";
    	s.pop();
    }
    
    
    return 0;
}
