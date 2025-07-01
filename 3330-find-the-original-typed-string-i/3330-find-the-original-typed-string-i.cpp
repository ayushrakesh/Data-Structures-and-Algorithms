class Solution {
public:
    int possibleStringCount(string word) {
        int res=1;
        int n=word.size();
        unordered_map<char,int>mp;
        for(int i=1;i<n;i++){
            if(word[i]==word[i-1]){
                res++;
            }
        }
        // for(auto it:mp){
        //     res+=(it.second-1);
        // }
        return res;
    }
};