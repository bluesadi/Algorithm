class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> M;
        for(int i = 0;i < nums.size();i++){
            int x = nums[i];
            auto it = M.find(target - x);
            if(it != M.end()) return {it->second,i};
            M[x] = i;
        }
        return {};
    }
};