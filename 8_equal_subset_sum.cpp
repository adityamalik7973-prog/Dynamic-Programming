#include<bits/stdc++.h>
using namespace std;
bool recursive(int n,vector<int> &nums,int target){
    if(target==0)return 1;
    if(n==0)return 0;
    bool op1=recursive(n-1,nums,target);
    bool op2=recursive(n-1,nums,target-nums[n-1]);
    return op1 or op2;
}
bool memoise(int n,vector<int> &nums,int target,vector<vector<int>> &dp){
    if(target==0)return 1;
    if(n==0)return 0;
    if(dp[n][target]!=-1)return dp[n][target];
    if(nums[n-1]<=target){
        bool op1=memoise(n-1,nums,target,dp);
        bool op2=memoise(n-1,nums,target-nums[n-1],dp);
        return dp[n][target]=op1 or op2;
    }else return memoise(n-1,nums,target,dp);
}
bool tabulation(int n,vector<int> &nums,int target){
    vector<vector<bool>> dp(n+1,vector<bool>(target+1,0));
    for(int i=0;i<n+1;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(nums[i-1]<=j){
                dp[i][j]=dp[i-1][j] or dp[i-1][j-nums[i-1]];
            }else dp[i][j]=dp[i-1][j];     
        }
    }
    return dp[n][target];
}
bool spaceOptimised(int n,vector<int> &nums,int target){
    vector<int> prev(target+1,0);
    vector<int> curr(target+1,0);
    prev[0]=1,curr[0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(nums[i-1]<=j){
                curr[j]=prev[j] or prev[j-nums[i-1]];
            }else curr[j]=prev[j];
        }
        prev=curr;
    }
    return prev[target];
}
bool ultraSpaceOptimised(int n,vector<int> &nums,int target){
    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<n+1;i++){
        for(int j=target;j>=nums[i-1];j--){
            dp[j]=dp[j] or dp[j-nums[i-1]];
        }
    }
    return dp[target];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];

    int sum=accumulate(nums.begin(),nums.end(),0);
    if(sum%2==1){
        cout<<0<<endl;
    }else{
        int target=sum/2;
        vector<vector<int>> dp(nums.size()+1,vector<int> (target+1,-1));
        cout<<ultraSpaceOptimised(nums.size(),nums,target);
    }
    return 0;
}
