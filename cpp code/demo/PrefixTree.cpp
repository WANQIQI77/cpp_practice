//Ç°×ºÊ÷
#include <bits/stdc++.h>  
using namespace std;  
  
const int maxn = 26;  
typedef struct TrieNode {  
    int nCount;  
    struct TrieNode *next[maxn];  
}Trie;  
Trie root;  
void InitTrie() {  
    for (int i = 0; i < maxn; i++)  
        root.next[i] = NULL;  
}  
void CreateTrie(char *str) {  
    int len = strlen(str);  
    Trie *p = &root, *q;  
    for (int i = 0; i < len; i++) {  
        int k = str[i] - 'a';  
        if (p->next[k] == NULL) {  
            q = (Trie *)malloc(sizeof(root));  
            q->nCount = 1;  
            for (int j = 0; j < maxn; j++)  
                q->next[j] = NULL;  
            p->next[k] = q;  
            p = p->next[k];  
        }  
        else {  
            p->next[k]->nCount++;  
            p = p->next[k];  
        }  
    }  
}  
int FindTrie(char *str) {  
    int len = strlen(str);  
    Trie *p = &root;  
    for (int i = 0; i < len; i++) {  
        int k = str[i] - 'a';  
        if (p->next[k] == NULL) return 0;  
        p = p->next[k];  
    }  
    return p->nCount;  
}  
int main() {  
    char str[15];  
    InitTrie();  
    while (gets(str) && str[0]) CreateTrie(str);  
    while (gets(str)) printf("%d\n", FindTrie(str));  
    return 0;  
}  