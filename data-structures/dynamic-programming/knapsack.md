# Knapsack


## Unbounded

Given `n` elements and two arrays, `weight` and `values`, where `weight[i]` represents the weight of the ith number and `values[i]` represents the value of the ith number, we select a subset of elements having the most value such that its weight is less than or equal to `W`.

Here, each of the `n` elements could be selected any number of times.

### Example
```
Input : W = 100
       val[]  = {1, 30}
       wt[] = {1, 50}
Output : 100
There are many ways to fill knapsack.
1) 2 instances of 50 unit weight item.
2) 100 instances of 1 unit weight item.
3) 1 instance of 50 unit weight item and 50
   instances of 1 unit weight items.
We get maximum value with option 2.
```

### Approach

Here, for each element (say `n`) in the array, we have two options:

1. Include the n'th element in our answer subset
2. Exclude the n'th element from our answer subset

The answer would be the max of these two situations

### Recursion

```cpp
int memo(int W, int idx) {
    if (idx == 0) {
        return (W / weight[idx]) * value[idx];
    }

    int exclude = memo(W, idx-1);
    int include = INT_MIN;

    if (weight[idx] <= W) {
        include = value[idx] + memo(W - weight[idx], idx);
    }

    return max(include, exclude);
}

/*
 For DP
    dp[idx][W] = max(dp[idx][W], (weight[idx] <= W)? max(dp[idx-1][W], dp[idx][W-weight[idx]]): dp[idx-1][W])
*/
```