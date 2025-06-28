class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string si;
        string ti;
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] != '#') si.push_back(s[i]);
            else if(si.length() > 0) si.pop_back();
        //    else si.pop_back();
        }
        for(int i = 0 ; i < t.length() ; i++){
            if(t[i] != '#') ti.push_back(t[i]);
            else if(ti.length() > 0) ti.pop_back();
            //else i++;
        }
        return ( si == ti);
    }
};