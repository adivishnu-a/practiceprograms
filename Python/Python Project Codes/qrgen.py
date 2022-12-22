import pyqrcode 
import pyqrcode 

# String which represent the QR code 
s = input("Enter the URL to be turned into QR Code : ")
  
# Generate QR code 
url = pyqrcode.create(s) 
  
# Create and save the png file naming it myqrcode.svg
url.svg("myqrcode.svg",scale=8)
print("QR Code generated and saved...")


# SVG file's path
fileName = "myqrcode.svg"

