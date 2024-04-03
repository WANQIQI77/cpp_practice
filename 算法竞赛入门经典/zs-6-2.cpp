#include<bits/stdc++.h>
#include<stack>
using namespace std;
const int MAXN = 1000+10;
int n,target[MAXN];//n节车厢 
int main(){
	while(scanf("%d",&n)==1){
		stack<int> s;
		int A=1,B=1;//当前待进栈的车厢编号和待出栈的车厢编号，初始值均为 1
		for(int i=0;i<=n;i++) scanf("%d", &target[i]);//出栈顺序 
		int ok =1;
		while(B<=n){
			if(A==target[B]){ //当前待进栈的车厢编号和待出栈的车厢编号，初始值均为 1
				A++;
				B++;
			}
			else if(!s.empty()&&s.top() == target[B] {s.pop();B++;} //如果栈不为空，并且栈顶元素等于待出栈的车厢编号，则将栈顶元素出栈，并将 B 加 1。
			else if(A<=n) s.push(A++);//如果上述两种情况都不满足，并且还有车厢待进栈，则将当前待进栈的车厢编号压入栈中，并将 A 加 1。
			else{
				ok=0;
				break;
			}
		}
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
}
//三种情况：
//1.待进的是待出的是同一个，不进，待进A和待出B直接+1，进一辆马上出 
//2.栈顶的是待出的 ，出栈，待出B+1，出一辆 
//3.不能出，待进A+1 ，进一辆 
