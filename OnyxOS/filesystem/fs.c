#include "fs.h"
#include "memory.h"

#define MAX_FILES 64

typedef struct file {
    char name[32];
    uint32_t size;
    uint32_t* data;
} File;

static File filesystem[MAX_FILES];
static int file_count = 0;

// دالة لإنشاء ملف
int fs_create(const char* name, uint32_t size) {
    if (file_count >= MAX_FILES) {
        return -1;  // لم يعد هناك مساحة لإنشاء ملف جديد
    }
    
    File* new_file = &filesystem[file_count++];
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->data = (uint32_t*)malloc(size);
    
    // تهيئة بيانات الملف
    for (int i = 0; i < size / sizeof(uint32_t); i++) {
        new_file->data[i] = 0;
    }

    return 0;  // الملف تم إنشاؤه بنجاح
}

// دالة لقراءة ملف
int fs_read(const char* name, void* buffer, uint32_t size) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(filesystem[i].name, name) == 0) {
            if (filesystem[i].size < size) {
                size = filesystem[i].size;  // لا يمكن قراءة أكثر من حجم الملف
            }
            memcpy(buffer, filesystem[i].data, size);
            return size;
        }
    }
    return -1;  // الملف غير موجود
}

// دالة لكتابة بيانات إلى ملف
int fs_write(const char* name, const void* buffer, uint32_t size) {
    for (int i = 0; i < file_count; i++) {
        if (strcmp(filesystem[i].name, name) == 0) {
            if (filesystem[i].size < size) {
                size = filesystem[i].size;  // لا يمكن كتابة أكثر من حجم الملف
            }
            memcpy(filesystem[i].data, buffer, size);
            return size;
        }
    }
    return -1;  // الملف غير موجود
}
