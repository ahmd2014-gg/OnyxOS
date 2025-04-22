#include "vfs.h"
#include "fs.h"

typedef struct vfs_file_ops {
    int (*read)(const char* name, void* buffer, uint32_t size);
    int (*write)(const char* name, const void* buffer, uint32_t size);
} VFSFileOps;

static VFSFileOps vfs_ops = {
    .read = fs_read,
    .write = fs_write
};

// دالة لقراءة ملف عبر VFS
int vfs_read(const char* name, void* buffer, uint32_t size) {
    return vfs_ops.read(name, buffer, size);
}

// دالة لكتابة بيانات إلى ملف عبر VFS
int vfs_write(const char* name, const void* buffer, uint32_t size) {
    return vfs_ops.write(name, buffer, size);
}
