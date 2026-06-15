#include<bits/stdc++.h>
using namespace std;
int recursive(int n,vector<int> &nums,int target){
    if(n==0)return (target==0);
    int op1=recursive(n-1,nums,target);
    int op2=recursive(n-1,nums,target-nums[n-1]);
    return op1+op2;
}
int memoise(int n,vector<int>&nums,int target,vector<vector<int>> &dp){
    if(n==0)return (target==0);
    if(dp[n][target]!=-1)return dp[n][target];
    if(nums[n-1]<=target){
        int op1=memoise(n-1,nums,target,dp);
        int op2=memoise(n-1,nums,target-nums[n-1],dp);
        return dp[n][target]=op1+op2;
    }else return dp[n][target]=memoise(n-1,nums,target,dp);
}
int bottomUp(int n,vector<int> &nums,int target){
    vector<vector<int>> dp(nums.size()+1,vector<int> (target+1,0));
    dp[0][0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            if(nums[i-1]<=j){
                dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][target];
}
int spaceOptimised(int n, vector<int> &nums, int target){
    vector<int> prev(target + 1, 0);
    prev[0] = 1; 
    
    for(int i = 1; i <= n; i++){
        vector<int> curr(target + 1, 0);
        for(int j = 0; j <= target; j++){
            if(nums[i-1] <= j){
                curr[j] = prev[j] + prev[j - nums[i-1]];
            } else {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[target];
}
int main(){
    vector<int> nums={12,25,42,49,41,15,22,34,28,31};
    int target=35;
    int sum=accumulate(nums.begin(),nums.end(),0);
    if((abs(sum+target))%2==1)cout<<0<<endl;
    else{
        int req=abs(sum+target);
        req/=2;
        vector<vector<int>> dp(nums.size()+1,vector<int> (req+1,-1));
        cout<<spaceOptimised(nums.size(),nums,req);
    }
}