CC = gcc
LD = ld
AS = nasm
CFLAGS = -ffreestanding -nostdlib -O2 -Wall -Wextra
LDFLAGS = -T linker.ld
KERNEL_BIN = onyxos.bin
BUILD_DIR = build
ISO_DIR = build/iso
GRUB_DIR = build/iso/boot/grub
SRC = $(wildcard nucleus/*.c core/*.c drivers/*.c memory/*.c io/*.c multitask/*.c filesystem/*.c usermode/*.c utils/*.c)

all: $(KERNEL_BIN) $(ISO_DIR)

$(KERNEL_BIN): $(SRC)
	$(CC) $(CFLAGS) -o $(KERNEL_BIN) $(SRC) $(LDFLAGS)

$(ISO_DIR): $(KERNEL_BIN)
	mkdir -p $(ISO_DIR)/boot/grub
	cp $(KERNEL_BIN) $(ISO_DIR)/boot/
	cp grub.cfg $(GRUB_DIR)
	grub-mkrescue -o $(BUILD_DIR)/onyxos.iso $(ISO_DIR)

clean:
	rm -f $(KERNEL_BIN)
	rm -rf $(BUILD_DIR)