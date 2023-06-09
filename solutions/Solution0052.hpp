//
// Created by kevin on 2023/6/9.
//

#ifndef LEETCODEGITHUB_SOLUTION0052_H
#define LEETCODEGITHUB_SOLUTION0052_H

#include <functional>
#include <cstring>
using namespace std;


class Solution {
public:
    int res = 0;
    char table[9][9];
    int totalNQueens(int n) {
        memset(table,'.',sizeof(table));
        function<void(int)> dfs = [&](int i) -> void {
            if(i==n){
                res++;
                return;
            }
            for(int j=0;j<n;j++){
                if(!posAble(i,j,n)){
                    continue;
                }
                table[i][j]='Q';
                dfs(i+1);
                table[i][j]='.';
            }
        };
        dfs(0);
        return res;
    }

    bool posAble(int i,int j,int n){
        for(int h=0;h<i;h++){
            if(table[h][j]=='Q'){
                return false;
            }
        }

        for(int k=0;k<n;k++){
            if(table[i][k]=='Q'){
                return false;
            }
        }
        for(int h=i,k=j;h>=0&&k>=0;h--,k--){
            if(table[h][k]=='Q'){
                return false;
            }
        }

        for(int h=i,k=j;h>=0&&k<n;h--,k++){
            if(table[h][k]=='Q'){
                return false;
            }
        }
        return true;
    }
};

#endif //LEETCODEGITHUB_SOLUTION0052_H
