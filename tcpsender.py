import socket

host = '192.168.1.67'
port = 5000                   # The same port as used by the server
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(host, port)
s.sendall('Hello, world')
data = s.recv(1024)
s.close()
print('Received', repr(data))
