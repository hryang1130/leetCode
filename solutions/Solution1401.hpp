//
// Created by kevin on 2023/6/26.
//

#ifndef LEETCODEGITHUB_SOLUTION1401_HPP
#define LEETCODEGITHUB_SOLUTION1401_HPP

//https://leetcode.cn/problems/circle-and-rectangle-overlapping/

#include <algorithm>
using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        auto f = [](int i,int j,int k)-> int {
            if(j>=i && j<=k){
                return 0;
            }else{
                return min(abs(i-j),abs(j-k));
            }
        };
        int x = f(x1,xCenter,x2);
        int y = f(y1,yCenter,y2);

        return x*x+y*y <= radius*radius;

    }
};

#endif //LEETCODEGITHUB_SOLUTION1401_H
