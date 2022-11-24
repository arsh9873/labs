import socket
 
 
def client_program():
    host = socket.gethostname()  # as both code is running on same pc
    port = 9000  # socket server port number
 
    client_socket = socket.socket()  # instantiate
    client_socket.connect((host, port))  # connect to the server
 
    ch="y"
    while ch.lower() == "y":
        message = input("Enter message to send")  
        client_socket.send(message.encode())  # send message
        # data = client_socket.recv(1024).decode()  # receive response
        print("\n")
        # print('Received from server: ' + data)  # show in terminal
        # count=int(len(data))
        # alpha_count=0
        # num_count=0
        # data = str(data)
        # for i in data:
        #     if(i.isalpha()):
        #         alpha_count+=1
        #     elif(i.isnumeric()):
        #         num_count+=1
        
        # print('characters received from server: ', count)
        # print("number of alphabets:",alpha_count)
        # print("number of numbers in the string:",num_count)
        ch = input("want to send again?")

    client_socket.close()  # close the connection
 
 
if __name__ == '__main__':
    client_program()