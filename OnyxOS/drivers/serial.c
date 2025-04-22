#include "serial.h"
#include "screen.h"

#define SERIAL_PORT 0x3F8

// دالة لكتابة البيانات إلى المنفذ التسلسلي
void serial_write(char c) {
    while (inb(SERIAL_PORT + 5) & 0x20) {  // الانتظار حتى يصبح المنفذ جاهزاً للكتابة
        // الانتظار
    }
    outb(SERIAL_PORT, c);  // إرسال الحرف إلى المنفذ التسلسلي
}

// دالة لقراءة البيانات من المنفذ التسلسلي
char serial_read() {
    while (!(inb(SERIAL_PORT + 5) & 1)) {  // الانتظار حتى يكون هناك بيانات
        // الانتظار
    }
    return inb(SERIAL_PORT);  // قراءة البيانات من المنفذ التسلسلي
}
