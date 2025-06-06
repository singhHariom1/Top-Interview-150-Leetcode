#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Brute Force
// Check every possible h from n down to 0 by counting papers with citations >= h
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Simple but inefficient for large inputs

class Solution_BruteForce {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        for (int h = n; h >= 0; h--) {
            int count = 0;
            for (int c : citations) {
                if (c >= h) count++;
            }
            if (count >= h) return h;
        }
        return 0;
    }
};


// 🟠 Approach 2: Sorting + Greedy
// Sort citations and find max h such that citations[i] >= n - i
// Time Complexity: O(n log n) due to sorting
// Space Complexity: O(1) or O(n) depending on sort implementation

class Solution_Sorting {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        for (int i = 0; i < n; i++) {
            int h = n - i;
            if (citations[i] >= h) return h;
        }
        return 0;
    }
};


// 🟢 Approach 3: Counting / Bucket Sort (Optimal)
// Use buckets to count papers by citation number and calculate h-index in O(n)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution_Counting {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> buckets(n + 1, 0);

        for (int c : citations) {
            if (c >= n) buckets[n]++;
            else buckets[c]++;
        }

        int count = 0;
        for (int i = n; i >= 0; i--) {
            count += buckets[i];
            if (count >= i) return i;
        }
        return 0;
    }
};