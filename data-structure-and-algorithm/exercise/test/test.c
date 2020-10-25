#include<stdio.h>

int main()
{
    int yuwen = 84, sum = 0;
    double shuxue, wuli;
    shuxue = 83.333;
    wuli = 78.979;
    sum = yuwen + wuli + shuxue;
    
    // printf("yuwen \t= %p\nshuxue \t= %p\nwuli \t= %p\nsum \t= %p\n\n", &yuwen, &shuxue, &wuli, &sum);
    printf("yuwen = %d\nshuxue = %lf\nwuli = %lf\nsum = %lf\n\n", yuwen, shuxue, wuli, sum);
    // printf("sum_d = %p\n", &sum);
    printf("sum = %lf\n", sum); 
    return 0;
}
/*当整型 sum用 %lf 输出，第一次输出是0.00000，第二次输出是83.333，是shuxue的值，这是为什么？
*/