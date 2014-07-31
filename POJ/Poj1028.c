#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define LOCAL

int  topback = -1;
int  topfor  = -1;
char command[20] = {0};
char curpage[100] = "http://www.acm.org/";
char newpage[100] = {0};
char backward[110][80] = {0};
char forward[110][80] = {0};

int main()
{
#ifdef LOCAL
    freopen("E:\\poj1028.txt", "r", stdin);
    freopen("E:\\poj1028(result).txt", "w", stdout);
#endif

    while (EOF != scanf("%s", command), command[0]!='Q')
    {
        switch (command[0])
        {
            case 'V':
            {
                memset(newpage, 0, sizeof(newpage)); /* ��ջ�������ҳ���ַ������� */
                
                scanf("%s", newpage);
                if (strcmp(newpage, curpage) != 0)
                {   /* �������ҳ�����ڵ�ǰ��ҳ���򽫵�ǰ��ҳѹ�� backwardջ */ 
                    strcpy(backward[++topback], curpage);
                    
                    memset(curpage, 0, sizeof(curpage));
                    strcpy(curpage, newpage); /* ��ǰ��ҳ����Ϊ��������ҳ */
                }
                
                topfor = -1;
                memset(forward, 0, sizeof(forward));
                printf("%s\n", curpage);
            };break;
            
            case 'B':
            {
                if (topback == -1)
                {
                    printf("Ignored\n");
                }
                else
                {
                    strcpy(forward[++topfor], curpage);  /* ����ǰ��ҳѹ�� forward ջ */
                    
                    memset(curpage, 0, sizeof(curpage));
                    strcpy(curpage, backward[topback--]); /* �� backward ջ��Ԫ�ص��� */
                    strcpy(backward[topback+1], "\0");
                    printf("%s\n", curpage);
                }    
            }break;
            
            case 'F':
            {
                if (topfor == -1)
                {
                    printf("Ignored\n");
                }
                else
                {
                    strcpy(backward[++topback], curpage); /* ����ǰ��ҳѹ�� forward ջ */
                    
                    memset(curpage, 0, sizeof(curpage));
                    strcpy(curpage, forward[topfor--]);   /* �� forward ջ��Ԫ�ص��� */
                    strcpy(forward[topfor+1], "\0");
                    printf("%s\n", curpage);
                }
            };break;
        }/* End of Switch */
    }/* End of While */
    
    return 0;
}
