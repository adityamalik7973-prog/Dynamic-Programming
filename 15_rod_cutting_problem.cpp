#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int recursive(int i, int n, vector<int> &price) {
    if (i < 0) return 0;
    if (n <= 0) return 0;
    int take = INT_MIN;
    if (n - i - 1 >= 0) take = price[i] + recursive(i, n - i - 1, price);
    int skip = recursive(i - 1, n, price);
    return max(take, skip);
}

int memoisation(int i, int n, vector<int> &price, vector<vector<int>> &dp) {
    if (i < 0) return 0;
    if (n <= 0) return 0;
    if (dp[i][n] != -1) return dp[i][n];
    int take = INT_MIN;
    if (n - i - 1 >= 0) take = price[i] + memoisation(i, n - i - 1, price, dp);
    int skip = memoisation(i - 1, n, price, dp);
    return dp[i][n] = max(take, skip);
}

int tabulation(int n, vector<int> &price) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int skip = dp[i - 1][j];
            int take = INT_MIN;
            if (j - i >= 0) take = price[i - 1] + dp[i][j - i];
            dp[i][j] = max(skip, take);
        }
    }
    return dp[n][n];
}

int spaceOptimised(int n, vector<int> &price) {
    vector<int> curr(n + 1, 0), prev(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int skip = prev[j];
            int take = INT_MIN;
            if (j - i >= 0) take = price[i - 1] + curr[j - i];
            curr[j] = max(skip, take);
        }
        prev = curr;
    }
    return prev[n];
}

int cutRod(vector<int> &price) {
    int n = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return spaceOptimised(n, price);
}

int main() {
    int n;
    cout << "Enter the size of the rod: ";
    cin >> n;

    vector<int> price(n);
    cout << "Enter the prices for lengths 1 to " << n << ":" << endl;
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    int maxProfit = cutRod(price);

    cout << "Maximum obtainable value is: " << maxProfit << endl;

    return 0;
}