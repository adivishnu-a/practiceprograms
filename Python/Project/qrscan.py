import webbrowser
from pyzbar.pyzbar import decode
from PIL import Image
decocdeQR = decode(Image.open('code.png'))
url = decocdeQR[0].data.decode('ascii')
webbrowser.open(url)