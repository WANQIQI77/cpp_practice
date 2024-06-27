#include<iostream>  
using namespace std;  
  
int step;//ÒÆ¶¯²½Êý  
void Hanoi(int n, char a, char b, char c) {  
    if(n == 1) {  
        if((step+1) % 5 == 0)  
            cout << a << "-->" << c << endl;  
        else cout << a << "-->" << c << "   ";  
        step++;  
        return;  
    }  
    Hanoi(n-1, a, c, b);  
    Hanoi(1, a, b, c);  
    Hanoi(n-1, b, a, c);  
}  
int main() {  
     int n;  
     while(cin>>n)  
     {  
          if(n == 0) break;  
          step = 0;  
          Hanoi(n, 'A', 'B', 'C'); cout << endl;  
     }  
     return 0;  
}  