//
// Created by kevin on 2023/6/10.
//

#ifndef LEETCODEGITHUB_SOLUTION1170_HPP
#define LEETCODEGITHUB_SOLUTION1170_HPP
#include <vector>
#include <map>
#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> res;
        map<char,int> mp;
        int cnts[words.size()];memset(cnts,0,sizeof(cnts));
        int i=0;
        for(auto str:words){
            mp.clear();
            for(auto ch:str){
                if(mp.count(ch)==0){
                    mp[ch]=1;
                }else{
                    mp[ch]++;
                }
            }
            cnts[i++]=mp.begin()->second;
        }
        for(auto que:queries){
            mp.clear();
            for(auto ch:que){
                if(mp.count(ch)==0){
                    mp[ch]=1;
                }else{
                    mp[ch]++;
                }
            }
            int elem=mp.begin()->second;
            int record=0;
            for(int j=0;j<words.size();j++){
                if(elem<cnts[j]){
                    record++;
                }
            }
            res.push_back(record);
        }

        return res;
    }
};

#endif //LEETCODEGITHUB_SOLUTION1170_H
