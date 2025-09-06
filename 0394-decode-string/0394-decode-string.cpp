class Solution {
public:
    string solve(int& i, string s) {
        int n = s.size();
        string res = "";
        
        while (i < n && s[i] != ']') {
            if (s[i] <= '9' && s[i] >= '0') {
                int num = 0;
                while (i < n && s[i] <= '9' && s[i] >= '0') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i++;
                string temp = solve(i, s);
                i++;
                while (num--) {
                    res.append(temp);
                }
            } else {
                res.push_back(s[i]);
                i++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int n = s.size();
        int i=0;
        return solve(i, s);
    }
};