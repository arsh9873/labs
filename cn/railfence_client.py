# code for the client side
 
import socket
 
#num of collums = len(text)
#num of rows =3

def encrypted(text, key):
 
    
    rail = [['\n' for i in range(len(text))]
                  for j in range(key)]
     
    dir_down = False
    row, col = 0, 0
     
    for i in range(len(text)):
         
        if (row == 0) or (row == key - 1):
            dir_down = not dir_down
         
        rail[row][col] = text[i]
        col += 1
         
        if dir_down:
            row += 1
        else:
            row -= 1
    result = []
    for i in range(key):
        for j in range(len(text)):
            if rail[i][j] != '\n':
                result.append(rail[i][j])
    return("" . join(result))

def client_program():
    host = socket.gethostname()  
    port = 8001  
 
    client_socket = socket.socket()  
    client_socket.connect((host, port))  
   
    
    ch = "y"
    while ch.lower() == "y":
        message = input(" Enter Plaintext: ")
        key = int(input("enter the key"))
        enc = encrypted(message,key)
        print("\nthe message being sent is",enc)
        client_socket.send(enc.encode())  
        # data = client_socket.recv(1024).decode()  
        # print("\n")
        # print('Received from server: ' + data)  
        ch=input("Want to send Again")
    client_socket.close()  
 
 
if __name__ == '__main__':
    client_program()
