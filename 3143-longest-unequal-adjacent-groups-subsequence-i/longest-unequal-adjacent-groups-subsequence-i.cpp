class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words,
                                         vector<int>& groups) {
        int n = groups.size();
        if(n==1)return words;
        vector<string> res;

        set<int> v;
        int prevind=0;

        for (int i = 1; i < n;) {
            if (groups[i] != groups[prevind]) {
                v.insert(prevind);
                v.insert(i);
                prevind=i;
                i++;
            }
            else{
                i++;
            }
        }

        if(v.empty()){
            res.push_back(words[0]);
            return res;
        }
        for (auto it : v) {
            res.push_back(words[it]);
        }
        return res;
    }
};