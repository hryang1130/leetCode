//
// Created by kevin on 2023/6/9.
//

#ifndef LEETCODEGITHUB_SOLUTION1240_HPP
#define LEETCODEGITHUB_SOLUTION1240_HPP

//https://leetcode.cn/problems/tiling-a-rectangle-with-the-fewest-squares/solution/

#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int tilingRectangle(int n, int m) {
        int res = m*n;
        vector<vector<int>> visited(n,vector<int>(m,0));
        function<void(int,int,int)> dfs = [&](int i ,int j,int cnt)
        {
            //当前行满了，去下一行构建正方形
            if(j == m)
            {
                ++i;
                j = 0;
            }
            //如果i = n表示全部填满了，更新答案
            if(i == n)
            {
                res = cnt;
                return;
            }
            //如果当前区域已经被构建成了正方形，则去(i,j+1)构建
            if(visited[i][j] == 1)
            {
                dfs(i,j+1,cnt);
            }
                //剪枝，只有当前cnt比ans小时才继续进行递归
            else if(cnt + 1 < res)
            {
                //寻找可以构成的最大正方形的边长
                int r = 0,c = 0;
                while(i + r < n)
                {
                    if(visited[i + r][j] == 1)
                        break;
                    r++;
                }
                while(j + c < m)
                {
                    if(visited[i][j+c] == 1)
                        break;
                    c++;
                }
                int w = min(r,c);
                //将构建的正方形区域都标记为已经访问过并进行递归
                for(int k = 1;k <= w;++k)
                {
                    for(int l = 0;l<k;++l)
                    {
                        visited[i+k-1][j+l] = 1;
                        visited[i+l][j+k-1] = 1;
                    }
                    dfs(i,j+k,cnt+1);
                }
                //回溯
                for(int x = i;x < i + w;++x)
                {
                    for(int y = j;y < j + w;++y)
                    {
                        visited[x][y] = 0;
                    }
                }
            }
        };
        dfs(0,0,0);
        return res;
    }
};

#endif //LEETCODEGITHUB_SOLUTION1240_H
