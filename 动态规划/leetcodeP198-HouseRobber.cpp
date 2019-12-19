#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
		if(len > 0){
			int dp[len];
			dp[0] = nums[0];
			if(len > 1){
				dp[1] = max(nums[0],nums[1]);
				for(int i = 2;i < len;i ++){
					dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);
				}
			}
			return dp[len - 1];
		}
		return 0;
    }
};

