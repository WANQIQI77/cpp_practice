#include <cstring>
#include <stdio.h>  
#include <string.h>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
#include <algorithm>  
#include <iostream>  
#include <queue>  
#include <stack>  
#include <vector>  
#include <string>  
#include <climits>
#include <iomanip>
#include <bitset>
using namespace std; 

int find_mask(int s, int t, int m,const vector<int>& mem){
    int num=0;
    num = t-s+1;
    string m_str = bitset<32>(m).to_string();
    // cout<<m_str<<endl;
    for(int i=s;i<=t;i++){
        string i_str = bitset<32>(mem[i-1]).to_string();
        // cout<<i_str<<endl;
        //判断i中的1能否匹配s和t中的1
        for(int i=0; i<m_str.length(); i++){
            if(m_str[i]=='1'){
                if(i_str[i]=='0'){
                    num--;
                    break;
                }
            }
        }
    }
    return num;
}

int main(){
    int n;int q=0;
    int s,t,m;
    vector<int> mem;
    cin>>n;
    for(int i=0; i<n; i++){
        int temp;
        cin>>temp;
        mem.push_back(temp);
    }
    cin>>q;
    for(int i=0; i<q; i++){
        int out;
        cin>>s>>t>>m;
        out = find_mask(s,t,m,mem);
        cout<<out<<endl;

    }

}