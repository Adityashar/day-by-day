# Painting or Robbing

1. Paint House 1/2/3
2. House Robber 1/2/3

## Paint House 1

```cpp

#define MAX 1e5

int paintHouse(int n, int k, vector<vector<int>> &cost) {
    vector<vector<int>> dp(n, vector<int>(k, MAX));
    int total = 0;

    for (int i=0; i<k; i++) {
        dp[0][i] = cost[i];
        total += dp[0][i];
    }

    for (int i=1; i<n; i++) {
        int localTotal = 0;
        for (int j=0; j<k; j++) {
            dp[i][j] = min(dp[i][j], total - dp[i-1][j] + cost[j])
            localTotal += dp[i][j];
        }
        total = localTotal;
    }

    int minima = MAX;
    for (auto &c: dp[n-1])
        minima = min(c, minima);

    return minima;
}


```