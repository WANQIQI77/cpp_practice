#include<bits/stdc++.h>
using namespace std;
const char dirs[5]='NESW';
const char turns[4]='FLR';
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
/*
该函数返回 t在 turns 中的索引，如果 t 不在 turns 中，strchr 将返回 NULL，
此时表达式将产生一个将指针与 NULL 对齐的减法，这是未定义行为。
*/
inline int sdir(char c){	//将dir由char转化为int 
	return strchr(dirs,c)-dirs;
}
inline int sturn(char t){
	return strchr(turns,t)-turns;
}
//bx=begin_x,by=begin_y,bdir=begin_dir,ex=end_x,ey=end_y,nbx=new_begin_x,nby=new_begin_y 在起点只能向前直走，所以需要搞一个新起点 
int bx,by,bdir,ex,ey,nbx,nby;
bool edge[10][10][4][3]	//edge[x][y][dir][turn] 表示能否从(x,y,dir)转向turn，即是否有边
int step[10][10][4];                    //相同状态只走一次，需要一个bool组来表示是否走过，输出答案时又需要找到起点（步数step为0的点），所以直接用一个step数组来表示第一次到达某个状态时的步数，没到过就是-1 
struct node                             //三元组表状态 
{
	int x;
	int y;
	int dir;
	node(int x=0,int y=0,int dir=0)     //个人喜欢这样写构造函数，也可以简写为node(int x=0,int y=0,int dir=0):x(x),y(y),dir(dir) {} 
	{
		this->x=x;
		this->y=y;
		this->dir=dir;
	}
}father[10][10][4];                    //father数组表示每个状态的前驱状态，方便最好输出答案 
node walk(const node &n,int turn) 
{
	int dir=n.dir;
	if(turn==1) dir=(dir+3)%4;
	else if(turn==2) dir=(dir+1)%4;
	return node(n.x+dx[dir],n.y+dy[dir],dir);
}
inline bool isdir(const char &c) {return c=='W'||c=='N'||c=='E'||c=='S';} //方便输入时判断 
inline bool isturn(const char &c) {return c=='F'||c=='L'||c=='R';}
bool read()       //输入函数 
{
	string s;     //s方便判断数据是否结束 
	cin>>s;
	if(s=="END") return 0;
	memset(step,-1,sizeof(step));
	memset(edge,0,sizeof(edge));
	cout<<s<<endl<<" ";
	char tdir;
	scanf("%d %d %c %d %d",&bx,&by,&tdir,&ex,&ey);
	bdir=sdir(tdir);
	int tx,ty;
	while(scanf("%d %d",&tx,&ty)==2)
	{
		string s1;
		getline(cin,s1);
		for(int i=0;i<s1.size();++i)
		{
			if(isdir(s1[i]))
			{
				register int dir1=sdir(s1[i]);
				while(isturn(s1[++i]))
				{
					register int turn1=sturn(s1[i]);
					edge[tx][ty][dir1][turn1]=1;
				}
			}
		}
	}
	nbx=bx+dx[bdir]; //由起点转换为新起点 
	nby=by+dy[bdir];
	return 1;
}
void print_ans(node &n) //输出答案 
{
	vector<node> v; //这里也可以用stack来代替vector，但vector不容易崩 
	while(step[n.x][n.y][n.dir])
	{
		v.push_back(n);
		n=father[n.x][n.y][n.dir];
	}
	v.push_back(node(nbx,nby,bdir));//step为0时已经退出了循环，所以要手动把新起点加上 
	v.push_back(node(bx,by,bdir));//同理 
	int cnt=1;
	printf(" (%d,%d)",v.back().x,v.back().y);//手动输出第一个点，顺便吐槽一句uva的全字匹配 
	v.pop_back();
	while(!v.empty())
	{
		++cnt;
		if((cnt=cnt%10)==1)
		{
			printf("\n  (%d,%d)",v.back().x,v.back().y);
			v.pop_back();
		}
		else
		{
			printf(" (%d,%d)",v.back().x,v.back().y);
			v.pop_back();
		}
	}
	return;
}
void solve() //bfs求解 
{
	queue<node> q;
	node nbegin(nbx,nby,bdir);
	step[nbx][nby][bdir]=0;
	q.push(nbegin);
	while(!q.empty())
	{
		node tmp=q.front();q.pop();
		if(tmp.x==ex&&tmp.y==ey)
		{
			print_ans(tmp);
			cout<<endl;
			return;
		}
		for(int i=0;i<3;++i)
		{
			if(edge[tmp.x][tmp.y][tmp.dir][i])
			{
				node nn=walk(tmp,i);
				if(step[nn.x][nn.y][nn.dir]>-1) continue;
				q.push(nn);
				step[nn.x][nn.y][nn.dir]=step[tmp.x][tmp.y][tmp.dir]+1;
				father[nn.x][nn.y][nn.dir]=tmp;
			}
		}
	}
	cout<<" No Solution Possible"<<endl;
	return;
}
int main()
{
	//用uDebug的话要把输出存起来 freopen("out.txt","w",stdout) 
	while(read()) solve();
	return 0;
}
