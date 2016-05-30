/*hello.c
 *
 *Simple hello world LKM (Loadable Kernel Module)
 *
 *
 * Usage: 
 *      make
 *      insmod hello.ko
 *      dmesg | tail
 *      rmmod hello
 *      dmesg | tail
 */ 


#define __KERNEL__
#define MODULE

//standard headers for LKM's
//#include <linux/modversions.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <linux/tty.h> // console_print() interface

//init LKM
int init_module()
{
        printk(KERN_EMERG "Hello World!!\n");

        return 0;
}

void cleanup_module()
{
        printk(KERN_EMERG "This is the short life of a LKM\n");
}
