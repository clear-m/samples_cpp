#include <iostream>
#include <upnp/upnp.h>
#include <upnp/upnptools.h>

void search_devices()
{
    int ret = UpnpInit2(NULL, 0);
    if (ret != UPNP_E_SUCCESS)
    {
        std::cerr << "Failed to initialize UPnP library: " << ret << std::endl;
        return;
    }
    UpnpClient_Handle client = UpnpSearchAsync(0, 5, "ssdp:all", "ssdp:all");
    if (client < 0)
    {
        std::cerr << "Failed to start search" << std::endl;
        UpnpFinish();
        return;
    }
    UpnpFinish();
}

// INFO: required  "sudo apt install libupnp-dev"
int main(int argc, char **argv)
{
    search_devices();
    return 0;
}
