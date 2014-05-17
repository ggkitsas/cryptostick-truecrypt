ROOT_DIR=$(CURDIR)
WXWIDGETS_DIR=$(ROOT_DIR)/wxGTK-2.8.12
TRUECRYPT_DIR=$(ROOT_DIR)/truecrypt-7.1a-source
DEPS=libgtk2.0-dev nasm libfuse-dev opensc libwxgtk2.8-dev
J?=1

#These must be setup from comand line
DEBUG= DEBUG=1 DEBUGGER=1 NOSTRIP=1 VERBOSE=1 NOGUI=1

setup:
	#mkdir pkcs-11
	#wget 'ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-11/v2-20/pkcs11*' -P pkcs-11
	sudo apt-get install $(DEPS)
	wget http://sourceforge.net/projects/wxwindows/files/2.8.12/wxGTK-2.8.12.tar.gz
	tar -xvf wxGTK-2.8.12.tar.gz
	cd $(TRUECRYPT_DIR) && \
	make -j$(J)  WX_ROOT=$(WXWIDGETS_DIR) wxbuild

wxwidgets:
	cd $(TRUECRYPT_DIR) && \
	make -j$(J) WX_ROOT=$(WXWIDGETS_DIR) wxbuild


truecrypt:
	cd $(TRUECRYPT_DIR) && \
	make -j$(J) PKCS11_INC=$(ROOT_DIR)/pkcs-11

#sw-token:
	#sudo apt-get install opencryptoki opencryptoki-dev libopencryptoki0
	# kill pkcsslotd
	# sudo pkcs11_startup
	# Edit /var/lib/opencryptoki/pk_config_data , first line should be the libpkcs11_sw.so
	# run TC and configure pkcs interface library 

clean:
	cd $(TRUECRYPT_DIR) && \
	make clean
