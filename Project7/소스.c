#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int* price = NULL;
    int sum = 0, max = 0;

    // 1. 상품 개수 입력 및 범위 검사
    printf("상품 개수 (1~100): ");
    if (scanf_s("%d", &n) != 1 || n < 1 || n > 100) {
        printf("입력 오류: 1~100 사이의 숫자를 입력하세요.\n");
        return 1;
    }

    // 2. malloc을 이용한 동적 메모리 할당
    price = (int*)malloc(n * sizeof(int));

    // 3. 메모리 할당 성공 여부 확인
    if (price == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 4. 상품 가격 입력 및 배열 저장
    for (int i = 0; i < n; i++) {
        printf("상품 %d 가격: ", i + 1);

        // 입력 오류 발생 시 메모리 해제
        if (scanf_s("%d", &price[i]) != 1 || price[i] < 0) {
            printf("입력 오류: 올바른 가격을 입력하세요.\n");
            free(price);
            price = NULL;
            return 1;
        }

        sum += price[i];
        if (price[i] > max) {
            max = price[i];
        }
    }

    // 5. 전체 상품 가격 출력
    printf("입력된 상품 가격: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }
    printf("\n");

    // 6. 평균 가격과 최고 가격 출력
    printf("평균 가격: %.1f원\n", (double)sum / n);
    printf("최고 가격: %d원\n", max);

    // 7. 동적 메모리 해제 및 NULL 설정
    free(price);
    price = NULL;

    return 0;
}