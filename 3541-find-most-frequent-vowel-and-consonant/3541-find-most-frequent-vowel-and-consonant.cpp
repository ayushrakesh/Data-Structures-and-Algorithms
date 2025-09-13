class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> v(26,0);

        for(int i=0;i<s.size();i++){
             v[s[i]-'a']++;       
        }
        int m=0,n=0;
        for(int i=0;i<v.size();i++){
            if(i==0 || i==4 || i==8 || i==14 || i==20)
            {
                m=max(m,v[i]);
            }
            else{
                n=max(n,v[i]);
            }
        }
        return m+n;
    }
};