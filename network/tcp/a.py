import socket
import time
import threading

s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

s.connect(('112.150.253.39',1234))

def sending_data():
    while 1:
        s.sendall('A'*2000)
        print(s.recv(2048))
        time.sleep(0.1)

th = threading.Thread(target=sending_data)
th.start()

a = raw_input("?")
if a == 'q':
    th.stop()

s.close()
