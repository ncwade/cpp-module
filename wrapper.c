#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include "module.h"

static int __init local_init(void)
{
	start_driver("Hello");
	printk(KERN_INFO "cpp module installed\n");
	return 0;
}

static void __exit local_exit(void)
{
	stop_driver();
	printk(KERN_INFO "cpp module removed\n");
}

module_init(local_init);
module_exit(local_exit);
MODULE_LICENSE("GPL");
