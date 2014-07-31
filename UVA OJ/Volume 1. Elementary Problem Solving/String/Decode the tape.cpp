/*
PROG:   Decode the tape
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

#define DEBUG 0

// ���룺tape �ϱ�ʾ 7 λ��2�������֣����пո��������� 0���ַ���0��
// ��ʾ������ 1����tape�ϵĶ�������ʮ�����ε�ASCIll���ǽ��������� 
void decodeTape(string &tapes) {
    int decimal = 0;
    int slen = tapes.length();
    
    for (int i = 0; i < slen; ++i) {
        if (tapes[i] == ' ') {
            decimal <<= 1;
        } else if (tapes[i] == 'o') {
            decimal = decimal << 1 | 1;
        }
    }
    printf("%c", decimal);
}

int main() {
#if DEBUG
    freopen("E:\\10878.in", "r", stdin);
    freopen("E:\\10878.out", "w", stdout);
#endif

    string tapes;
    
    while (getline(cin, tapes)) {
        //getchar();  // get the carry return
        if (tapes != "___________") {
            decodeTape(tapes);
        }
    }// End of while
    //printf("\n");
    
    return 0;
}
