# code for the server side
 
import socket
def decrypted(message,key):
    dec=""
    for char in message:
        if(char.isalpha() == False):
            dec=dec+char
            continue
        if(ord(char)<=90 and ord(char)>=65):
            if((ord(char)-key))<65 :
                char = chr(91-(65-(ord(char)-key)))
            else:
                char = chr(ord(char)-key)    
        elif(ord(char)<=122 and ord(char)>=97):
            if((ord(char)+key))<97 :
                char = chr(123-(97-(ord(char)-key)))
            else:
                char = chr(ord(char)-key)  
        dec=dec+char
    return dec
 
def server_program():

    host = socket.gethostname()
    port = 8000  
 
    server_socket = socket.socket()  
    server_socket.bind((host, port)) 
 

    server_socket.listen(2)
    conn, address = server_socket.accept()   
    print("Connection from: " + str(address))
    while True:
        
        data = conn.recv(1024).decode()
        if not data:

            break
        print("\n")
        print("encrypted message recieved: " + str(data))       
        message = str(data)
        key= int(input("enter the key used"))
        dec = decrypted(message,key)
        print("the Decrypted message is:",dec)
      
 
    conn.close()   
 
 
if __name__ == '__main__':
   server_program()
