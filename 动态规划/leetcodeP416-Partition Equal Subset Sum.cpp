#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0,len = nums.size();
        for(int a : nums) sum += a;
		if(sum & 1) return false;
		else{
			sum /= 2;
			int dp[sum + 1] = {0};
			for(int i = 0;i < len;i ++){
				for(int j = sum;j >= nums[i];j --){//有状态转移方程可知，这里必须是从大到小，否则可能导致重复放某一物品 
					dp[j] = dp[j] || dp[j - nums[i]] || j == nums[i];
				}
			}	
			return dp[sum];
		}
    }
};
