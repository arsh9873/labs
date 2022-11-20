#socket-bind-listen-accept-recv-send-recv-send-...close
import socket
import sys
server_socket= socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1',12345))
server_socket.listen(5)#5 is a backlog parameter, upto 5 connections can wait if the server is busy

while True:
    print("Server waiting for connection")
    client_socket,addr=server_socket.accept()
    print("client connected from ",addr)
    while True:#to get and send data to client
        data=client_socket.recv(1024)
        if not data or data.decode('utf-8') == 'END':#in case data not recv or end of data recv
            break
        print("recived from client: %s"% data.decode("utf-8"))
        try:
            sending_data=input("Enter data to send to the server")
            client_socket.send(bytes(sending_data,'utf-8'))#send sends bytes so converting str to bytes
        except:
            print("exited by user")
    client_socket.close()
server_socket.close()