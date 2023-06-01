//
// Created by kevin on 2023/6/1.
//

#ifndef LEETCODEGITEE_SOLUTION2517_HPP
#define LEETCODEGITEE_SOLUTION2517_HPP
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int l = 0,r=price.back()-price[0];
        auto check = [&](int target) -> bool {
            int cnt=1;
            int tmp=price[0];
            for(int j=1;j<price.size();j++){
                if(price[j]-tmp>=target){
                    cnt++;
                    tmp=price[j];
                }
            }
            return cnt>=k;
        };

        while(l<r){
            int mid=(l+r+1)/2;
            if(check(mid)){
                l=mid;
            }else{
                r=mid-1;
            }
        }

        return l;
    }
};

#endif //LEETCODEGITEE_SOLUTION2517_HPP
