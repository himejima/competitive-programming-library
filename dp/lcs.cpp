//
// LCS (Longest Common Subsequnce) 
//
// verified
// [Is Subsequence - LeetCode](https://leetcode.com/problems/is-subsequence/)
// 
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

class Solution {
public:
    int dp[110][10100];

    bool isSubsequence(string s, string t) {
       for (int i = 0; i < s.size(); i++) {
           for (int j = 0; j < t.size(); j++) {
               if (s[i] == t[j]) {
                   dp[i + 1][j + 1] = dp[i][j] + 1;
               } else {
                   dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
               }
           }
       }

       bool ans = false;
       if (dp[s.size()][t.size()] >= s.size()) {
           ans = true;
       }

       return ans; 
    }
};

/*
abc
ahbgdc

axc
ahbgdc
*/
string a, b;
int main() {
    cin >> a >> b;
    cout << Solution().isSubsequence(a, b) << endl;
}