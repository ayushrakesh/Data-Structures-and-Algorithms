class Solution {
public:
    int solve(int i,int j,string s,string t){
        int n=s.size(),m=t.size();

        if(j>=m)return 1;
        if(i>=n)return 0;

        if(s[i]==t[j])return solve(i+1,j+1,s,t)+solve(i+1,j,s,t);
        return solve(i+1,j,s,t);
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        return solve(0,0,s,t);
    }
};