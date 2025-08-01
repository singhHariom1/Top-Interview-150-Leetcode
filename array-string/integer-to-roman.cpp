#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach: Greedy + Lookup Table
// Time Complexity: O(1) [Max input is 3999, so constant time]
// Space Complexity: O(1) [Result string max length is 15]

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> roman = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        string result;

        for (const auto& it : roman) {
            while (num >= it.first) {
                result += it.second;
                num -= it.first;
            }
        }
        return result;
    }
};