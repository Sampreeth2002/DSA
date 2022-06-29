// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends


int currMin  = 1e9;

void push(stack<int>& s, int a){
	if(s.empty())
	{
	    currMin = a;
	    s.push(a);
	}
	else if(currMin > a)
	{
	    
	    s.push(2*a - currMin);
	    currMin = a;
	}
	else
	{
	    s.push(a);
	}
}

bool isFull(stack<int>& s,int n){
	return s.size()==n;
}

bool isEmpty(stack<int>& s){
	return s.empty();
}

int pop(stack<int>& s){
	int a = s.top();
	s.pop();
	if(a>currMin)
	    return a;
	else
	    return 2*currMin - a;
}

int getMin(stack<int>& s){
	return currMin;
}