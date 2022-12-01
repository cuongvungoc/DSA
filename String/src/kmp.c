#include <stdio.h>

unsigned int my_strlen(const char *s) {
    unsigned int count = 0;
    while(*s!='\0')
    {
        count++;
        s++;
    }
    return count;
}

void compute_LPS_array(char *pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp_search(char *pat, char *txt) {
    int m = my_strlen(pat);
    int n = my_strlen(txt);

    int lps[m];
    compute_LPS_array(pat, m, lps);

    int i = 0;
    int j = 0;
    
    while ((n - i) >= (m - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == m) {
            printf("Pattern index: %d\n", i - j);
            j = lps[j - 1];
        }

        else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
}

int main() {
    char txt[] = "abcabdabefgh";
    char pat[] = "dab";
    kmp_search(pat, txt);
    return 0;
}