#include <stdio.h>

void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(char *arr, int begin, int end) {
    for (int i = begin; i < end; i++) {
        for (int j = begin; j < end - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main(){
	int num;
	scanf("%d", &num);
	char str[10000];
	int m, n;

	for (int i = 0; i < num; i++) {
		scanf("%s", str);
		scanf("%d", &n);
		scanf("%d", &m);
		bubble_sort(str, n, m);
		printf("%s", str);
	}
}
