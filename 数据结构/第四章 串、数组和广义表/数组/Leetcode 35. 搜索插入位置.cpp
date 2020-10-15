class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty() || target <= nums[0]) return 0;
        for(int i = 1;i < nums.size();i++){
            if(target > nums[i - 1] && target <= nums[i]) return i;
        }
        return nums.size();
    }
};