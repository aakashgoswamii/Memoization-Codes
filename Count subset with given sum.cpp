#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&arr,int n,int sum,vector<vector<int>>&memo,int pos)
    {
        if(sum==0)
            return 1;
        if(pos>=n||sum<0)
            return 0;
        
        if(memo[pos][sum]!=-1)
            return memo[pos][sum];
        int c1 = solve(arr,n,sum,memo,pos+1);
        int c2 = solve(arr,n,sum-arr[pos],memo,pos+1);
        memo[pos][sum] = c1+c2;
        return memo[pos][sum];
    }
    
int main()
    {
        vector<int>arr = {3,1,2,3};
        int sum = 6;
        int n = arr.size();
        vector<vector<int>>memo(n+1,vector<int>(sum+1,-1));
        cout<<solve(arr,n,sum,memo,0)<<endl;
        return 0;
    }
