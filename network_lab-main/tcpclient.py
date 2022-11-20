#socket-connect-send-recv-close
import socket
client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1',12345))
#payload to be sent to the server
try:
    while True:
        payload=input("Enter payload 1st:")
        client_socket.send(payload.encode('utf-8'))#send needs utf-8 dat
        data=client_socket.recv(1024)#takes at most 1024 bytes
        print(str(data))
        more=input("want to send data to server?")
        if more.lower()=="y":
            payload=input("Enter payload")
        else:
            break
except KeyboardInterrupt:
    print("exited by the user")
client_socket.close()


    