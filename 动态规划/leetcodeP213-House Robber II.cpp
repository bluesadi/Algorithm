#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {//其实没有这么麻烦，只是HouseRobber I分三种情况 
        int len = nums.size();
		if(len > 1){
			int dp[len][len];
			for(int begin = 0;begin < len;begin ++){
				for(int end = begin;end < len;end ++){
					if(end == begin){
						dp[begin][begin] = nums[begin];
					}else if(end - begin == 1){
						dp[begin][end] = max(nums[begin],nums[end]);
					}else{
						dp[begin][end] = max(dp[begin][end - 2] + nums[end],dp[begin][end - 1]);
					}
				}
			}
			return max(dp[1][len - 1],dp[0][len - 2]);
		}else if(len == 1){
			return nums[0];
		} 
		return 0;
    }
};

