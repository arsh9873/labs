# code for the client side
 
import socket
 
 
def encrypted(message,key):
    enc=""
    for char in message:
        if(char.isalpha() == False):
            enc=enc+char
            continue
        if(ord(char)<=90 and ord(char)>=65):
            if((ord(char)+key))>90 :
                char = chr(((ord(char)+key)%91 +65))
            else:
                char = chr(ord(char)+key)    
        elif(ord(char)<=122 and ord(char)>=97):
            if((ord(char)+key))>122 :
                char = chr((ord(char)+key)%123 +97)
            else:
                char = chr(ord(char)+key)  
        enc=enc+char
    return enc

def client_program():
    host = socket.gethostname()  
    port = 8000  
 
    client_socket = socket.socket()  
    client_socket.connect((host, port))  
   
    
    ch = "y"
    while ch.lower() == "y":
        message = input(" Enter Plaintext: ")
        key = int(input("Enter the key:"))
        payload = encrypted(message,key)
        print("the payload being sent is",payload)
        client_socket.send(payload.encode())  
        print("\n")
       
        ch=input("Want to send Again")
    client_socket.close()  
 
 
if __name__ == '__main__':
    client_program()
