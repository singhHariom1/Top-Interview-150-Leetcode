#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Brute Force (Check every pair)
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution_BruteForce {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                if (prices[j] > prices[i]) {
                    maxProfit = max(maxProfit, prices[j] - prices[i]);
                }
            }
        }
        return maxProfit;
    }
};


// 🟢 Approach 2: Optimal One-Pass (Greedy)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int mini = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < mini) {
                mini = prices[i];
            } else {
                maxProfit = max(maxProfit, prices[i] - mini);
            }
        }
        return maxProfit;
    }
};