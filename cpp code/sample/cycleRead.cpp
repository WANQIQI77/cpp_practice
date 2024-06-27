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
using namespace std; 

int main() {
    int a, b;
    //c
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", a+b);
    }
    //c++
    while (cin >> a >> b) {  
        cout << a + b << endl;  
    }  
    return 0;
}