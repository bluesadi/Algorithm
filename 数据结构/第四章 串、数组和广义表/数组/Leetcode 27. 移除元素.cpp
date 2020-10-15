class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ptr = 0,len = 0;
        for(int num : nums){
            if(num != val) nums[ptr++] = num,len++; 
        }
        return len;
    }
};