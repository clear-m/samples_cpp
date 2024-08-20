#include <pcap.h>
#include <iostream>

// INFO: required LDFLAGS=-lpcap "sudo apt install libpcap-dev"

void packet_handler(u_char *args, const pcap_pkthdr *header, const u_char *packet)
{
    std::cout << "Captured a packet with length: " << header->len << std::endl;
}

int main(int argc, char **argv)
{
    char err_buff[PCAP_ERRBUF_SIZE];
    pcap_if_t *interfaces = nullptr;
    pcap_if_t *temp = nullptr;
    if (pcap_findalldevs(&interfaces, err_buff) < 0)
    {
        std::cerr << "Error finding device: " << err_buff << std::endl;
        return 1;
    }
    // Выбираем первый интерфейс для захвата
    temp = interfaces;
    std::cout << "Devide found: " << temp->name << std::endl;
    pcap_t *handle = pcap_open_live(temp->name, BUFSIZ, 1, 1000, err_buff);
    if (!handle)
    {
        std::cerr << "Error opening device: " << err_buff << std::endl;
        return 1;
    }
    // Захватываем пакеты
    pcap_loop(handle, 10, packet_handler, nullptr);
    // Закрываем устройство
    pcap_close(handle);
    pcap_freealldevs(interfaces);
    return 0;
}
