#AP21110010186 - Adi VIshnu Avula

import subprocess
import platform

def ping_cmd(host):
    if platform.system().lower() == "windows":
        cmd = ["ping", "-n", "4", host]
    else:
        cmd = ["ping", "-c", "4", host]
    try:
        result = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if result.returncode == 0:
            print(result.stdout)
        else:
            print("Ping failed")
    except Exception as e:
        print("An error occurred:", str(e))

if __name__ == "__main__":
    target_host = input("Enter the target website or IP address: ")
    ping_cmd(target_host)