#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[100];
    cin.getline(a, 100);
    int len=strlen(a);
    for (int i = 0; i < len; i++) {
        if (a[i] >= 'a' && a[i] <= 'z') { // For lowercase letters
            a[i] = ((a[i] - 'a' + 3) % 26) + 'a'; // Correctly shift and wrap around the alphabet
        }
        else if (a[i] >= 'A' && a[i] <= 'Z') { // For uppercase letters
            a[i] = ((a[i] - 'A' + 3) % 26) + 'A'; // Correctly shift and wrap around the alphabet
        }
        // Non-alphabetic characters are left unchanged
    }

    cout << "Encrypted string: " << a << endl; // Output the encrypted string
    return 0;
    return 0;
}