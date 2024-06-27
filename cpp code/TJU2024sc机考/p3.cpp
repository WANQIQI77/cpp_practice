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
using namespace std; 
bool isK(int a,int k){
    int sum=0;
    while(a>0){
        sum=a%10;
        a/=10;
        // cout<<sum<<endl;
        if(sum==k) return true;
    }
    return false;
}
int main(){
    int T;
    int n,k;
    int num;
    cin >> T;
    // cout <<"T:"<<T;
    while (T--) {
        cin >> n >> k;
        num = n;
        for(int i=1;i<=n;i++) {
            for(int j=k;j<=9;j++){
                if(isK(i,j)){num--;break;}
            } 
        }
        cout<<num<<endl;
    }
        
    return 0;
}