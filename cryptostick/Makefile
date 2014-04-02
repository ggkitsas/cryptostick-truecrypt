ROOT_DIR=$(CURDIR)
CRYPTO_DIR=cryptostick.oath
BUILD_DIR=$(CRYPTO_DIR)/firmware/build/gcc
QEMU_DIR=../qemu/qemu_stm32/arm-softmmu/
MEM=128

setup:
	sudo add-apt-repository ppa:terry.guo/gcc-arm-embedded
	sudo apt-get update
	sudo apt-get install gcc-arm-none-eabi

all:
	cd cryptostick.oath/firmware/build/gcc && \
	make all

emulate:
	#$(QEMU_DIR)/qemu-system-arm  -m $(MEM)M -nographic -kernel $(BUILD_DIR)/crypto.elf
	$(QEMU_DIR)/qemu-system-arm  -M stm32-p103 -kernel $(BUILD_DIR)/crypto.elf -serial stdio -monitor stdio -usb
#	qemu-system-arm -M stm32-p103 -kernel

debug:
	$(QEMU_DIR)/qemu-system-arm  -M stm32-p103 -s -S -kernel $(BUILD_DIR)/crypto.elf

clean:
	cd cryptostick.oath/firmware/build/gcc && \
	make clean

