#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
    int i, j, x, y, flag = 1, select = 0, count = 0;
    int movie[5][5][5] = { 0 };
    char yn;

    printf("��ȭ�� ������\n");
    while (select != 6)
    {
        printf("1.���˵���3\t 2.����4\t 3.������� ���ܼ�\t 4.¯�� \t 5.�������Դϴ�.\t 6.����\n");
        scanf("%d", &select);
        while (1)
        {
            printf(" 1 2 3 4 5\n");
            for (i = 0; i < 5; i++)
            {
                printf(" %d", i + 1);
                for (j = 0; j < 5; j++)
                {
                    if (movie[select - 1][i][j] == 1)
                        printf("��");
                    else
                        printf("��");
                }
                printf("\n");
            }
            if (flag == 1)
            {
                printf("�¼��� �Է��ϼ���(����(-1 -1))\n");
                scanf("%d %d", &x, &y);
                if (x == -1 && y == -1)
                    break;
                if (movie[select - 1][y - 1][x - 1] == 1)
                {
                    printf("�̹� ����� �¼��Դϴ�\n");
                }
                else
                {
                    movie[select - 1][y - 1][x - 1] = 1;
                    flag = 0;
                }
            }
            else
            {
                printf("������ �¼��� �½��ϱ�? (Y/N)\n");
                scanf(" %c", &yn);
                if (yn == 'Y' || yn == 'y')
                {
                    count++;
                    flag = 1;
                }
                else
                {
                    movie[select - 1][y - 1][x - 1] = 0;
                    flag = 1;
                }
            }
        }
        printf("%d ���� �¼��� �����ϼ�����, %d���Դϴ�\n", count, count * 9000);
        count = 0;
    }
}