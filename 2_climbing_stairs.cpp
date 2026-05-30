#include<iostream>
#include<vector>
using namespace std;
int memo(int n,vector<int> &dp){
    if(n==1)return 1;
    if(n==2)return 2;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=memo(n-1,dp)+memo(n-2,dp);
}
int tab(int n,vector<int> &dp){
    dp[1]=1;
    if(n>1)dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    int n;cin>>n;
    vector<int> dp(n+1,-1);
    cout<<tab(n,dp);
}