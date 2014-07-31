/**
 * PROG: �򵥼�����
 */
#include <map>
#include <stack>
#include <string>
#include <iomanip>
#include <iostream>
#include <cctype>

using namespace std;

map<char, int> g_grade;  // �������ȼ�

/**
 * Ԥ�����ȼ�
 */
void GetGrade()
{
    g_grade['#'] = 1;
    g_grade['+'] = 2;
    g_grade['-'] = 2;
    g_grade['*'] = 3;
    g_grade['/'] = 3;
}

/**
 * @infix:��׺���ʽ
 */
string GetPostfixBy(const string& infix)
{
    stack<char> symbol;  // ����ջ
    symbol.push('#');

    string postfix;      // ��׺���ʽ

    /**
     *  1. ջ��ʼѹ�� '#' ��Ϊ��׺���ʽ�Ľ�����־
     *  2. �����ǰɨ����ַ�Ϊ���֣�������������ֱ�����
           ����׺���ʽ�ַ���postfix�У����� $ �ָ�
     *  3. �����ǰɨ����ַ��ǲ����������ջ���Ĳ���������
           �����ڻ���ڸò�����������ջ������ջ������������
           ��׺���ʽ�ַ���postfix��
     *  4. ��ɨ������׺���ʽ���ַ�ջ�ǿգ���ջ����
     */
    int strLen = infix.length();
    for (int i=0; i<strLen; ++i)
    {
        if (isdigit(infix[i]))
        {
            postfix += infix[i];
        }
        else if ('+'==infix[i] ||
                 '-'==infix[i] ||
                 '*'==infix[i] ||
                 '/'==infix[i])
        {
            postfix += '$';  // end of number
            while (g_grade[symbol.top()] >= g_grade[infix[i]])
            {
                postfix += symbol.top();
                symbol.pop();
            }
            symbol.push(infix[i]);
        }
    }
    postfix += '$';
    while (!symbol.empty())
    {
        postfix += symbol.top();
        symbol.pop();
    }
    return postfix;
}

/**
 * @postfix:��׺���ʽ
 */
double CalcBy(const string& postfix)
{
    stack<double> number;

    int strLen = postfix.length();
    for (int i=0; i<strLen; ++i)
    {
        if (isdigit(postfix[i]))
        {
            double temp = 0.0;
            while (isdigit(postfix[i]))
            {
                temp = temp * 10.0 + (postfix[i++] - '0');
            }
            number.push(temp);

            --i;
        }
        else if ('+' == postfix[i] ||
                 '-' == postfix[i] ||
                 '*' == postfix[i] ||
                 '/' == postfix[i])
        {
            double number_b = number.top();
            number.pop();
            double number_a = number.top();
            number.pop();
            double result;
            switch (postfix[i])
            {
                case '+':
                    result = number_a + number_b;
                    break;
                case '-':
                    result = number_a - number_b;
                    break;
                case '*':
                    result = number_a * number_b;
                    break;
                case '/':
                    result = number_a / number_b;
                    break;
                default:
                    result = 0.0;
                    break;
            }
            number.push(result);
        }
    }// End of For
    return (number.top());
}

int main(void)
{
    GetGrade();

    string infix;
    while (getline(cin, infix))
    {
        if ("0" == infix)
        {
            break;
        }
        // cout << infix << endl;
        string postfix = GetPostfixBy(infix);
        cout << std::fixed << setprecision(2) << CalcBy(postfix) << endl;
        //cout << postfix << endl;
    }// End of While
    return 0;
}
