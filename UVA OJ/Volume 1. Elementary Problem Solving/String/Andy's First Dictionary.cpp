/*
PROG:   Andy's First Dictionary
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <iostream>

using namespace std;

typedef set<char *> SCP;

#define DEBUG 1

// ��ָ�� s ָ��ĵ���ת��ΪСд 
void ChangeCases(char *&s) {
    for (int i = 0; *(s + i) != '\0'; ++i) {
        if (islower(*(s + i))) {
            *(s + i) = tolower(*(s + i));
        }
    }
}

// �������һ�зֽ�ɵ��ʣ�����¼�ڼ��� data �� 
void SplitWords(string &lines, SCP &data) {
    char ss[204] = {0};
    strncpy(ss, lines.c_str(), 200);
    
    char *ptr = strtok(ss, " ");
    while (ptr != NULL) {
        ChangeCases(ptr);
        data.insert(ptr);
        ptr = strtok(NULL, " ");
    }
}

// ݔ�����в�ͬ�Ć��~
void Display(SCP &data) {
    SCP::iterator iter;
    for (iter = data.begin(); iter != data.end(); ++iter) {
        cout << *iter << endl;
    }
} 

int main() {
#if DEBUG
    freopen("E:\\10815.in", "r", stdin);
    freopen("E:\\10815.out", "w", stdout);
#endif

    SCP data;  // ���ʼ��� 
    string lines;
    
    while (getline(cin, lines)) {
        if (!lines.empty()) {
            SplitWords(lines, data);
        }
    }// End of while
    Display(data);

    return 0;
}
