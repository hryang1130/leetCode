//
// Created by kevin on 2023/5/31.
//

#ifndef LEETCODEGITEE_SOLUTION1130_HPP
#define LEETCODEGITEE_SOLUTION1130_HPP
#include <iostream>
#include <cstring>
#include <vector>
#include <functional>
using namespace std;
class Solution {
//记忆化搜索版本
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        int g[n][n];
        int f[n][n];
        memset(f,0,sizeof(f));
        for(int i=n-1;i>=0;i--){
            g[i][i]=arr[i];
            for(int j=i+1;j<n;j++){
                g[i][j]=max(arr[j],g[i][j-1]);
            }
        }

        function<int(int,int)> dfs = [&](int i,int j)-> int {
            if(i==j){
                return 0;
            }
            if (f[i][j] > 0) {
                return f[i][j];
            }
            int ans = INT32_MAX;
            for (int k = i; k < j; ++k) {
                ans = min(ans, dfs(i, k) + dfs(k + 1, j) + g[i][k] * g[k + 1][j]);
            }
            return f[i][j] = ans;

        };
        return dfs(0,n-1);

    }
};

#endif //LEETCODEGITEE_SOLUTION1130_HPP
