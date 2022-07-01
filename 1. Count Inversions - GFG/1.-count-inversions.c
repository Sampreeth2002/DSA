// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.


long long mergeringArrays(long long arr[],long long n,long long left,long long mid, long long right,long long temp[])
{
    long long i = left;
    long long j = mid;
    long long k = left;
    // long long temp[];
    long long int inversions = 0;
    
    while((i<mid) && (j<=right))
    {
        
        if(arr[i]<=arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            inversions += (mid-i);
            temp[k++] = arr[j++];
        }
        
    }
    
    while(i<mid)
    {
        temp[k++] = arr[i++];
    }
    while(j<=right)
    {
        temp[k++] = arr[j++];
    }
    
    for(i = left;i<=right;i++)
    {
        arr[i] = temp[i];
    }
    
    return inversions;
    
    
}



long long mergerSort(long long arr[],long long n,long long left,long long right,long long temp[])
{
    long long int inversions = 0;
    if(left < right)
    {
        long long mid = (left+right)/2;
        
        
         inversions += mergerSort(arr,n,left,mid,temp);
         inversions += mergerSort(arr,n,mid+1,right,temp);
        
         inversions += mergeringArrays(arr,n,left,mid+1,right,temp); 
        
    }
    
    return inversions;
}


long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
    long long int ans = mergerSort(arr,N,0,N-1,temp);
    return ans;
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends