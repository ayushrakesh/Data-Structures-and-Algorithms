class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        char res='z'+1;
        int low=0,high=n-1;

        while(low<=high){
            int mid = low+(high-low)/2;
            if(letters[mid] > target){
                res=letters[mid];
                high=mid-1;
            }
            // else if(letters[mid] > target)high=mid-1;
            else low=mid+1;
        }
        return res=='z'+1 ? letters[0] : res;
    }
};