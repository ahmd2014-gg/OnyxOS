#include "math.h"

// دالة لحساب القيمة المطلقة
int abs(int x) {
    return x < 0 ? -x : x;
}

// دالة لحساب الحد الأقصى بين رقمين
int max(int a, int b) {
    return a > b ? a : b;
}

// دالة لحساب الحد الأدنى بين رقمين
int min(int a, int b) {
    return a < b ? a : b;
}

// دالة لحساب القوة
int pow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}
