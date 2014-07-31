/*
PROG:   Hangman Judge
ID  :   ouyangyewei
LANG:   C++
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

#define DEBUG 0

// Remove the repetitive characters
string dupRemoval(string &ss) {
    string ret;
    int slen = ss.length();
    
    for (int i = 0; i < slen; ++i) {
        for (int j = i + 1; j < slen; ++j) {
            if (ss[j] == ss[i]) {
                ss[j] = ' ';
            }
        }
        if (ss[i] != ' ') {
            ret += ss[i];
        }
    }
    
    return ret;
}

// 1. ���Ƚ� 7 �λ��������޷��� first �Ƚ��꣬Ϊ lost
// 2. ���� 7 ���ڽ� first �Ƚ��꣬Ϊ win
// 3. ���� 7 ���ڣ�δ�� first �Ƚ��꣬second �ͱ��������ˣ�Ϊ chickened out
void Simula(string &frist, string &second) {
    int win = 0, lost = 0;
    int flen = frist.length();
    int slen = second.length();
    bool hash[27] = {false};
    
    // hashing the string 'frist'
    for (int i = 0; i < flen; ++i) {
        hash[frist[i]-'a'] = true;
    }
    // Simulation
    for (int i = 0; i < slen; ++i) {
        if (hash[second[i]-'a']) {
            ++win;
            if (win == flen) {
                break;
            }
        } else {
            ++lost;
            if (lost >= 7) {
                break;
            }
        }
    }
    if (win == flen && lost < 7) {
        cout << "You win." << endl;
    } else if (lost >= 7) {
        cout << "You lose." << endl;
    } else if (lost < 7 && win < flen) {
        cout << "You chickened out." << endl;
    }
}

int main() {
#if DEBUG
    freopen("E:\\489.in", "r", stdin);
    freopen("E:\\489.out", "w", stdout);
#endif

    int rounds;
    string frist, second;
    
    while (cin >> rounds && rounds != -1) {
        cin >> frist >> second;
        cout << "Round " << rounds << endl;
        
        // remove the repetitive characters
        frist = dupRemoval(frist);
        second = dupRemoval(second);
        
        // Simulation
        Simula(frist, second);
    }// End of while

    return 0;
}
