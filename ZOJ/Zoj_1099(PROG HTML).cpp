/*
PROG:   HTML
ID  :   ouyangyewei
LANG:   C++
*/
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

#define DEBUG 0

int main() {
#if DEBUG
    freopen("E:\\zoj_1099.in", "r", stdin);
    freopen("E:\\zoj_1099.out", "w", stdout);
#endif

    string words;
    int lineLen = 0;
    
    while (cin >> words) {
        if (words == "<br>") {  // ���� '<br>'���t�Q�� 
            cout << endl;
            lineLen = 0;  // ��һ�е����� 
        } else if (words == "<hr>") {
            if (lineLen != 0) {  // �������ף��t�Q�� 
                cout << endl;
            }
            for (int i = 0; i < 80; ++i) {
                cout << '-';
            }
            cout << endl;
            
            lineLen = 0;  // ��һ�е����� 
        } else {
            if (lineLen + words.size() <= 80) {
                if (!lineLen) {
                    cout << words;
                    lineLen = words.size();
                } else if (lineLen + 1 + words.size() <= 80) {
                    cout << " " << words;
                    lineLen += (1 + words.size());
                } else {
                    cout << endl << words;
                    lineLen = words.size();
                }
            } else {
                cout << endl << words;
                lineLen = words.size(); 
            }
        }
    }// End of while
    cout << endl;

    return 0;
}
