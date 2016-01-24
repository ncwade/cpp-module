#####################
# Makefile
#####################
obj-m += cpp-module.o
cpp-module-objs := wrapper.o module.o kernel_interface.o
list-multi := cpp-module.o
LINUX := $(shell uname -r)

all: module.o module
module:
	make -C /lib/modules/$(LINUX)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(LINUX)/build M=$(PWD) clean
module.o : module.cpp kernel_interface.h module.h
	g++ -c -o $@ -mcmodel=kernel -fpermissive -fno-builtin -fno-exceptions -fno-rtti -nostdinc $<
