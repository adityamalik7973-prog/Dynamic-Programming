#include <bits/stdc++.h>
using namespace std;

int memo(int n, int k, vector<int> &dp, vector<int> &heights) {
    if (n == 0) return 0;
    if (dp[n] != -1) return dp[n];

    int ans = INT_MAX;
    for (int jump = 1; jump <= k; jump++) {
        if (n - jump >= 0) {
            ans = min(ans, memo(n - jump, k, dp, heights) + abs(heights[n] - heights[n - jump]));
        }
    }

    return dp[n] = ans;
}

int tab(int n, int k, vector<int> &dp, vector<int> &heights) {
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int jump = 1; jump <= k; jump++) {
            if (i - jump >= 0) {
                dp[i] = min(dp[i], dp[i - jump] + abs(heights[i] - heights[i - jump]));
            }
        }
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) cin >> heights[i];

    vector<int> dp(n, -1);
    cout << tab(n - 1, k, dp, heights);

    return 0;
}
