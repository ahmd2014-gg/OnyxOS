[bits 16]
[org 0x7C00]

start:
    cli                 ; تعطيل المقاطعات
    xor ax, ax          ; مسح سجل AX
    mov ds, ax          ; تعيين DS إلى 0
    mov es, ax          ; تعيين ES إلى 0
    mov fs, ax          ; تعيين FS إلى 0
    mov gs, ax          ; تعيين GS إلى 0

    ; طباعة رسالة
    mov si, message
    call print_string

    ; إنهاء
    hlt

print_string:
    ; دالة طباعة السلسلة
    mov ah, 0x0E
.print_loop:
    lodsb
    cmp al, 0
    je .done
    int 0x10
    jmp .print_loop
.done:
    ret

message db 'OnyxOS Bootloader Initialized!', 0
times 510 - ($ - $$) db 0
dw 0xAA55
