import socket
 
def server_program():
    # get the hostname
    host = socket.gethostname()
    port = 9000  # initiate port no above 1024
 
    server_socket = socket.socket()  # get instance
    # look closely. The bind() function takes tuple as argument
    server_socket.bind((host, port))  # bind host address and port together
 
    # configure how many client the server can listen simultaneously
    server_socket.listen(2)
    conn, address = server_socket.accept()  # accept new connection
    print("Connection from: " + str(address))
    while True:
        #receive data stream. it won't accept data packet greater than 1024 bytes
        data = conn.recv(1024).decode()
        if not data:
            #if data is not received break
            break
        print("\n")
        print("from connected user: " + str(data))       
        data=str(data)
        count=int(len(data))
        alpha_count=0
        num_count=0
        data = str(data)
        for i in data:
            if(i.isalpha()):
                print(i,":alphabet")
                alpha_count+=1
            elif(i.isnumeric()):
                print(i,":number")
                num_count+=1
            elif(i == " "):
                print("space")
            else:
                print(i,":special character")
        print('characters received from server: ', count)
        print("number of alphabets:",alpha_count)
        print("number of numbers in the string:",num_count)
 
        #data = input(' -> ')
        #conn.send(data.encode())  # send data to the client
 
    conn.close()  # close the connection
 
 
if __name__ == '__main__':
   server_program()