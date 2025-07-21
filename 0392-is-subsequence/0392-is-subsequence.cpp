class Solution {
public:
    bool brute(string s, string t) {
        int ind=0;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            bool b = false;
            for (int j = ind ; j < t.size(); j++) {
                if (t[j] == c) {
                    ind = j+1;
                    b = true;
                    break;
                }
            }
            if (!b)
                return false;
        }
        return true;
    }
    bool optimal(string s,string t){
        int sp = 0;
        int tp = 0;

        while (sp < s.length() && tp < t.length()) {
            if (s[sp] == t[tp]) {
                sp++;
            }
            tp++;
        }
        return sp == s.length();
    }
    bool isSubsequence(string s, string t) {
        // return optimal(s,t);
        return brute(s,t);
    }
};