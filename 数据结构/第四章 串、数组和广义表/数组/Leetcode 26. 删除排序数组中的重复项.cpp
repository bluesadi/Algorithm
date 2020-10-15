class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ptr = 0,len = nums.size();
        for(int i = 1;i < nums.size();i++){
            if(nums[ptr] != nums[i]) nums[++ptr] = nums[i];
            else len--;
        }
        return len;
    }
};