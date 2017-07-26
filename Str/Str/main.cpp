//
//  main.cpp
//  Str
//
//  Created by 王肖 on 2017/7/11.
//  Copyright © 2017年 王肖. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


//获取next数组
vector<int> GetNext(string s, int num)
{
    vector<int> next(num);
    int k=-1;//前缀
    int j=0;//后缀
    next[0] =-1;
    int n = s.length();
    while(j<n)//后缀扫描一边结束
    {
        //第一次循环，k的初始值为-1，直接进入if语句，k和j加1使得k=0，j=1，从第二位开始比较
        if (k==-1||s[k]==s[j])
        {
            k++;
            j++;
            //如果相等，就将next[k]赋值给next[j]，避免重复
            if (s[j]==s[k])
            {
                next[j]=next[k];
                //next.push_back(next[k]);
            }
            //不相等则next[j]为l=k
            else
            {
                next[j]=k;
                //next.push_back(k);
            }
        }
        //如果k！=-1并且s[k]与s[j]不相等，将k赋值为next[k]
        else
        {
            k = next[k];
        }
    }
    return next;
}

//s为要被匹配的文本，p为匹配文本
int kmpSearch(string s, string p)
{
    int i=0;
    int j=0;
    int plength = p.length();
    int slength = s.length();
    vector<int> next = GetNext(p, plength);
    while(i<slength && j<plength)
    {
        if (s[i]==p[j]||j==-1)
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }
    if (j==plength)
    {
        return i-j;
    }
    else
    {
        return -1;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<kmpSearch("abcdqcdwe", "cdqcd");
    cout << "Hello, World123!\n";
    return 0;
}
