ROOT=$(CURDIR)
J=2

truecrypt:
	cd $(TC) && \
	make truecrypt

truecrypt-cmd-only:
	
	
clean:
	cd $(TC) && make clean
