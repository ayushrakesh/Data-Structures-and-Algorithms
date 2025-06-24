// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int start=0;
//         int end=s.size()-1;
//         while(start<end){
//             swap(s[start++],s[end--]);
//         }

//     }
// };

class Solution{
    public:
    void reverseString (vector<char>& s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            
        }



        for (int i = 0; i < s.size(); i++) {
            s[i] = st.top();
            st.pop();
        }


    }
};