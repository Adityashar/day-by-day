#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

#define MAX 1e5
#define p pair<int, int>

void updateMinimums(p *minOne, p *minTwo, int v, int k) {
    if (v < minOne->first) {
        p temp = *minOne;
        *minOne = {v, k};
        *minTwo = temp;
    } else if (v < minTwo->first && v >= minOne->first) {
        *minTwo = {v, k};
    }
}

int paintHouse(int n, int k, vector<vector<int>> &cost) {
    vector<vector<int>> dp(n, vector<int>(k));
    p minOne = {MAX, 0};
    p minTwo = {MAX, 1};

    for (int i=0; i<k; i++) {
        dp[0][i] = cost[0][i];
        updateMinimums(&minOne, &minTwo, dp[0][i], i);
    }

    for (int i=1; i<n; i++) {
        p tempMinOne, tempMinTwo;
        tempMinOne = tempMinTwo = {MAX, 0};
        for (int j=0; j<k; j++) {
            int minValue = minOne.first;
            if (j == minOne.second)
                minValue = minTwo.first;

            dp[i][j] = minValue + cost[i][j];
            
            updateMinimums(&tempMinOne, &tempMinTwo, dp[i][j], j);
        }
        minOne = tempMinOne;
        minTwo = tempMinTwo;
    }

    int minima = MAX;
    for (auto &c: dp[n-1])
        minima = min(c, minima);

    // for (auto &i: dp) {
    //     for (auto &j: i) {
    //         printf("%d ", j);
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    return minima;
}

int main() {
    vector<vector<int>> c1 = {{1,5,3},{2,9,4}};
    cout<<paintHouse(c1.size(), c1[0].size(), c1)<<endl;

    vector<vector<int>> c2 = {{6,5,3},{2,9,4}, {3,2,3}};
    cout<<paintHouse(c2.size(), c2[0].size(), c2)<<endl;

    vector<vector<int>> c3 = {{4,1,2,6},{3,4,4,5},{1,2,2,1}};
    cout<<paintHouse(c3.size(), c3[0].size(), c3)<<endl;
}