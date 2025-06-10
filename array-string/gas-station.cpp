#include <bits/stdc++.h>
using namespace std;

// 🔴 Brute Force Approach
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Try each starting station and simulate the journey
class Solution_BruteForce {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for (int start = 0; start < n; ++start) {
            int fuel = 0, count = 0, curr = start;

            while (count < n) {
                fuel += gas[curr];
                if (fuel < cost[curr])
                    break;

                fuel -= cost[curr];
                curr = (curr + 1) % n;
                count++;
            }

            if (count == n)
                return start;
        }
        return -1;
    }
};

// 🟢 Optimal Greedy Approach
// Time Complexity: O(n)
// Space Complexity: O(1)
// If total gas >= total cost, there's a solution starting after the last failure
class Solution_Optimal {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0, tank = 0;
        int startIndex = 0;

        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];

            if (tank < 0) {
                startIndex = i + 1;
                tank = 0;
            }
        }

        return (totalGas >= totalCost) ? startIndex : -1;
    }
};