#include "buffer.h"

#define BUFFER_SIZE 128

// تعريف هيكلية البوفر
typedef struct {
    char buffer[BUFFER_SIZE];
    int head;
    int tail;
} CircularBuffer;

CircularBuffer input_buffer = { .head = 0, .tail = 0 };

// دالة لإضافة عنصر إلى البوفر
void buffer_add(char c) {
    if ((input_buffer.tail + 1) % BUFFER_SIZE != input_buffer.head) {  // إذا كانت المساحة متاحة
        input_buffer.buffer[input_buffer.tail] = c;
        input_buffer.tail = (input_buffer.tail + 1) % BUFFER_SIZE;
    }
}

// دالة لقراءة عنصر من البوفر
char buffer_read() {
    if (input_buffer.head != input_buffer.tail) {  // إذا كان هناك عنصر للقراءة
        char c = input_buffer.buffer[input_buffer.head];
        input_buffer.head = (input_buffer.head + 1) % BUFFER_SIZE;
        return c;
    }
    return -1;  // في حال كان البوفر فارغاً
}

// دالة للتحقق من البوفر (هل هناك عناصر للقراءة)
int buffer_available() {
    return input_buffer.head != input_buffer.tail;
}
