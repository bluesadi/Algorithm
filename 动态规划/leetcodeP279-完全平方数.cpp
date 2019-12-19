#include <iostream>
#include <algorithm>
#include <cstring>

class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        for(int i = 0;i <= n;i ++) dp[i] = (int)1e5; 
        dp[0] = 0;
        dp[1] = 1;
		for(int i = 2;i <= n;i ++){
			for(int j = 1;j * j <= i;j ++){
				dp[i] = std::min(dp[i - j * j] + 1,dp[i]);
			}
		} 
		return dp[n];
    }
};

int main(){
	for(int n = 1;n <= 13;n ++){
		std::cout << n << ":" << Solution().numSquares(n) << std::endl;
	}
}
