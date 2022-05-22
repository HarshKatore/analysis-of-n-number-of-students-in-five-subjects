#include <stdio.h>
void highest(int s[][5], int m)
{ // atleast second of [] iscompulsory
    int max = s[0][3];
    int j = 1;
    for (int p = 0; p < m; p++)
    {
        if (s[p][3] > max)
        {
            max = s[p][3];
            j = p;
        }
    }
    printf("  The student  %d has the highest marks in subject number 4\n ", j + 1);
}

void percentage(int marks[][5], int m)
{
    int a, b, flag;
    float sum = 0, p;
    for (a = 0; a < m; a++)
    {
        flag = 0;
        for (b = 0; b < 5; b++)
        {
            if (marks[a][b] < 45)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            continue;
        }
        sum += 1;
    }
    m=sum;
    p = (sum / 5) * 100;
    printf(" The %0.2f percent  is the overall result of class\n ", p);
    printf(" The %d  students  passed all subjects \n", m);
}

void fail_students(int marks[][5], int m)
{
    int a, b, z=0, sum = 0;
    for (a = 0; a < m; a++)
    {
        sum = 0;
        for (b = 0; b < 5; b++)
        {
            if (marks[a][b] < 45)
            {
                sum += 1;
            if (sum == 1)
            {
                z++;
            }
            }
        }
    }
    printf("  Students failed in one subject are: %d\n", z);
}

void distinction(int marks[][5], int m)
{
    int a, b, dist = 0;
    float per, sum;
    for (a = 0; a < m; a++)
    {
        sum = 0;
        for (b = 0; b < 5; b++)
        {
            sum += marks[a][b];
        }
        per = (sum / 500) * 100;
        if (per >= 70)
        {
            dist += 1;
        }
    }
    printf("total number of distinction in the class are %d", dist);
}

int main()
{
    int m;
    printf("enter the total number of the student: ", m);
    scanf("%d", &m);
    int s[m][5];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("enter the marks of the student %d of subject %d\n", i + 1, j + 1);
            scanf("%d", &s[i][j]);
        }
    }
    highest(s, m);
    percentage(s, m);
    fail_students(s, m);
    distinction(s, m);
    return 0;
}