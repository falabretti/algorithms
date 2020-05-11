#include <bits/stdc++.h>
using namespace std;

// kmp for pattern searching

void calc_lps(string p, int lps[]) {
    int len = 0;
    lps[0] = 0;

    for (int i = 1; i < p.size();) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp(string s, string p) {
    int lps[p.size()];
    calc_lps(p, lps);

    for (int i = 0, j = 0; i < s.size();) {
        if (s[i] == p[j]) {
            i++;
            j++;
        }

        if (j == p.size()) {
            printf("Pattern found at: %d\n", i - j);
            j = lps[j - 1];
        } else if (i < s.size() and s[i] != p[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string s, p;
    cin >> s >> p;

    kmp(s, p);

    return 0;
}