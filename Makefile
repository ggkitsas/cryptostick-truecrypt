ROOT_DIR=$(CURDIR)
#WXWIDGETS_DIR=$(ROOT_DIR)/wxWidgets-3.0.0
WXWIDGETS_DIR=$(ROOT_DIR)/wxGTK-2.8.12
TRUECRYPT_DIR=$(ROOT_DIR)/truecrypt-7.1a-source
DEPS=libgtk2.0-dev nasm libfuse-dev opensc
J?=1

setup:
	#mkdir pkcs-11
	#wget 'ftp://ftp.rsasecurity.com/pub/pkcs/pkcs-11/v2-20/pkcs11*' -P pkcs-11
	sudo apt-get install $(DEPS)
	wget http://sourceforge.net/projects/wxwindows/files/2.8.12/wxGTK-2.8.12.tar.gz
	tar -xvf wxGTK-2.8.12.tar.gz

wxwidgets:
	cd $(TRUECRYPT_DIR) && \
        make -j$(J) WX_ROOT=$(WXWIDGETS_DIR) wxbuild

truecrypt: wxwidgets
	cd $(TRUECRYPT_DIR) && \
	make -j$(J) PKCS11_INC=$(ROOT_DIR)/pkcs-11

