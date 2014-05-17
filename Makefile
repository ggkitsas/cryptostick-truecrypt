ROOT=$(CURDIR)
GNUK=$(ROOT)/gnuk-1.1.2
J=2

setup:
	# fetch CS firmware
	# fetch truecrypt
	# fetch gnuk

gnuk:
	cd $(GNUK)/src && \
	./configure --vidpid=234b:0000 --target=OLIMEX_STM32_H103 && \
	make -j$(J)

gnuk-flash:
	cd $(GNUK) && \
	cp src/build/gnuk.elf . && \
	sudo openocd -f interface/stlink-v2.cfg -f board/olimex_stm32_h103.cfg -f tool/openocd-script/write.tcl
	
truecrypt:
	cd $(TC) && \
	make truecrypt

firmware:
	cd $(CS) && \
	make all	

firmware-flash:

openocd:

clean:
	cd $(TC) && make clean
	cd $(CS) && make clean
