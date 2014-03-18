ROOT_DIR=$(CURDIR)
#WXWIDGETS_DIR=$(ROOT_DIR)/wxWidgets-3.0.0
WXWIDGETS_DIR=$(ROOT_DIR)/wxGTK-2.8.12
TRUECRYPT_DIR=$(ROOT_DIR)/truecrypt-7.1a-source

setup:
	sudo apt-get install libgtk2.0-dev nasm libfuse-dev
	wget http://downloads.sourceforge.net/project/wxwindows/3.0.0/wxWidgets-3.0.0.tar.bz2
	tar -xvf wxWidgets-3.0.0.tar.bz2
	mkdir -p $(HOME)/src/pkcs-11
	wget 'ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-11/v2-20/pkcs11*' -P $(HOME)/src/pkcs-11
	# Download manually truecrypt sources

wxwidgets:
	cd $(TRUECRYPT_DIR) && \
        make -j$(J) WX_ROOT=$(WXWIDGETS_DIR) wxbuild

truecrypt: wxwidgets
	cd $(TRUECRYPT_DIR) && \
	make -j$(J) PKCS11_INC=$(HOME)/src/pkcs-11

