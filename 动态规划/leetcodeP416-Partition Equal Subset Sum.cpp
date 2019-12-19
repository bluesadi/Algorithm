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
				for(int j = sum;j >= nums[i];j --){//��״̬ת�Ʒ��̿�֪����������ǴӴ�С��������ܵ����ظ���ĳһ��Ʒ 
					dp[j] = dp[j] || dp[j - nums[i]] || j == nums[i];
				}
			}	
			return dp[sum];
		}
    }
};
