#include <stdio.h>  
#include <cstring>
int main() {  
    //1��������
    int n;  
    scanf("%d", &n);  
    int ans = 0;//������֮��Ĵ𰸴�������  
    while (n > 0) {//��n��λ�ֽ�  
        ans *= 10;  
        ans += (n % 10);  
        n /= 10;  
    }  
    printf("%d\n", ans);  

    //2��10����תx
    int n, x;  
    char s[105];//ʮ�����������ַ���������char�洢  
    //����10����n �� Ҫת���Ľ���x  
    scanf("%d%d", &n, &x);  
    int cnt = 0;//�����±�  
    while (n > 0) {//��n��λ�ֽ�  
        int w = (n % x);  
        if (w < 10) s[cnt++] = w + '0';//����ַ���Ҫ��'0'  
        else s[cnt++] = (w - 10) + 'A';//���ת��ΪСд���'a'  
        //�������10���A�ַ���ʼ  
        n /= x;  
    }  
    //�������  
    for (int i = cnt - 1; i >= 0; i--) {  
        printf("%c", s[i]);  
    }  
    printf("\n"); 

    //3��xת10����
    char s[105];  
    int x;  
    //����X�����ַ��� �� ����Ľ���x  
    scanf("%s%d", &s, &x);  
    int ans = 0;//  
    int len = strlen(s);  
    for (int i = 0; i < len; i++) {  
        ans = ans * x;  
        if (s[i] >= '0' && s[i] <= '9') ans += (s[i] - '0');  
        else ans += (s[i] - 'A') + 10;  
    }  
    printf("%d\n", ans);  
    

    //4��xתy����
    char s[105];  
    int x, y;  
    //����������ַ��� �� ����Ľ���x �Լ�Ҫת���Ľ���y  
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

    //5������ת�� //ʮ����ת������
    char s[40], buf[200];
    int num[40];  
    while (scanf("%s", s) != EOF){  
        int len = strlen(s);  
        for (int i = 0; i < len; i++){//�ַ���ת��int����  
            num[i] = s[i] - '0';  
        }  
        int i = 0, len_str = 0;  
        while (i < len){//��2ȡ�෨  
            buf[len_str++] = num[len - 1] % 2 + '0';//���ַ����һλ������תΪ�ַ�  

            // ��������,����num[]����  
            int c = 0;  //���ڴ洢��ǰλ����2������һλ�Ľ�λ��
            for (int j = i; j < len; j++){  
                int tmp = num[j];  
                num[j] = (num[j] + c) / 2; 
                //��λ��2 ���ĸ�λ��Ӧ�����λ  
                if (tmp % 2 == 1){//�ж�tmp�Ƿ�Ϊ����  
                    c = 10;//�����ǰλ����������ô�ڳ���2ʱ��������1����˽���λ����Ϊ10����Ϊ��һλ����2ʱ��Ҫ�����������*10����
                }  
                else c = 0;  
            }  
            if (num[i] == 0) i++;//��λ��Ϊ0  
        }  
        for (int j = len_str - 1; j >= 0; j--){  
            printf("%c", buf[j]);  
        }  
        printf("\n");  
    }  
    return 0;
}  