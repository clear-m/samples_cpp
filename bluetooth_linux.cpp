#include <iostream>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <unistd.h>

// INFO: https://affix.sourceforge.net/affix-doc/x496.html
// INFO: required LDFLAGS=-lbluetooth and "sudo apt-get install bluez libbluetooth-dev"
#define BLUETOOTH_NAME_MAX_LENGTH_BYTES 248 /* Bluetooth user-friendly name length limit */

int main(int argc, char **argv)
{
	inquiry_info *ii = nullptr;
	int max_rsp, num_rsp;
	int dev_id, sock, len;
	char addr[19] = {0};
	char name[BLUETOOTH_NAME_MAX_LENGTH_BYTES] = {0};

	dev_id = hci_get_route(nullptr);
	if (dev_id < 0)
	{
		perror("Device is not available.\n");
		return 1;
	}
	sock = hci_open_dev(dev_id);
	if (sock < 0)
	{
		perror("Failed to open device\n");
		return 1;
	}
	len = 8;	   // длина поиска
	max_rsp = 255; // максимальное количество устройств

	ii = new inquiry_info[max_rsp];

	num_rsp = hci_inquiry(dev_id, len, max_rsp, nullptr, &ii, IREQ_CACHE_FLUSH);
	if (num_rsp < 0)
	{
		perror("hci_inquiry failed");
		return 1;
	}
	num_rsp = num_rsp;
	for (int i = 0; i < num_rsp; i++)
	{
		ba2str(&ii[i].bdaddr, addr);
		hci_read_remote_name(sock, &ii[i].bdaddr, sizeof(name), name, 0);
		std::cout << "Device found: " << addr << " " << name << std::endl;
	}

	delete[] ii;
	close(sock);
	return 0;
}
