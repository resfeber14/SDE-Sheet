// Problem Link: NA Seach on gfg

// Queue using Arrays
    // Imagine the queue can hold at max N elements 

    int front=0,rear=0;
    int cnt=0; // stores count of the elements
    
// For pushing into the queue
    void push(int x){
    	if(cnt==n){  // queue is full
    		return -1;
    	}
    	arr[rear%n]=x;
    	rear++;
    	cnt++;
    } 
// popping the elements

    void pop(){
    	if(cnt==0)
    		arr[front%n]=-1;
    	else{
    		front++;
    		cnt--;
    	}
    }

// returning the front of the queue

    void top(){
			
    	if(cnt==0){    //If there are no elments in the queue
    		return -1;
    	}
    	
    	return arr[front%n];
    	
    }
// Checking if the queue is empty or not

    bool empty(){
    	return cnt==0;
    }

// for printing all the elements of the queue

    if(cnt==0){
    	return ;
    }
    for(int i=front;i<=rear;i++){
    	cout<<arr[i%n]<<" ";
    }
