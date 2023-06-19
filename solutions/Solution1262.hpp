//
// Created by kevin on 2023/6/19.
//

#ifndef LEETCODEGITHUB_SOLUTION1262_HPP
#define LEETCODEGITHUB_SOLUTION1262_HPP

#include <vector>
using namespace std;
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        const int inf = 1 << 30;
        vector<int> f={0,-inf,-inf};
        for(int i=0;i<n;i++){
            vector<int> g = f;
            for(int j=0;j<3;j++){
                g[j]=max(f[j],f[(j-nums[i]%3+3)%3]+nums[i]);
            }
            f=move(g);
        }

        return f[0];

    }
};

#endif //LEETCODEGITHUB_SOLUTION1262_H
