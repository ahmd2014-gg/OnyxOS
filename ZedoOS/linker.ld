ENTRY(start)

SECTIONS
{
    /* موقع بداية تحميل الكيرنل في الذاكرة */
    . = 1M;

    /* قسم النصوص (الكود) */
    .text ALIGN(4K) : AT(ADDR(.text)) {
        *(.multiboot)
        *(.text*)
    }

    /* قسم البيانات الثابتة */
    .rodata ALIGN(4K) : AT(ADDR(.rodata)) {
        *(.rodata*)
    }

    /* قسم البيانات القابلة للتعديل */
    .data ALIGN(4K) : AT(ADDR(.data)) {
        *(.data*)
    }

    /* قسم الذاكرة غير المهيّئة */
    .bss ALIGN(4K) : AT(ADDR(.bss)) {
        *(COMMON)
        *(.bss*)
    }
}
