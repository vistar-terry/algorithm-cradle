#include <stdio.h>

int main()
{
    int a[] = {0, 1, 2, 3};

    printf("   a.address: %p\n", a);
    for (int i = 0; i < 4; i++)
    { 
	printf("a[%d].address: %p\n", i, &a[i]);
    }
}
