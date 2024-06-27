/*
在进行数据传输时常使用字符串压缩算法节约资源，小C发现在他传输的字符串中有很多连续的字符，他基于这一点创造了以下压缩方法:
所有相同且连续的字符串将被压缩成“连续个数+原字符”的形式，例如字符串“??????
AaaaBC”将被压缩为“1?3?1?1?“

输入
多组样例，第一行包含一个数字T表示样例组数。接下来每组样例占一行，保证输入字符串中只包含大小写字母、数字和空格。需要处理到输入结束(EOF)。

输出
对于每一组输入，输出压缩结果。

样例
输入
3
333 444
    ABCD
TJU 1895
输出
331 34
4 1A1B1C1D
1T1J1U1 11181915 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int s;
    cin>>n;
    cin.ignore(); // 忽略掉前一个输入后留下的换行符
    while(n--){
        string s;
        getline(cin,s);
        int len=s.size();
        for(int i=0;i<len;i++){
            int j=i+1;
            while(j<len&&s[j]==s[i]){
                j++;
            }
            cout<<j-i<<s[i];
            i=j-1;
        }
        cout<<endl;
    }
    return 0;
}