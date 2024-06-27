#include <stdio.h>  
#include <cstring>
int main() {  
    //1、反序数
    int n;  
    scanf("%d", &n);  
    int ans = 0;//将反序之后的答案存在这里  
    while (n > 0) {//将n逐位分解  
        ans *= 10;  
        ans += (n % 10);  
        n /= 10;  
    }  
    printf("%d\n", ans);  

    //2、10进制转x
    int n, x;  
    char s[105];//十进制以上有字符，所以用char存储  
    //输入10进制n 和 要转换的进制x  
    scanf("%d%d", &n, &x);  
    int cnt = 0;//数组下标  
    while (n > 0) {//将n逐位分解  
        int w = (n % x);  
        if (w < 10) s[cnt++] = w + '0';//变成字符需要加'0'  
        else s[cnt++] = (w - 10) + 'A';//如果转换为小写则加'a'  
        //如果大于10则从A字符开始  
        n /= x;  
    }  
    //反序输出  
    for (int i = cnt - 1; i >= 0; i--) {  
        printf("%c", s[i]);  
    }  
    printf("\n"); 

    //3、x转10进制
    char s[105];  
    int x;  
    //输入X进制字符串 和 代表的进制x  
    scanf("%s%d", &s, &x);  
    int ans = 0;//  
    int len = strlen(s);  
    for (int i = 0; i < len; i++) {  
        ans = ans * x;  
        if (s[i] >= '0' && s[i] <= '9') ans += (s[i] - '0');  
        else ans += (s[i] - 'A') + 10;  
    }  
    printf("%d\n", ans);  
    

    //4、x转y进制
    char s[105];  
    int x, y;  
    //输入二进制字符串 和 代表的进制x 以及要转换的进制y  
    scanf("%s%d%d", &s, &x, &y);  
    int ans = 0;  
    int len = strlen(s);  
    for (int i = 0; i < len; i++) {  
        ans = ans * x;  
        if (s[i] >= '0' && s[i] <= '9') ans += (s[i] - '0');  
        else ans += (s[i] - 'A') + 10;  
    }  
    char out[105];  
    int cnt = 0;  
    while (ans > 0) {  
        int w = (ans % y);  
        if (w < 10) out[cnt++] = w + '0';  
        else out[cnt++] = (w-10) + 'A';  
        ans /= y;  
    }  
    for (int i = cnt - 1; i >= 0; i--) {  
        printf("%c", out[i]);  
    }  
    printf("\n");  

    //5、大数转换 //十进制转二进制
    char s[40], buf[200];
    int num[40];  
    while (scanf("%s", s) != EOF){  
        int len = strlen(s);  
        for (int i = 0; i < len; i++){//字符串转成int数组  
            num[i] = s[i] - '0';  
        }  
        int i = 0, len_str = 0;  
        while (i < len){//除2取余法  
            buf[len_str++] = num[len - 1] % 2 + '0';//将字符最后一位的余数转为字符  

            // 大数除法,更新num[]数组  
            int c = 0;  //用于存储当前位除以2后向下一位的进位。
            for (int j = i; j < len; j++){  
                int tmp = num[j];  
                num[j] = (num[j] + c) / 2; 
                //高位除2 数的高位对应数组低位  
                if (tmp % 2 == 1){//判断tmp是否为奇数  
                    c = 10;//如果当前位是奇数，那么在除以2时会有余数1，因此将进位设置为10（因为下一位除以2时需要加上这个余数*10）。
                }  
                else c = 0;  
            }  
            if (num[i] == 0) i++;//高位变为0  
        }  
        for (int j = len_str - 1; j >= 0; j--){  
            printf("%c", buf[j]);  
        }  
        printf("\n");  
    }  
    return 0;
}  