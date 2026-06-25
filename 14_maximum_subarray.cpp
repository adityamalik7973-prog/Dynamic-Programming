#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursive(int i,int n,vector<int> &nums){
        if(i<0)return 0;
        if(n==1)return nums[n-1];
        int op1=nums[i]+recursive(i-1,n,nums);
        int op2=nums[i];
        return max(op1,op2);
    }
    int memoisation(int i,int n,vector<int> &nums,vector<int> &dp){
        if(i<0)return 0;
        if(n==1)return nums[n-1];
        if(dp[i]!=INT_MIN)return dp[i];
        int op1=nums[i]+memoisation(i-1,n,nums,dp);
        int op2=nums[i];
        return dp[i]=max(op1,op2);
    }
    int tabulation(int n,vector<int> &nums){
        vector<int> dp(n,INT_MIN);
        dp[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(nums[i]+dp[i-1],nums[i]);
            ans=max(ans,dp[i]);
        }
        return ans;
    }
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int n=nums.size();
        // vector<int> dp(n,INT_MIN);
        // for(int i=0;i<n;i++){
        //     ans=max(ans,memoisation(i,n,nums,dp));
        // }
        int prev=nums[0],curr;
        for(int i=1;i<n;i++){
            curr=max(nums[i]+prev,nums[i]);
            
            prev=curr;
            ans=max(ans,prev);
        }
        ans=max(ans,prev);
        return ans;
        
        
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    cout << solution.maxSubArray(nums) << endl;

    return 0;
}
