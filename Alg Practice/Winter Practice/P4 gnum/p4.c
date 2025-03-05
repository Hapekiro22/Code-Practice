//好数判断
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int judge1 = 0, judge2 = 0;
    judge1 = !(n%2);
    judge2 = (n>4)&&(n<=12);
    printf("%d %d %d %d\n",judge1&&judge2,judge1||judge2,judge1^judge2,!(judge1||judge2));
    return 0;
}