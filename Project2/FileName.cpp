#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
    int i, j, x, y, flag = 1, select = 0, count = 0;
    int movie[5][5][5] = { 0 };
    char yn;

    printf("영화를 고르세요\n");
    while (select != 6)
    {
        printf("1.범죄도시3\t 2.존윅4\t 3.스즈매의 문단속\t 4.짱구 \t 5.문재인입니다.\t 6.종료\n");
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
                        printf("■");
                    else
                        printf("□");
                }
                printf("\n");
            }
            if (flag == 1)
            {
                printf("좌석을 입력하세요(종료(-1 -1))\n");
                scanf("%d %d", &x, &y);
                if (x == -1 && y == -1)
                    break;
                if (movie[select - 1][y - 1][x - 1] == 1)
                {
                    printf("이미 예약된 좌석입니다\n");
                }
                else
                {
                    movie[select - 1][y - 1][x - 1] = 1;
                    flag = 0;
                }
            }
            else
            {
                printf("선택한 좌석이 맞습니까? (Y/N)\n");
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
        printf("%d 개의 좌석을 예약하셨으며, %d원입니다\n", count, count * 9000);
        count = 0;
    }
}