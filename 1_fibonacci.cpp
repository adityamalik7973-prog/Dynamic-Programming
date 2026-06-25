#include <bits/stdc++.h>
using namespace std;

int fibo1(int n,vector<int> &dp){
    if(n<=1)return n;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=fibo1(n-1,dp)+fibo1(n-2,dp);
}
int fibo2(int n,vector<int> &dp){
    if(n<=1)return n;
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> dp(n+1,-1);
    cout<<fibo2(n,dp);
    return 0;
}
