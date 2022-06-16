// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       vector<int> petrol;
       vector<int> distance;
       
       for(int i=0;i<n;i++)
       {
           petrol.push_back(p[i].petrol);
           distance.push_back(p[i].distance);
       }
       
       int firstStop = 0;
       int balance = 0;
       int needToHave = 0;
       
       for(int i=0;i<n;i++)
       {
           if(balance + petrol[i]-distance[i] >= 0)
           {
               balance += petrol[i]-distance[i];
           }
           else
           {
               needToHave += balance + petrol[i]-distance[i];
               firstStop = i+1;
               balance = 0;
           }
       }
       
       if(needToHave+balance>=0 && firstStop<=n-1)
       {
           return firstStop;
       }
       else
       {
           return -1;
       }
       
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends