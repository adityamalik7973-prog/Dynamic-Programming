#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll recursive(ll n,ll w,vector<ll> &val,vector<ll> &weight){
    if(n==0||w==0)return 0;
    if(weight[n-1]<=w){
        return max(val[n-1]+recursive(n-1,w-weight[n-1],val,weight),recursive(n-1,w,val,weight));
    }else return recursive(n-1,w,val,weight);
}
ll memoise(ll n, ll w, vector<ll> &val,vector<ll> &weight,vector<vector<ll>> &dp){
    if(n==0||w==0)return 0;
    if(dp[n][w]!=-1)return dp[n][w];
    if(weight[n-1]<=w){
        return dp[n][w]=max(val[n-1]+memoise(n-1,w-weight[n-1],val,weight,dp),memoise(n-1,w,val,weight,dp));
    }else return dp[n][w]=memoise(n-1,w,val,weight,dp);
}
ll tabulation(ll n,ll w,vector<ll> &val,vector<ll> &weight){
    vector<vector<ll>> dp(n+1,vector<ll> (w+1,0));
    for(ll i=1;i<n+1;i++){
        for(ll j=1;j<w+1;j++){
            if(weight[i-1]<=j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}
ll space_optimized(ll n,ll w,vector<ll> &val,vector<ll> &weight){
    vector<ll> prev(w+1,0);
    vector<ll> curr(w+1,0);
    for(ll i=1;i<n+1;i++){
        for(ll j=1;j<w+1;j++){
            if(weight[i-1]<=j){
                curr[j]=max(val[i-1]+prev[j-weight[i-1]],prev[j]);
            }else curr[j]=prev[j];
        }
        prev=curr;
    }
    return curr[w];
}
void solve(){
    ll n,w;cin>>n>>w;
    vector<ll> val(n+1),weight(n+1);
    for(ll i=0;i<n;i++)cin>>weight[i]>>val[i];
    vector<vector<ll>> dp(n+1,vector<ll> (w+1,-1));
    cout<<space_optimized(n,w,val,weight);
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}