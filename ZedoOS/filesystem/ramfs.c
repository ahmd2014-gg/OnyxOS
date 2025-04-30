#include "ramfs.h"
#include "memory.h"

#define MAX_RAM_FILES 64

typedef struct ramfs_file {
    char name[32];
    uint32_t size;
    uint32_t* data;
} RamFSFile;

static RamFSFile ram_files[MAX_RAM_FILES];
static int ram_file_count = 0;

// دالة لإنشاء ملف في الذاكرة
int ramfs_create(const char* name, uint32_t size) {
    if (ram_file_count >= MAX_RAM_FILES) {
        return -1;  // لم يعد هناك مساحة لإنشاء ملف جديد في الذاكرة
    }

    RamFSFile* new_file = &ram_files[ram_file_count++];
    strcpy(new_file->name, name);
    new_file->size = size;
    new_file->data = (uint32_t*)malloc(size);

    // تهيئة بيانات الملف
    for (int i = 0; i < size / sizeof(uint32_t); i++) {
        new_file->data[i] = 0;
    }

    return 0;  // تم إنشاء الملف بنجاح
}

// دالة لقراءة ملف من الذاكرة
int ramfs_read(const char* name, void* buffer, uint32_t size) {
    for (int i = 0; i < ram_file_count; i++) {
        if (strcmp(ram_files[i].name, name) == 0) {
            if (ram_files[i].size < size) {
                size = ram_files[i].size;  // لا يمكن قراءة أكثر من حجم الملف
            }
            memcpy(buffer, ram_files[i].data, size);
            return size;
        }
    }
    return -1;  // الملف غير موجود
}

// دالة لكتابة بيانات إلى ملف في الذاكرة
int ramfs_write(const char* name, const void* buffer, uint32_t size) {
    for (int i = 0; i < ram_file_count; i++) {
        if (strcmp(ram_files[i].name, name) == 0) {
            if (ram_files[i].size < size) {
                size = ram_files[i].size;  // لا يمكن كتابة أكثر من حجم الملف
            }
            memcpy(ram_files[i].data, buffer, size);
            return size;
        }
    }
    return -1;  // الملف غير موجود
}
