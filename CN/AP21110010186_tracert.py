#AP21110010186 - Adi Vishnu Avula

import scapy.all as scapy

def custom_traceroute(destination, max_hops=30):
    for ttl in range(1, max_hops + 1):        
        packet = scapy.IP(dst=destination, ttl=ttl) / scapy.ICMP()
        reply = scapy.sr1(packet, verbose=False, timeout=1)
        if reply is None:
            print(f"{ttl}\t-")
        else:
            print(f"{ttl}\t{reply.src}")
            if reply.src == destination:
                break

destination = input("Enter the destination IP address: ")

custom_traceroute(destination)