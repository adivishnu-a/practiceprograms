# AP21110010186 - Adi Vishnu Avula

import sys
import time
from ping3 import ping, verbose_ping

def main():
    if len(sys.argv) != 2:
        print("Usage: python ping.py <hostname or IP>")
        sys.exit(1)

    target_host = sys.argv[1]

    try:
        while True:
            response_time = ping(target_host)
            if response_time is not None:
                print(f"Response from {target_host}: time={response_time}ms")
            else:
                print(f"No response from {target_host}")
            time.sleep(1)
    except KeyboardInterrupt:
        print("\nPing program terminated.")

if __name__ == "__main__":
    main()