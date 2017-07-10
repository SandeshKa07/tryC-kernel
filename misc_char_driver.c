#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/uaccess.h>
#include <linux/fs.h>
#include <linux/printk.h>

#define myassignID "a89cef62eae7"
#define idLen 13

static ssize_t my_misc_read(struct file *file, char __user *buffer,
			    size_t count, loff_t *ppos)
{
	if (*ppos != 0)
		return 0;

	if ((count < idLen) || copy_to_user(buffer, myassignID, idLen))
		return -EFAULT;

	*ppos += count;
	return count;
}

static ssize_t my_misc_write(struct file *file, const char __user *buffer,
			     size_t count, loff_t *ppos)
{
	char wbuffer[idLen];

	if (count != idLen)
		return -EINVAL;

	if (copy_from_user(wbuffer, buffer, count))
		return -EFAULT;

	if (strncmp(myassignID, wbuffer, (idLen - 1)))
		return -EINVAL;

	return count;
}

static const struct file_operations my_misc_fops = {
	.owner = THIS_MODULE,
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

	pr_info("\nHello World\n");
	error = misc_register(&my_misc_device);
	if (error) {
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
