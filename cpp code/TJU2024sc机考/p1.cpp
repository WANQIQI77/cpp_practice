/*СZ�ڴ����ά������ϵ����ݣ��ܵ��������ƣ���ϣ�������еĵ��Ӧ������������������㣨���������Ϊ�������ϣ������������������
���һ�����ж������������ĵ㣬ȡ���������С���Ǹ��㡣
��*/
// #include <bits/stdc++.h>
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
using namespace std; 
const int N = 0x3f3f3f;;
struct Point {
    float x, y;
} p[N];

bool cmp(Point p) {
    int x=0, y=0;
    int a=0;
    x=int(p.x); y=int(p.y);
    if(p.x>0){
        a=int((p.x*10))%10;
        if(a>5) x=x+1;
    }
    if(p.y>0){
        a=int((p.y*10))%10;
        if(a>5) y=y+1;
    }
    if(p.x<0){
        a=-int((p.x*10))%10;
        if(a>=5) x=x-1;
    }
     if(p.y<0){
        a=-int((p.y*10))%10;
        if(a>=5) y=y-1;
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}

int main(){
    int n;
    cin >> n;
    Point p;
    for(int i = 0; i < n; i++){
        cin>>p.x >> p.y;
        cmp(p);
    }

    return 0;
}