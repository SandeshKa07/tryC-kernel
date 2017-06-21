#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/slab.h>
#include <asm/uaccess.h>
#include <asm/types.h>

struct proc_dir_entry *proc;
static const struct file_operations proc_fops;

int len=0,temp=0;
char *msg;
char *proc_node_name = "hello";

static ssize_t example_read_proc(struct file *filp,char *buf,size_t count,loff_t *offp ) 
{
	char *data;
	int rv = 0;
	data=PDE_DATA(file_inode(filp));
	if(!(data)) {
		printk(KERN_INFO "Null data");
		return 0;
	}

	if(count>temp) {
		count=temp;
	}
	temp=temp-count;

	rv = copy_to_user(buf,data, count);

	if(count==0)
		temp=len;

	return count;
}

static const struct file_operations proc_fops = {
	.read = example_read_proc
};

static void create_proc_entry(void) {
	msg="Hello World\n";
	proc=proc_create_data(proc_node_name,0,NULL,&proc_fops,msg);
	len=strlen(msg);
	temp=len;
}

static int __init proc_init (void) {
	create_proc_entry();
       	return 0;
}

void __exit proc_cleanup(void) {
	remove_proc_entry(proc_node_name,NULL);
}

module_init(proc_init);
module_exit(proc_cleanup);
MODULE_AUTHOR("Sandesh K A");
MODULE_LICENSE("GPL"); 
