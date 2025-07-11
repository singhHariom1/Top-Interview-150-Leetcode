#include <bits/stdc++.h>
using namespace std;

// 🟠 Approach 1: Brute Force using nested loop + map simulation
// Time Complexity: O(n^2)  — For each char in s, scan t to verify uniqueness
// Space Complexity: O(1)

class BruteForceSolution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i + 1; j < s.length(); ++j) {
                if ((s[i] == s[j] && t[i] != t[j]) || 
                    (s[i] != s[j] && t[i] == t[j]))
                    return false;
            }
        }
        return true;
    }
};

// 🟢 Approach 2: Optimal Mapping using 2 Hashmaps
// Time Complexity: O(n)
// Space Complexity: O(1) — Only 256 ASCII characters

class OptimalSolution {
    public:
        bool isIsomorphic(string s, string t) {
            if (s.length() != t.length())
                return false;
            unordered_map<char, char> mapST, mapTS;
            for (int i = 0; i < s.length(); i++) {
                char chS = s[i];
                char chT = t[i];
    
                if (mapST.count(chS)) {
                    if (mapST[chS] != chT)
                        return false;
                } else {
                    mapST[chS] = chT;
                }

                if(mapTS.count(chT)){
                    if(mapTS[chT]!=chS)
                        return false;
                }else{
                    mapTS[chT]=chS;
                }
            }
            return true;
        }
};    