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
/* dice =(2*iou) / (iou +1) 
写程序让两个公式相互转化 */

int main(){
    int T;
    cin>>T;
    while(T--){
        string name; 
        double key=0;
        double num=0;
        cin>>name>>key;
        // cout<<name.c_str()<<endl;
        if (!strcmp(name.c_str(),"iou")) {
            num = (2*key)/(key+1);
        }
        else if (!strcmp(name.c_str(), "dice")) {
            num = (key)/(2-key);
        }
        else num = 0;
        cout << fixed << setprecision(2) << num << endl;
    }
    return 0;
}