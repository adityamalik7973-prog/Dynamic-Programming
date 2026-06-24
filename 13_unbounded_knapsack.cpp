#include <bits/stdc++.h>
using namespace std;

int recursive(int i, int n, vector<int> &val, vector<int> &wt, int cap) {
    if (i < 0) return 0;
    if (cap <= 0) return 0;

    int skip = recursive(i - 1, n, val, wt, cap);
    int take = INT_MIN;

    if (wt[i] <= cap) take = val[i] + recursive(i, n, val, wt, cap - wt[i]);

    return max(skip, take);
}

int memoisation(int i, int n, vector<int> &val, vector<int> &wt, int cap, vector<vector<int>> &dp) {
    if (i < 0) return 0;
    if (cap <= 0) return 0;
    if (dp[i][cap] != -1) return dp[i][cap];

    int skip = memoisation(i - 1, n, val, wt, cap, dp);
    int take = INT_MIN;

    if (wt[i] <= cap) take = val[i] + memoisation(i, n, val, wt, cap - wt[i], dp);

    return dp[i][cap] = max(skip, take);
}

int tabulation(int n, vector<int> &val, vector<int> &wt, int cap) {
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, -1));

    for (int i = 0; i <= cap; i++) {
        dp[0][i] = 0;
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cap; j++) {
            int skip = dp[i - 1][j];
            int take = INT_MIN;

            if (wt[i - 1] <= j) take = val[i - 1] + dp[i][j - wt[i - 1]];

            dp[i][j] = max(skip, take);
        }
    }

    return dp[n][cap];
}

int spaceOptimised(int n, vector<int> &val, vector<int> &wt, int cap) {
    vector<int> curr(cap + 1), prev(cap + 1);
    prev[0] = 0;
    curr[0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cap; j++) {
            int skip = prev[j];
            int take = INT_MIN;

            if (wt[i - 1] <= j) take = val[i - 1] + curr[j - wt[i - 1]];

            curr[j] = max(skip, take);
        }

        prev = curr;
    }

    return prev[cap];
}


int main() {
    vector<int> val = {10, 40, 50, 70};
    vector<int> wt = {1, 3, 4, 5};
    int capacity = 8;

    cout << "Maximum profit: " << spaceOptimised(val.size(),val, wt, capacity) << endl;

    return 0;
}
