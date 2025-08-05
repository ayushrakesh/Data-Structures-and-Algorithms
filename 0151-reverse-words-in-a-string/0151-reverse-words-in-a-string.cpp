class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int n=s.size()-1;
        while(s[n]==' ')
        {
            n--;
        }
        int k=0;
        while(s[k]==' ')
        {
            k++;
        }
            string w;
        for(int i=n;i>=k;i--)
        {
            if(s[i]!=' ')
            {
                //cout<<s[i]<<" ";
                w.push_back(s[i]);
            }
            else if(s[i]==' ' && s[i-1]!=' ')
            {
                reverse(w.begin(),w.end());
                ans+=w+" ";
                w.erase();
            }
        }
         reverse(w.begin(),w.end());
         ans+=w;
        return ans;
    }
};