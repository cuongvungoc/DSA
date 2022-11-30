#include <stdio.h>

struct house_t {
    int x;
    int y;
    int h;
};

void swap_struct(struct house_t *h1, struct house_t *h2) {
    struct house_t temp;
    temp = *h1;
    *h1 = *h2;
    *h2 = temp;
}

void sort_by_x(struct house_t *house, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (house[j].x > house[j + 1].x) {
                swap_struct(&house[j], &house[j + 1]);
            }
        }
    }
}

void balenced(struct house_t *house, int begin, int end, int n) {
    int check = 0;
    for (int c = begin; c < end; c++) {
        int left = 0;
        int right = 0;
        for (int j = 0; j < n; j++) {    
            if (house[j].y > house[j].x + c) {
                left += house[j].h;
            }
            else if (house[j].y < house[j].x + c) {
                right += house[j].h;
            }
        }
        if (right == left) {
            check ++;
        }
    }

    if (check == 0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
}

int main() {
    FILE *fp;
    fp = fopen ("input.txt", "r++");
    int t;
    fscanf(fp, "%d", &t);
    int n;
    for(int i = 0; i < t; i++) {
        fscanf(fp, "%d", &n);

        struct house_t house[n]; 
        for (int j = 0; j < n; j++) {
            fscanf(fp, "%d", &house[j].x);
            fscanf(fp, "%d", &house[j].y);
            fscanf(fp, "%d", &house[j].h);
        }
        sort_by_x(house, n);
        balenced(house, house[0].x, house[n - 1].x - 1, n);
    }

    return 0;
}