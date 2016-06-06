obj-m += hello.o
obj-m += hello_2.o
obj-m += hello_arg.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

