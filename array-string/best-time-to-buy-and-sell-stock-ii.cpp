#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Track Local Minima and Sell When Profitable
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i]; // New low → better buy point
            } else {
                profit += prices[i] - buy; // Take profit
                buy = prices[i]; // Reset buy to current for next possible trade
            }
        }
        return profit;
    }
};

// 🟢 Approach 2: Optimal Greedy (Cleanest)
// Logic: If price[i] > price[i-1], take the profit (prices[i] - prices[i-1])
// You’re effectively buying yesterday and selling today.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};