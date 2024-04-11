#include <vector>
#include <string>
#include <map>
#include <utility>
#include <stdlib.h>
using namespace std;

bool is_palindrome(string& s, int i, int j, map<pair<int, int>, bool>& memo) {
    pair<int, int> key{i, j};
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    if (i >= j) { // A string of length 0 or 1 is a palindrome
        memo[key] = true;
        return true;
    }
    if (s[i] != s[j]) {
        memo[key] = false;
        return false;
    }
    // Recursively check the inner substring
    memo[key] = is_palindrome(s, i + 1, j - 1, memo);
    return memo[key];
}

int minCut(string s) {
    map<pair<int, int>, bool> is_pal;
    vector<int> dp(s.size(), s.size()); // Initialize with s.size() for the maximum cuts
    dp[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        if (is_palindrome(s, 0, i, is_pal)) {
            dp[i] = 0;
            continue;
        }
        
        for (int j = 0; j < i; j++) {
            if (is_palindrome(s, j + 1, i, is_pal)) {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp.back();
}
int main() {
    minCut("sssssssss");
    return 0;
}