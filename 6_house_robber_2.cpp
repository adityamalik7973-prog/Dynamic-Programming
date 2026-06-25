#include <bits/stdc++.h>
using namespace std;

int memo(int n,vector<int> &dp,vector<int> &nums,int s){
    if(n<s)return 0;
    if(n==s)return nums[s];
    if(dp[n]!=-1)return dp[n];
    return dp[n]=max(nums[n]+memo(n-2,dp,nums,s),memo(n-1,dp,nums,s));
}
int tab(int n,vector<int> &nums,int s){
    if(n<s)return 0;
    if(n==s)return nums[s];
    vector<int> dp(n+1,-1);
    dp[s]=nums[s];
    if(s+1 <= n && s+1 < nums.size()){
        dp[s+1]=max(nums[s],nums[s+1]);
    }
    for(int i=s+2;i<=n;i++){
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

    if(n==1){
        cout<<nums[0];
        return 0;
    }
    vector<int> dp1(n,-1);
    vector<int> dp2(n,-1);
    int case1=tab(n-2,nums,0);
    int case2=tab(n-1,nums,1);
    cout<<max(case1,case2);
    return 0;
}
