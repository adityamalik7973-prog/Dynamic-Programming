#include<bits/stdc++.h>
using namespace std;
int recursive(int i,int n,vector<int> &coins,int amount){
    if(amount==0)return 0;
    if(i<0||amount<0)return INT_MAX;
    int take=recursive(i,n,coins,amount-coins[i]);
    int skip=recursive(i-1,n,coins,amount);
    return min(take==INT_MAX?take:1+take,skip);
}
int memoisation(int i,int n,vector<int> &coins,int amount,vector<vector<int>> &dp){
    if(amount==0)return 0;
    if(i<0||amount<0)return INT_MAX;
    if(dp[i][amount]!=-1)return dp[i][amount];
    int take=memoisation(i,n,coins,amount-coins[i],dp);
    int skip=memoisation(i-1,n,coins,amount,dp);
    return dp[i][amount]=min(take==INT_MAX?take:1+take,skip);
}
int tabulation(int n,vector<int> &coins,int amount){
    vector<vector<int>> dp(n+1,vector<int> (amount+1,INT_MAX));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<amount+1;j++){
            int take=INT_MAX;
            int skip=dp[i-1][j];
            if(j-coins[i-1]>=0)take=dp[i][j-coins[i-1]];
            dp[i][j]=min(skip,take==INT_MAX?take:take+1);
        }
    }
    return dp[n][amount];
}
int spaceOptimised(int n,vector<int> &coins,int amount){
    vector<int> dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            int take=INT_MAX;
            int skip=dp[j];
            if(j-coins[i-1]>=0)take=dp[j-coins[i-1]];
            dp[j]=min(skip,take==INT_MAX?take:take+1);
        }
    }
    return dp[amount];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,amount;
    cin>>n>>amount;
    vector<int> coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];

    vector<vector<int>> dp(n+1,vector<int> (amount+1,-1));
    int ans=spaceOptimised(n,coins,amount);
    cout<<(ans==INT_MAX?-1:ans);
    return 0;
}
