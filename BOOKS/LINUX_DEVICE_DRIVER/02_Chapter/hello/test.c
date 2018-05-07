#include <linux/init.h>
#include <linux/module.h>

static int __init hello_init(void)
{
	printk("Insert Mode:hello world\n");

	return 0;
}

static void __exit hello_exit(void)
{
	printk("Out Mode:hello world\n");
}


module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
