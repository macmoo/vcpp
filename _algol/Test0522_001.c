#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x;
    // int형 오브젝트 생성
    x = calloc(1, sizeof(int));
    if(x == NULL)
        puts("Failed");
    else{
        *x = 57;
        printf("%d\n", *x);
        free(x); // 메모리해제
        printf("%d\n", *x);  // <- 에러안남(쓰레기값출력)
    }
    return 0;
}