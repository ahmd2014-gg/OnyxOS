[bits 16]
[global]

; طباعة الأحرف باستخدام المقاطعة 0x10
print_char:
    mov ah, 0x0E
    int 0x10             ; استدعاء المقاطعة 0x10 لطباعة الحرف
    ret

; تحويل عدد إلى سلسلة (مثل تحويل عدد صحيح إلى نص)
itoa:
    ; تحويل العدد الموجود في register ax إلى سلسلة نصية
    mov cx, 10
itoa_loop:
    xor dx, dx           ; مسح الـ dx
    div cx               ; قسمة ax على 10
    add dl, '0'          ; تحويل الباقي إلى حرف
    push dx              ; تخزين الحرف المؤقت
    test ax, ax          ; اختبار إذا كانت القسمة انتهت
    jnz itoa_loop        ; إذا لم تنتهِ القسمة، استمر في الحلقة

    ; استرجاع الأرقام المحفوظة في المكدس
itoa_reverse:
    pop dx
    mov ah, 0x0E
    int 0x10             ; طباعة الحرف
    test sp, sp
    jnz itoa_reverse     ; استمر في الطباعة إذا كان هناك المزيد

    ret
