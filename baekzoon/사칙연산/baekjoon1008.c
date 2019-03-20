//백준-1008 a/b
//두 수는 주어짐, 절대/상대 오차는 10^-9까지 허 용 
#include <stdio.h>
 
int main() {
    double a, b;
    scanf("%d %d", &a, &b);
    printf("%.9f\n", a / b);
    return 0;
}
