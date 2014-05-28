ROOT=$(CURDIR)
GNUK=$(ROOT)/gnuk-1.1.2
J=2

truecrypt:
	cd $(TC) && \
	make truecrypt

truecrypt-cmd-only:
	
	
clean:
	cd $(TC) && make clean
