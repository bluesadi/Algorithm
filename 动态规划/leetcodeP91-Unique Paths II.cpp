#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std; 

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int h = obstacleGrid.size();
        int w = obstacleGrid[0].size();
        long long dp[h + 1][w + 1];
        memset(dp,0,sizeof dp);
        dp[h][w] = 1; 
        for(int i = h;i >= 1;i --){
			for(int j = w;j >= 1;j --){
				if(i + 1 <= h && j + 1 <= w){
					dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
				}else if(i + 1 <= h){
					dp[i][j] = dp[i + 1][j];
				}else if(j + 1 <= w){
					dp[i][j] = dp[i][j + 1];
				}
				if(obstacleGrid[i - 1][j - 1]){
					dp[i][j] = 0;
				}
			}
		}
		return dp[1][1];
    }
};

