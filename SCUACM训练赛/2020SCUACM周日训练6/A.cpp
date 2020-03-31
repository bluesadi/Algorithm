#define LOCAL
#include <iostream>
#define debug(x) cout << "debug:" << x << endl
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n,grid[105][105],k,Q;

int main(){
#ifdef LOCAL
    freopen("D:/Algorithm/test.in","r",stdin);
#endif
    int score = 0;
    memset(grid,0,sizeof grid);
    scanf("%d%d",&n,&k);
    while(k--){
        int a,x,y;
        scanf("%d%d%d",&a,&x,&y);
        grid[x][y] = a;
    }
    scanf("%d",&Q);
    while(Q--){
        char tmp[5];
        char op;
        int b,r,c;
        scanf("%s%d%d%d",&tmp,&b,&r,&c);
        op = tmp[0];
        if(op == 'D'){
            for(int i = 1;i <= n;i ++){
                int top = n + 1;
                for(int j = n;j >= 1;j --){
                    if(grid[j][i]){
                        if(top == n + 1){
                            grid[n][i] = grid[j][i];
                            if(j != n) grid[j][i] = 0;
                            top = n;
                        }else{
                            if(grid[top][i]){
                                if(grid[j][i] == grid[top][i]){
                                    score += 2 * grid[j][i];
                                    grid[top--][i] *= 2;
                                    grid[j][i] = 0;
                                }else{
                                    grid[--top][i] = grid[j][i];
                                    if(j != top) grid[j][i] = 0;
                                }
                            }else grid[top][i] = grid[j][i],grid[j][i] = 0;
                        }
                    }
                }
            }
        }else if(op == 'U'){
            for(int i = 1;i <= n;i ++){
                int bot = 0;
                for(int j = 1;j <= n;j ++){
                    if(grid[j][i]){
                        if(bot == 0){
                            grid[1][i] = grid[j][i];
                            if(j != 1) grid[j][i] = 0;
                            bot = 1;
                        }else{
                            if(grid[bot][i]){
                                if(grid[j][i] == grid[bot][i]){
                                    score += 2 * grid[j][i];
                                    grid[bot++][i] *= 2;
                                    grid[j][i] = 0;
                                }else{
                                    grid[++bot][i] = grid[j][i];
                                    if(j != bot) grid[j][i] = 0;
                                }
                            }else grid[bot][i] = grid[j][i],grid[j][i] = 0;
                        }
                    }
                }
            }
        }else if(op == 'L'){
            for(int i = 1;i <= n;i ++){
                int left = 0;
                for(int j = 1;j <= n;j ++){
                    if(grid[i][j]){
                        if(left == 0){
                            grid[i][1] = grid[i][j];
                            if(j != 1) grid[i][j] = 0;
                            left = 1;
                        }else{
                            if(grid[i][left]){
                                if(grid[i][j] == grid[i][left]){
                                    score += 2 * grid[i][j];
                                    grid[i][left++] *= 2;
                                    grid[i][j] = 0;
                                }else{
                                    grid[i][++left] = grid[i][j];
                                    if(j != left) grid[i][j] = 0;
                                }
                            }else grid[i][left] = grid[i][j],grid[i][j] = 0;
                        }
                    }
                }
            }
        }else if(op == 'R'){
            for(int i = 1;i <= n;i ++){
                int right = n + 1;
                for(int j = n;j >= 1;j --){
                    if(grid[i][j]){
                        if(right == n + 1){
                            grid[i][n] = grid[i][j];
                            if(j != n) grid[i][j] = 0;
                            right = n;
                        }else{
                            if(grid[i][right]){
                                if(grid[i][j] == grid[i][right]){
                                    score += 2 * grid[i][j];
                                    grid[i][right--] *= 2;
                                    grid[i][j] = 0;
                                }else{
                                    grid[i][--right] = grid[i][j];
                                    if(j != right) grid[i][j] = 0;
                                }
                            }else grid[i][right] = grid[i][j],grid[i][j] = 0;
                        }
                    }
                }
            }
        }
        grid[r][c] = b;
    }
    printf("%d\n",score);
}