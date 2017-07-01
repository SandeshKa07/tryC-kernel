#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/list.h>
#include <linux/fs.h>
#include <linux/usb.h>
#include <linux/mod_devicetable.h>
#include <linux/device.h>

static struct usb_device_id eudy_usb_id_table [] = {
	/*vendorID=0x413c for DELL, productID=0x2003 for DELL keyboard */
	{USB_DEVICE(0x1a2c, 0x0002)},

	/* Interfaceclass = 3, Boot interface subclass = 1, Keyboard = 1 */
	{USB_INTERFACE_INFO(3,1,1)},

	/*Terminating  entry */
	{}
};
MODULE_DEVICE_TABLE (usb, eudy_usb_id_table);

static int eudy_usb_driver_probe (struct usb_interface *intf,
				  const struct usb_device_id *id) {

	printk("Hello world Module: USB driver is probed");
	return 0;
}

static void eudy_usb_driver_disconnect(struct usb_interface *intf) {
        printk("Hello world Module: USB keyboard detached\n");
}

static struct usb_driver my_usb_driver = {
	.name           = "eudy usb driver",
	.id_table       = eudy_usb_id_table,
	.probe          = eudy_usb_driver_probe,
	.disconnect     = eudy_usb_driver_disconnect,
};

static int __init usb_driver_init(void) {
	int result;

	/* register my eudy usb driver with the USB subsystem */
	result = usb_register(&my_usb_driver);
	if(result)
		pr_debug("usb_register failed. Error number %d\n", result);

	printk("\nHello World Module: USB keyboard is plugged\n");
	return result;
}

static void __exit usb_driver_exit(void) {
	usb_deregister(&my_usb_driver);
	printk("\nHello World Module: Good bye !\n");
}

module_init(usb_driver_init);
module_exit(usb_driver_exit);
MODULE_AUTHOR("Sandesh K A");
MODULE_LICENSE("GPL");
