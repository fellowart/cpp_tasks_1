//YOUR CODE HERE
#include <iostream>

bool isValid(const char* s) {
    if (*s == '-' || *s == '+') ++s;
    if (*s < '0' || *s > '9') return false;
    while (*s >= '0' && *s <= '9') ++s;
    if (*s == '.') {
        ++s;
        if (*s < '0' || *s > '9') return false;
        while (*s >= '0' && *s <= '9') ++s;
    }
    return *s == '\0';
}

int cmp_abs(const char* a, const char* b) {
    const char* ae = a;
    const char* be = b;
    while (*ae >= '0' && *ae <= '9') ++ae;
    while (*be >= '0' && *be <= '9') ++be;

    if (ae - a < be - b) return -1;
    if (ae - a > be - b) return 1;

    while (a < ae) {
        if (*a < *b) return -1;
        if (*a > *b) return 1;
        ++a;
        ++b;
    }

    if (*a == '.') ++a;
    if (*b == '.') ++b;

    while (*a || *b) {
        char x = '0', y = '0';
        if (*a) x = *a++;
        if (*b) y = *b++;
        if (x < y) return -1;
        if (x > y) return 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 3 || !isValid(argv[1]) || !isValid(argv[2])) {
        return 1;
    }
    const char* a = argv[1];
    const char* b = argv[2];

    bool aNeg = false, bNeg = false;
    if (*a == '-') aNeg = true;
    if (*b == '-') bNeg = true;
    if (*a == '-' || *a == '+') ++a;
    if (*b == '-' || *b == '+') ++b;

    int res;
    if (aNeg && !bNeg) {
        res = -1;
    } else if (!aNeg && bNeg) {
        res = 1;
    } else {
        res = cmp_abs(a, b);
        if (aNeg) res = -res;
    }

    if (res == -1) std::cout << "less\n";
    else if (res == 1) std::cout << "greater\n";
    else std::cout << "equal\n";
}