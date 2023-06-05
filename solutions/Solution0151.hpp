//
// Created by kevin on 2023/6/5.
//

#ifndef LEETCODEGITEE_SOLUTION151_HPP
#define LEETCODEGITEE_SOLUTION151_HPP

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string tmp="";
        stack<string> words;
        for(auto ch:s){
            if(ch==' '){
                if(tmp.size()>0){
                    words.push(tmp);
                }
                tmp.clear();
            }else{
                tmp+=ch;
            }
        }
        if(tmp.size()>0){
            words.push(tmp);
        }
        tmp="";
        while(!words.empty()){
            tmp+=words.top();
            if(words.size()>1){
                tmp+=' ';
            }
            words.pop();
        }

        return tmp;

    }
};

#endif //LEETCODEGITEE_SOLUTION151_H
