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



//standard headers for LKM's
#include <linux/kernel.h>       //needed for printk()
#include <linux/module.h>       //needed for all modules
#include <linux/init.h>         //needed for macros

#define DRIVER_AUTHOR "Bhargava Narayana <bhargava.naryana@gmail.com"
#define DRIVER_DESC "simple hello world"

//init LKM
static int __init hello_module_init(void)
{
        printk(KERN_EMERG "Hello World!!\n");
        return 0;
}

static void __exit cleanup_hello_module(void)
{
        printk(KERN_EMERG "This is the short life of a LKM\n");
}

module_init(hello_module_init);
module_exit(cleanup_hello_module);

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_SUPPORTED_DEVICE("testdevice");
