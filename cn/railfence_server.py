# code for the server side
 
import socket
def decrypted(cipher, key):

    rail = [['\n' for i in range(len(cipher))]
                  for j in range(key)]
     
  
    dir_down = None
    row, col = 0, 0
  
    
    for i in range(len(cipher)):
        if row == 0:
            dir_down = True
        if row == key - 1:
            dir_down = False
         
        
        rail[row][col] = '*'
        col += 1
       
        if dir_down:
            row += 1
        else:
            row -= 1
    
    index = 0
    for i in range(key):
        for j in range(len(cipher)):
            if ((rail[i][j] == '*') and
               (index < len(cipher))):
                rail[i][j] = cipher[index]
                index += 1
         
    
    result = []
    row, col = 0, 0
    for i in range(len(cipher)):
         
      
        if row == 0:
            dir_down = True
        if row == key-1:
            dir_down = False
             
       
        if (rail[row][col] != '*'):
            result.append(rail[row][col])
            col += 1
        
        if dir_down:
            row += 1
        else:
            row -= 1
    return("".join(result))

def server_program():

    host = socket.gethostname()
    port = 8001  
 
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
        print("encrypted message received: " + str(data))       
        key = int(input("\nenter the key used:"))
        dec = decrypted(str(data),key)
        print("decrypted message:",dec)

        # data = input(' -> ')
        # conn.send(data.encode())  
 
    conn.close()   
 
 
if __name__ == '__main__':
   server_program()
