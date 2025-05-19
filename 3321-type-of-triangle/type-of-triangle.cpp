class Solution {
public:
    string triangleType(vector<int>& nums) {
        int n = nums.size();

        if (nums[0] + nums[1] > nums[2] && nums[1] + nums[2] > nums[0] &&
            nums[0] + nums[2] > nums[1]) {
            if (nums[0] == nums[1] && nums[1] == nums[2] && nums[0] == nums[2])
                return "equilateral";
            if (nums[0] != nums[1] && nums[1] != nums[2] && nums[0] != nums[2])
                return "scalene";
            if ((nums[0] == nums[1] && nums[0] != nums[2]) ||
                (nums[1] == nums[2] && nums[0] != nums[2]) ||
                (nums[0] == nums[2] && nums[0] != nums[1]))
                return "isosceles";
        }
        return "none";
    }
};