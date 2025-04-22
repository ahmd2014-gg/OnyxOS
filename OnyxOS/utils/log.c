#include "log.h"
#include "userlib.h"

// دالة لتسجيل رسالة
void log_message(const char* message) {
    print("[LOG]: ");
    print(message);
    print("\n");
}

// دالة لتسجيل خطأ
void log_error(const char* message) {
    print("[ERROR]: ");
    print(message);
    print("\n");
}

// دالة لتسجيل تحذير
void log_warning(const char* message) {
    print("[WARNING]: ");
    print(message);
    print("\n");
}
