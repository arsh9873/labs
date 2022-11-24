# code for the client side
 
import socket
 
 

def client_program():
    host = socket.gethostname()  
    port = 8000  
 
    client_socket = socket.socket()  
    client_socket.connect((host, port))  
   
    
    ch = "y"
    while ch.lower() == "y":
        message = input(" Enter Plaintext: ")
        client_socket.send(message.encode())  
        data = client_socket.recv(1024).decode()  
        print("\n")
        print('Received from server: ' + data)  
        ch=input("Want to send Again")
    client_socket.close()  
 
 
if __name__ == '__main__':
    client_program()
