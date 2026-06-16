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
    vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
    for(int j=0;j<sum+1;j++){
        dp[0][j]=abs(target-2*j);
    }
    for(int i=1;i<n+1;i++){
        for(int j=0;j<sum+1;j++){
            dp[i][j]=min(dp[i-1][j],dp[i-1][j+nums[i-1]]);
        }
    }
    return dp[n][sum];
}
int spaceOptimised(int n,vector<int>& nums,int target,int sum){
    vector<int> dp(target+1);
    for(int j=0;j<target+1;j++){
        dp[j]=abs(target-2*j);
    }
    for(int i=1;i<n+1;i++){
        for(int j = 0; j <= target; j++) {
            if (j + nums[i-1] <= target) {
                dp[j] = min(dp[j], dp[j + nums[i-1]]);
                }
        }
    }
    return dp[sum];
}
int main(){
    vector<int> nums={1,2,3,4};
    int sum=accumulate(nums.begin(),nums.end(),0);
    vector<vector<int>> dp(nums.size()+1,vector<int> (sum+1,-1));
    cout<<tabulation(nums.size(),nums,sum,0);
}