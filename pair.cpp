#include<iostream>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#define maxn 1000
using namespace std;



int main()
{

pair<string, int>p;
   // 幫某個類別取名字
    typedef vector< pair<string, int> > VP;
    VP vp;
    while(cin>>p.first>>p.second)
    {
        vp.push_back(make_pair(p.first,p.second));
        
    }
    VP::iterator it;
    for(it=vp.begin(); it!=vp.end(); it++)
        cout<<it->first<<","<<it->second<<endl;

    return 0;
}