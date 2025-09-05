class Solution {
public:
    int optimal(vector<int>&height){
        int n=height.size();
        int res=0;
        int i=0,j=n-1;
        while(i<j){
            int water=(j-i)*min(height[i],height[j]);
            res=max(res,water);

            if(height[i] <= height[j])i++;
            else j--;
        }
        return res;
    }
    int maxArea(vector<int>& height) {
        return optimal(height);
    }
};