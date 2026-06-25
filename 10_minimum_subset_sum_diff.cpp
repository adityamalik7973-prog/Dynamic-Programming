#include<bits/stdc++.h>
using namespace std;
int recursive(int n,vector<int> &nums,int target,int sum){
    if(n==0)return abs(target-2*sum);
    return min(recursive(n-1,nums,target,sum),recursive(n-1,nums,target,sum+nums[n-1]));
}
int memoise(int n,vector<int> &nums,int target,int sum,vector<vector<int>> &dp){
    if(n==0)return abs(target-2*sum);
    if(dp[n][sum]!=-1)return dp[n][sum];
    return dp[n][sum]=min(memoise(n-1,nums,target,sum,dp),memoise(n-1,nums,target,sum+nums[n-1],dp));
}
int tabulation(int n,vector<int> &nums,int target,int sum){
    vector<vector<bool>> dp(n+1,vector<bool> (target+1,false));
    for(int i=0;i<n+1;i++){
        dp[i][0]=true;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            dp[i][j]=dp[i-1][j];
            if(nums[i-1]<=j){
                dp[i][j]=dp[i][j] || dp[i-1][j-nums[i-1]];
            }
        }
    }
    int ans=INT_MAX;
    for(int j=0;j<=target;j++){
        if(dp[n][j]){
            ans=min(ans,abs(target-2*j));
        }
    }
    return ans;
}
int spaceOptimised(int n,vector<int>& nums,int target,int sum){
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=target;j>=nums[i-1];j--){
            dp[j]=dp[j] || dp[j-nums[i-1]];
        }
    }
    int ans=INT_MAX;
    for(int j=0;j<=target;j++){
        if(dp[j]){
            ans=min(ans,abs(target-2*j));
        }
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    int sum=accumulate(nums.begin(),nums.end(),0);
    vector<vector<int>> dp(nums.size()+1,vector<int> (sum+1,-1));
    cout<<spaceOptimised(nums.size(),nums,sum,0);
    return 0;
}
