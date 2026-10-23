//YOUR CODE HERE
#include <iostream>

bool isValid(const char* s) {
    if (*s < '0' || *s > '9') return false;
    while (*s >= '0' && *s <= '9') ++s;
    return *s == '\0';
}

void reverse(int* arr, int l, int r) {
    while (l < r) {
        int tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        ++l;
        --r;
    }
}

int main(int argc, char** argv) {
    if (argc != 2 || !isValid(argv[1])) {
        return 1;
    }

    int n = 0;
    for (const char* s = argv[1]; *s; ++s) {
        n = n * 10 + (*s - '0');
        if (n > 100000) return 1;
    }
    if (n < 1) return 1;

    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    long long k;
    std::cin >> k;

    int shift = static_cast<int>(k % n);
    if (shift < 0) shift += n;

    if (shift != 0) {
        reverse(arr, 0, n - 1);
        reverse(arr, 0, shift - 1);
        reverse(arr, shift, n - 1);
    }

    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << '\n';
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << arr[i];
    }
    std::cout << '\n';

    delete[] arr;
}