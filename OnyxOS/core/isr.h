#ifndef ISR_H
#define ISR_H

#include <stdint.h>

void isr_handler(uint8_t interrupt, uint32_t esp);
void isr_install();

#endif
