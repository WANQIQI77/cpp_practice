#include<bits/stdc++.h>
#include<stack>
using namespace std;
const int MAXN = 1000+10;
int n,target[MAXN];//n�ڳ��� 
int main(){
	while(scanf("%d",&n)==1){
		stack<int> s;
		int A=1,B=1;//��ǰ����ջ�ĳ����źʹ���ջ�ĳ����ţ���ʼֵ��Ϊ 1
		for(int i=0;i<=n;i++) scanf("%d", &target[i]);//��ջ˳�� 
		int ok =1;
		while(B<=n){
			if(A==target[B]){ //��ǰ����ջ�ĳ����źʹ���ջ�ĳ����ţ���ʼֵ��Ϊ 1
				A++;
				B++;
			}
			else if(!s.empty()&&s.top() == target[B] {s.pop();B++;} //���ջ��Ϊ�գ�����ջ��Ԫ�ص��ڴ���ջ�ĳ����ţ���ջ��Ԫ�س�ջ������ B �� 1��
			else if(A<=n) s.push(A++);//���������������������㣬���һ��г������ջ���򽫵�ǰ����ջ�ĳ�����ѹ��ջ�У����� A �� 1��
			else{
				ok=0;
				break;
			}
		}
		printf("%s\n",ok?"Yes":"No");
	}
	return 0;
}
//���������
//1.�������Ǵ�������ͬһ��������������A�ʹ���Bֱ��+1����һ�����ϳ� 
//2.ջ�����Ǵ����� ����ջ������B+1����һ�� 
//3.���ܳ�������A+1 ����һ�� 
