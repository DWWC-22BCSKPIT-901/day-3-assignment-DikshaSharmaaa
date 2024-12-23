#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to implement wildcard matching
bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Base case: Empty string matches with empty pattern
    dp[0][0] = true;

    // Handle patterns with '*'
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match or '?' matches any single character
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1]; // '*' matches zero or more characters
            }
        }
    }

    return dp[m][n];
}

// Main function to test the wildcard matching
int main() {
    // Example 1
    string s1 = "aa", p1 = "a";
    cout << "Input: s = \"" << s1 << "\", p = \"" << p1 << "\"" << endl;
    cout << "Output: " << (isMatch(s1, p1) ? "true" : "false") << endl;

    // Example 2
    string s2 = "aa", p2 = "*";
    cout << "Input: s = \"" << s2 << "\", p = \"" << p2 << "\"" << endl;
    cout << "Output: " << (isMatch(s2, p2) ? "true" : "false") << endl;

    // Example 3
    string s3 = "cb", p3 = "?a";
    cout << "Input: s = \"" << s3 << "\", p = \"" << p3 << "\"" << endl;
    cout << "Output: " << (isMatch(s3, p3) ? "true" : "false") << endl;

    return 0;
}
