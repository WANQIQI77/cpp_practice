//����ͺ��������ʹ·��Ȩ�غ���С
#include<iostream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

//��Ȩֵ��Ϊ�����
const int maxv = 10000+10; 
int in_order[maxv],post_order[maxv],lch[maxv],rch[maxv];
int n;

bool read_list(int *a){
	string line;
	if(!getline(cin,line)) return false;
	stringstream ss(line);
	n=0;
	int x;
	while(ss >> x) a[n++] =x; //ss >> x�����ַ�����ss�ж�ȡ��һ��������������洢������x��
	return n>0;
}
//��in_order��post_order����һ�ö���������������
int build(int L1,int R1,int L2,int R2){ //�������е���߽�L1���ұ߽�R1������������е���߽�L2���ұ߽�R2��
	if (L1>R1) return 0;//����
	int root = post_order[R2];
	int p=L1;
	while(in_order[p]!=root) p++;
	int cnt=p-L1;
	lch[root] = build(L1,p-1,L2,L2+cnt-1);
	rch[root] = build(p+1,R1,L2+cnt,R2-1);
	return root;
} 

int best,best_sum;

void dfs(int u,int sum){
	sum+=u;//��ǰ���Ȩ�غ� 
	if(!lch[u] && !rch[u]){ //Ҷ�ӽ�㣬û�����Һ��� 
		if(sum<best_sum || (sum == best_sum && u<best)) {
			best =u;
			best_sum=sum;
		} 
		if(lch[u]) dfs(lch[u],sum);
		if(rch[u]) dfs(rch[u],sum);
	}
}
int main(){
	while(read_list(in_order)){
		read_list(post_order);
		build(0,n-1,0,n-1);
		best_sum = 1000000000;
		dfs(post_order[n-1],0);
		cout<<best<<"\n";
	}
	return 0;
}
