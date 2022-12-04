import time
from plyer import notification

if __name__ == "__main__":
    i=0
    while True:
        if i%5==0:
            notification.notify(
                title = "ALERT!!!",
                message = "Take a break! It has been "+str(i)+" seconds!",
                timeout = 5
            )
        time.sleep(1)
        i=i+1