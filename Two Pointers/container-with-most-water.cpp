#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach: Brute Force
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int Area = 0;
        for (int i = 0; i < height.size() - 1; i++) {
            for (int j = i + 1; j < height.size(); j++) {
                Area = max(Area, (j - i) * min(height[i], height[j]));
            }
        }
        return Area;
    }
};

// 🟢 Approach: Two Pointers (Optimal)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, area = 0;
        while (i < j) {
            area = max(area, (j - i) * min(height[i], height[j]));
            (height[i] < height[j]) ? i++ : j--;
        }
        return area;
    }
};