#include <stdio.h>

int main(){
    int a, b, c, x, y, z;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);
    printf("%d", (x/a)*(y/b)*(z/c));
    return 0;
}
