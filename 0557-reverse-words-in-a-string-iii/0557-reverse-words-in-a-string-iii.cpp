class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        while(i < n) {
            while(s[i] == ' ' && i < n) i++;
            int j = i;

            while(s[j] != ' ' && j < n) 
            j++;
        
            int l = i, r = j - 1;

            while(l < r) {
                swap(s[l],s[r]);
                l++;
                r--;
            }

            i = j;
            
        }
        return s;
    }
};