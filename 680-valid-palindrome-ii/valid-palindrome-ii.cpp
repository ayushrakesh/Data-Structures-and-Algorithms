class Solution {
public:
    bool solve(int &l,int &r,string &s){
        while(l<r){
            if(s[l] != s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int l=0,r=n-1;

        if(solve(l,r,s))return true;

        int newl=l+1;
        int newr=r;

        if(solve(newl,newr,s))return true;

        int nl=l;
        int nr=r-1;

        return solve(nl,nr,s);
    }
};