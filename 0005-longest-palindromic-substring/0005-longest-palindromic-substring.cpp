class Solution {
public:
    string brute(string s) {
        int n = s.size();
        string res = "";

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            int low = i, high = i;
            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
            }
            low++;
            high--;
            if (high - low + 1 > (int)res.size()) {
                res = s.substr(low, high - low + 1);
            }

            // Even length palindrome
            low = i, high = i + 1;
            while (low >= 0 && high < n && s[low] == s[high]) {
                low--;
                high++;
            }
            low++;
            high--;
            if (high - low + 1 > (int)res.size()) {
                res = s.substr(low, high - low + 1);
            }
        }
        return res;
    }

    string longestPalindrome(string s) {
        return brute(s);
    }
};
