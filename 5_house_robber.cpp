#include <bits/stdc++.h>
using namespace std;

int memo(int n,vector<int> &dp,vector<int> &nums){
    if(n==0)return nums[0];
    if(n==1)return max(nums[0],nums[1]);
    if(dp[n]!=-1)return dp[n];
    return dp[n]=max(nums[n]+memo(n-2,dp,nums),memo(n-1,dp,nums));
}
int tab(int n,vector<int> &dp,vector<int> &nums){
    dp[0]=nums[0];
    if(n>=1)dp[1]=max(nums[1],nums[0]);
    for(int i=2;i<=n;i++){
        dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
    }
    return dp[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    vector<int> dp(n,-1);
    cout<<tab(n-1,dp,nums);
    return 0;
}
