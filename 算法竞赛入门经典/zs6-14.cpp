#include<bits/stdc++.h>
using namespace std;
const char dirs[5]='NESW';
const char turns[4]='FLR';
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
/*
�ú������� t�� turns �е���������� t ���� turns �У�strchr ������ NULL��
��ʱ���ʽ������һ����ָ���� NULL ����ļ���������δ������Ϊ��
*/
inline int sdir(char c){	//��dir��charת��Ϊint 
	return strchr(dirs,c)-dirs;
}
inline int sturn(char t){
	return strchr(turns,t)-turns;
}
//bx=begin_x,by=begin_y,bdir=begin_dir,ex=end_x,ey=end_y,nbx=new_begin_x,nby=new_begin_y �����ֻ����ǰֱ�ߣ�������Ҫ��һ������� 
int bx,by,bdir,ex,ey,nbx,nby;
bool edge[10][10][4][3]	//edge[x][y][dir][turn] ��ʾ�ܷ��(x,y,dir)ת��turn�����Ƿ��б�
int step[10][10][4];                    //��ͬ״ֻ̬��һ�Σ���Ҫһ��bool������ʾ�Ƿ��߹��������ʱ����Ҫ�ҵ���㣨����stepΪ0�ĵ㣩������ֱ����һ��step��������ʾ��һ�ε���ĳ��״̬ʱ�Ĳ�����û��������-1 
struct node                             //��Ԫ���״̬ 
{
	int x;
	int y;
	int dir;
	node(int x=0,int y=0,int dir=0)     //����ϲ������д���캯����Ҳ���Լ�дΪnode(int x=0,int y=0,int dir=0):x(x),y(y),dir(dir) {} 
	{
		this->x=x;
		this->y=y;
		this->dir=dir;
	}
}father[10][10][4];                    //father�����ʾÿ��״̬��ǰ��״̬�������������� 
node walk(const node &n,int turn) 
{
	int dir=n.dir;
	if(turn==1) dir=(dir+3)%4;
	else if(turn==2) dir=(dir+1)%4;
	return node(n.x+dx[dir],n.y+dy[dir],dir);
}
inline bool isdir(const char &c) {return c=='W'||c=='N'||c=='E'||c=='S';} //��������ʱ�ж� 
inline bool isturn(const char &c) {return c=='F'||c=='L'||c=='R';}
bool read()       //���뺯�� 
{
	string s;     //s�����ж������Ƿ���� 
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
	nbx=bx+dx[bdir]; //�����ת��Ϊ����� 
	nby=by+dy[bdir];
	return 1;
}
void print_ans(node &n) //����� 
{
	vector<node> v; //����Ҳ������stack������vector����vector�����ױ� 
	while(step[n.x][n.y][n.dir])
	{
		v.push_back(n);
		n=father[n.x][n.y][n.dir];
	}
	v.push_back(node(nbx,nby,bdir));//stepΪ0ʱ�Ѿ��˳���ѭ��������Ҫ�ֶ����������� 
	v.push_back(node(bx,by,bdir));//ͬ�� 
	int cnt=1;
	printf(" (%d,%d)",v.back().x,v.back().y);//�ֶ������һ���㣬˳���²�һ��uva��ȫ��ƥ�� 
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
void solve() //bfs��� 
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
	//��uDebug�Ļ�Ҫ����������� freopen("out.txt","w",stdout) 
	while(read()) solve();
	return 0;
}
