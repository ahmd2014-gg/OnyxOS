#ifndef IRQ_H
#define IRQ_H

#include <stdint.h>

void irq_handler(uint8_t irq, uint32_t esp);
void irq_install();

#endif
