#include<stdio.h>

int main()
{
    int yuwen = 84;
    double dd, shuxue, wuli, shengwu;
    int sum;
    dd = 34.809;
    shuxue = 83.333;
    wuli = 78.979;
    shengwu = 98.673;
    sum = yuwen + wuli + shuxue + shengwu;
    printf("yuwen = %d,\nshuxue = %lf,\nwuli = %lf,\nshengwu = %lf\n", yuwen, shuxue, wuli, shengwu);
    printf("sum_d = %d\n", &sum);
    printf("sum = %lf\n", sum); 
    return 0;
}
