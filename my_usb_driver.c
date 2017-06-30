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
	{USB_DEVICE(0x413c, 0x2003)},

	/* Interfaceclass = 3, Boot interface subclass = 1, Keyboard = 1 */
	{USB_INTERFACE_INFO(3,1,1)},

	/*Terminating  entry */
	{}
};
MODULE_DEVICE_TABLE (usb, eudy_usb_id_table);

static int eudy_usb_driver_probe (struct usb_interface *intf,
				  const struct usb_device_id *id) {

	pr_debug("USB keyboard plugged in and driver got probed");
	return 0;
}

static struct usb_driver my_usb_driver = {
	.name           = "eudy usb driver",
	.id_table       = eudy_usb_id_table,
	.probe          = eudy_usb_driver_probe,
};

static int __init usb_driver_init(void) {
	int result;

	/* register my eudy usb driver with the USB subsystem */
	result = usb_register(&my_usb_driver);
	if(result)
		pr_debug("usb_register failed. Error number %d\n", result);

	pr_debug("\nHello World, usb keyboard is plugged\n");
	return result;
}

static void __exit usb_driver_exit(void) {
	usb_deregister(&my_usb_driver);
	pr_debug("\nGood Bye usb device is removed and i am siging off\n");
}

module_init(usb_driver_init);
module_exit(usb_driver_exit);
MODULE_AUTHOR("Sandesh K A");
MODULE_LICENSE("GPL");
