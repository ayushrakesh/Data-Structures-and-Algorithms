class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        string t = strs[0];
        int len = t.size();

        for (int i = 0; i < len; i++) {
            t = t.substr(0, len - i);
            bool b=false;
            for (int j = 1; j < n; j++) {
                if (strs[j].find(t) == string::npos) {
                    b = true;
                    break;
                }
            }
            if (!b) {
                return t;
            }
        }

        return "";
    }
};