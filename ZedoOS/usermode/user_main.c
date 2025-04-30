#include "usyscall.h"
#include "userlib.h"

// نقطة البداية لعملية المستخدم
void main() {
    // طباعة رسالة ترحيبية
    print("Hello, this is the user process starting!\n");

    // نداء نظام لفتح ملف
    int file = open("test.txt", 0);
    if (file < 0) {
        print("Error opening file!\n");
    } else {
        print("File opened successfully!\n");
    }

    // نداء نظام لقراءة من الملف
    char buffer[128];
    int bytes_read = read(file, buffer, sizeof(buffer));
    if (bytes_read > 0) {
        print("Read data: ");
        print(buffer);
    }

    // إغلاق الملف
    close(file);

    // إنهاء العملية بنجاح
    exit(0);
}
