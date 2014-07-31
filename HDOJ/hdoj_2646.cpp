#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAXSIZE 1000
//#define localjudge

char inExp[MAXSIZE] = {0};          /* ������׺���ʽ */ 
char postexp[MAXSIZE] = {0};        /* �����׺���ʽ */
int  scp[6] = {0, 2, 8, 8, 4, 4};   /* ջ�ڲ����������ȼ� */ 
int  ecp[6] = {0, 12, 8, 8, 4, 4};  /* ջ������������ȼ� */ 

int Index(char symbol)
{   /* ���ز������������±� */ 
    switch (symbol)
    {
        case '$' : return 0;
        case '(' : return 1;
        case '*' : return 2;
        case '/' : return 3;
        case '+' : return 4;
        case '-' : return 5;
    }
}/* priority */

void TransToPostExp(char *infix)
{
    int  sp, ep;              /* StackCharPriority , ExpressCharPriority */
    int  ix=0, top=-1;
    char stack[MAXSIZE] = {0};      /* �����ַ�ջ */ 
    
    stack[++top] = '$';       /* ��׺���ʽ�Ľ�����־ */ 
    while (top!=-1 && *infix!='\0')
    {
        /***
         *  1. ջ��ʼѹ�� '$' ��Ϊ��׺���ʽ�Ľ�����־ 
         *  2. �����ǰɨ����ַ�Ϊ '(', ��ֱ��ѹ��ջ 
         *  3. �����ǰɨ����ַ�Ϊ  ')', ��ջ�� '(', '('ǰ�����в���������postexp��
         *  4. �����ǰɨ����ַ�Ϊ���֣�������������ֱ�ӷ���ջ������ # �ָ�  
         *  5. �����ǰɨ����ַ��ǲ����������ջ���Ĳ��������ȼ����ڻ���ڸò�������
         *     ����ջ������ջ������������postexp��
         *  6. ��ɨ������׺���ʽ���ַ�ջ�ǿգ���ջ���� 
         ***/
        if (*infix>='0' && *infix<='9')
        {
            while (*infix>='0' && *infix<='9')
            {   /* ��ǰɨ����ַ�Ϊ���֣�������������ֱ�ӷ���ջ */
                postexp[ix++] = *infix;
                infix++;
            }
            postexp[ix++] = '#';   /* ������ # �ָ� */
        }
        else
        {
            switch (*infix)
            {
                case '(' : stack[++top] = *infix; break;
                case ')' :
                {
                    while (top!=-1 && stack[top]!='(')
                    {   /* ��ջ�� '('��'('ǰ�����в���������postexp�� */
                        postexp[ix++] = stack[top--];
                    }
                    stack[top--];   /* '(' ��ջ */ 
                };break;
                default :
                {
                    sp = Index(stack[top]);  /* ���ջ�����������±����� */ 
                    ep = Index(*infix);      /* ��õ�ǰɨ����ʽ���������±����� */
                    for ( ;*infix!='\0' && scp[sp]>=ecp[ep]; )
                    {
                        postexp[ix++] = stack[top--]; /* ��������ջ��postexp */ 
                        sp = Index(stack[top]);       /* ���»��ջ�����������±����� */
                    }
                    
                    if (*infix != '\0')
                    {
                        stack[++top] = *infix;
                    }
                };break;
            }/* End of switch */

            ++infix;  /* ����ɨ����׺���ʽ����һ�ַ� */ 
        }/* End of Else */
    }/* End of While */
    
    /* ��ɨ������׺���ʽ���ַ�ջ�ǿգ���ջ��postexp */
    while (top != -1)
    {
        postexp[ix++] = stack[top--];
    }
    
    return ;
}/* TransToPostExp */

void EvalOfPostExp(char *postfix)
{
    double operand[MAXSIZE] = {0};
    double aNum, bNum, temp;
    int    top=-1;
    
    while (*postfix != '$')
    {
        switch (*postfix)
        {
            case '+' :
            {
                aNum = operand[top--];
                bNum = operand[top--];
                operand[++top] = bNum + aNum;
            };break;
            case '-' :
            {
                aNum = operand[top--];
                bNum = operand[top--];
                operand[++top] = bNum - aNum;
            };break;
            case '*' :
            {
                aNum = operand[top--];
                bNum = operand[top--];
                operand[++top] = 1.0 * bNum * aNum;
            };break;
            case '/' :
            {
                aNum = operand[top--];
                bNum = operand[top--];
                operand[++top] = 1.0 * bNum / aNum;
            };break;
            default  :
            {
                temp = 0.0;
                while (*postfix>='0' && *postfix<='9')
                {
                    temp = 10.0 * temp + (*postfix-'0');
                    ++postfix;
                }/* End of While */
                operand[++top] = temp;
            };break;
        }/* End of switch */
        
        ++postfix;
    }/* End of While */
    
    printf("The answer is  : %.3lf\n", operand[top]);
}/* EvalOfPostExp */

int main()
{
#ifdef localjudge
    freopen("E:\\EvaluationOfExpression.txt", "r", stdin);
    freopen("E:\\EvaluationOfExpression(result).txt", "w", stdout);
#endif

    while (~scanf("%s", inExp))
    {
        /* ��ջ����׺���ʽ������ */ 
        memset(postexp, 0, sizeof(postexp));
        
        /* ��׺���ʽת������׺���ʽ */ 
        TransToPostExp(inExp);
        
        /* Evaluation the PostExpression */
        EvalOfPostExp(postexp);
        
        /* ��ջ�����׺���ʽ������ */ 
        memset(inExp, 0, sizeof(inExp));
    }/* End of While */
    
    return 0; 
}
