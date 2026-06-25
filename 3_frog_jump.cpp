#include <bits/stdc++.h>
using namespace std;

int memo(int n,vector<int> &dp,vector<int> &heights){
    if(n==0)return 0;
    if(n==1)return abs(heights[1]-heights[0]);
    if(dp[n]!=-1)return dp[n];
    return min(memo(n-1,dp,heights)+abs(heights[n]-heights[n-1]),memo(n-2,dp,heights)+abs(heights[n]-heights[n-2]));
}
int tab(int n,vector<int> &dp,vector<int> &heights){
    dp[0]=0;
    if(n>1)dp[1]=abs(heights[0]-heights[1]);
    for(int i=2;i<=n;i++){
        dp[i]=min(dp[i-1]+abs(heights[i]-heights[i-1]),dp[i-2]+abs(heights[i]-heights[i-2]));
    }
    return dp[n];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> heights(n);
    for(int i=0;i<n;i++)cin>>heights[i];

    vector<int> dp(n,-1);
    cout<<tab(n-1,dp,heights);
    return 0;
}
