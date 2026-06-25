#include<bits/stdc++.h>
using namespace std;
int recursive(int l,int r,int n,vector<int> &prices){
    if(l>r)return 0;
    int day=n-(r-l);
    int op1=prices[l]*day+recursive(l+1,r,n,prices);
    int op2=prices[r]*day+recursive(l,r-1,n,prices);
    return max(op1,op2);
}
int memoisation(int l,int r,int n,vector<int> &prices,vector<vector<int>> &dp){
    if(l>r)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int day=n-(r-l);
    int op1=prices[l]*day+memoisation(l+1,r,n,prices,dp);
    int op2=prices[r]*day+memoisation(l,r-1,n,prices,dp);
    return dp[l][r]=max(op1,op2);
}
int tabulation(int n,vector<int> &prices){
    vector<vector<int>> dp(n,vector<int> (n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=prices[i]*n;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=i+1;j<n;j++){
            int day=n-(j-i);
            int op1=prices[i]*day+dp[i+1][j];
            int op2=prices[j]*day+dp[i][j-1];
            dp[i][j]=max(op1,op2);
        }
    }
    return dp[0][n-1];
}
int spaceOptimised(int n,vector<int> &prices){
    vector<int> curr(n,0),prev(n,0);
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            int day=n-(j-i);
            int op1=prices[i]*day+prev[j];
            int op2=prices[j]*day+curr[j-1];
            curr[j]=max(op1,op2);
        }
        prev=curr;
    }
    return prev[n-1];
}
int ultraspaceOptimised(int n, vector<int> &prices) {
    vector<int> dp(n, 0);
    
    for(int i = n - 1; i >= 0; i--) {
        dp[i] = prices[i] * n; 
        
        for(int j = i + 1; j < n; j++) {
            int day = n - (j - i);
            int op1 = prices[i] * day + dp[j];
            int op2 = prices[j] * day + dp[j - 1];
            
            dp[j] = max(op1, op2);
        }
    }
    return dp[n - 1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> prices(n);
    for(int i=0;i<n;i++)cin>>prices[i];
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    cout<<tabulation(n,prices);
    return 0;
}
