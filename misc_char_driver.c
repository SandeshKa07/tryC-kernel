#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <asm/uaccess.h>
#include <linux/fs.h>
#include <linux/printk.h>

static const char assignID[] = "a89cef62eae7\n";
static const ssize_t size_assignID = sizeof(assignID);

static ssize_t my_misc_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
	pr_info("misc-driver: Device file read at offset=%i, read bytes  =%u\n",
		(int)*ppos, (unsigned int)count);

	if( *ppos >= size_assignID )
		return 0;

	if( *ppos + count > size_assignID )
		count = size_assignID - *ppos;
	
	if(copy_to_user(buffer, assignID + *ppos, count) != 0)
		return -EFAULT;

	*ppos +=count;
	return count;
}

static ssize_t my_misc_write(struct file *file, const char __user *buffer, size_t count, loff_t *ppos)
{
	char writebuffer[size_assignID];
	pr_info("\nwritebuffer value is %s\n", writebuffer);

	if(copy_from_user(writebuffer, assignID, count) != 0)
		return -EFAULT;

	pr_info("\nwritebuffer value is %s\n", writebuffer);
	
	if (strncmp(writebuffer,assignID, size_assignID) != 0)
		return -EINVAL;

	return 0;
}

const static struct file_operations my_misc_fops = {
	.read = my_misc_read,
	.write = my_misc_write,
};

static struct miscdevice my_misc_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "eudyptula",
	.fops = &my_misc_fops,
};

static int __init my_misc_init(void)
{
	int error;
	error = misc_register(&my_misc_device);
	if(error)
	{
		pr_err("\n Error Registering the misc device\n");
		return error;
	}
	return 0;
}
       
static void __exit my_misc_exit(void)
{
	misc_deregister(&my_misc_device);
	pr_info("Good Bye\n");
}

module_init(my_misc_init);
module_exit(my_misc_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sandesh K A");
