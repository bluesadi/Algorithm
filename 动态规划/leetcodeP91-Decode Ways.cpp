#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std; 

class Solution {
public:
    int numDecodings(string str) {
    	int len = str.length();
        int dp[len] = {0};//该数组可换成两个int,使空间复杂度变为O(1) 
        dp[0] = str[0] != '0';
        if(len > 1 && dp[0] != 0){
        	int num = (str[0] - '0') * 10 + str[1] - '0';
	        dp[1] = (str[1] != '0') + (num <= 26 && num >= 10);  
	        for(int i = 2;i < len;i ++){
	        	int num = (str[i - 1] - '0') * 10 + str[i] - '0';
	        	if(num <= 26 && num >= 10){
					if(str[i] == '0'){
						dp[i] = dp[i - 2];
					}else{
						dp[i] = dp[i - 1] + dp[i - 2];
					}
				}else{
					if(str[i] != '0'){
						dp[i] = dp[i - 1]; 
					}
				}
			}
		}
		return dp[len - 1];
    }
};

int main(){
	cout << Solution().numDecodings("230");
}
