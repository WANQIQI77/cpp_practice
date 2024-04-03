#include<bits/stdc++.h>
using namespace std;
#define maxn 100
int left_chars,chance;
char s[maxn],s2[maxn];
int win,lose;

void guess(char ch)
{
	int bad =1;
	for(int i=0;i<strlen(s);i++)
		if(s[i]==ch){left_chars--;s[i]=' ';bad=0;}  //猜出来的字母置为空 
	if(bad) chance--; //chance次没有全部猜出来，就输了 
	if(!chance) lose = 1;
	if(!left_chars) win = 1;
}
int main()
{
	int rnd;
	while(scanf("%d%s%s",&rnd ,s ,s2) ==3 && rnd !=-1)
	{
		printf("Round %d\n", rnd);
		win = lose =0;
		left_chars=strlen(s);
		chance=7;
		for(int i=0;i<strlen(s2);i++)
		{
			guess(s2[i]);
			if(win||lose) break;
		}
		if (win) printf("You win.\n");
		else if(lose) printf("You lose.\n");
		else printf("You chickend out.\n");
	}
	return 0;
}
