ans = 1234
i=0
while True:
    pin = int(input("Enter the pin : "))
    if pin==ans:
        print("You have successfully logged in")
        break
    else:
        if i<3:
            print("Wrong pin, You have", (3-i), "chances left")
            i+=1
            continue
        else:
            print("Your Access card blocked, try after 24 hours")
            break
