#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>


static int count = 1;
static char *pstring = "hello";

module_param(count, int, S_IRUGO);
module_param(pstring, charp, S_IRUGO);


static int __init hello_init(void)
{
	int i = 0;

	printk("Hello Module Init\n");

	printk("count = %d\n", count);
	printk("pstring = %s\n", pstring);


	for (i = 0; i < count; i++)
	{
		printk("[%d]:%s\n", i + 1, pstring);
	}

	return 0;
}


static void __exit hello_exit(void)
{
	printk("Hello Module Exit\n");
}


module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
