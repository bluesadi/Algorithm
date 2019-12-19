#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
/*╢нсе╫Б 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	if(amount == 0){
			return 0;
		}
        int dp[amount + 1];
        memset(dp,-1,sizeof dp);
        dp[0] = 0;
        int len = coins.size();
        for(int i = 0;i < len;i ++){
			for(int j = amount;j >= coins[i];j --){
				for(int k = 0;j - k * coins[i] >= 0;k ++){
					if(dp[j - k * coins[i]] != -1){
						if(dp[j] != -1){
							dp[j] = min(dp[j],dp[j - k * coins[i]] + k);
						}else{
							dp[j] = dp[j - k * coins[i]] + k;
						}
					}
				}
			}
		}
        return dp[amount];
    }
}; */

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    	if(amount == 0){
			return 0;
		}
        int dp[amount + 1];
        memset(dp,-1,sizeof dp);
        dp[0] = 0;
        int len = coins.size();
        for(int i = 0;i < len;i ++){
			for(int j = coins[i];j <= amount;j ++){
				if(j - coins[i] >= 0){
					if(dp[j - coins[i]] != -1){
						if(dp[j] != -1){
							dp[j] = min(dp[j],dp[j - coins[i]] + 1);
						}else{
							dp[j] = dp[j - coins[i]] + 1;
						}
					}
				}
			}
		}
        return dp[amount];
    }
};

int main(){
	vector<int> vec = {1,2,5};
	cout << Solution().coinChange(vec,11);
}
