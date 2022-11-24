import socket
alphabet = "abcdefghijklmnopqrstuvwxyz "

letter_to_index = dict(zip(alphabet, range(len(alphabet))))
index_to_letter = dict(zip(range(len(alphabet)), alphabet))

def encrypt(message, key):
    encrypted = ""
    split_message = [
        message[i : i + len(key)] for i in range(0, len(message), len(key))
    ]

    for each_split in split_message:
        i = 0
        for letter in each_split:
            number = (letter_to_index[letter] + letter_to_index[key[i]]) % len(alphabet)
            encrypted += index_to_letter[number]
            i += 1

    return encrypted

client_socket=socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client_socket.connect(('127.0.0.1',12345))
try:
    while True:
        string = input("Enter the message:")
        keyword  = input("Enter the key:")
        ch = int(input("1-server enters key? 2-append key to message"))
        payload = encrypt(string , keyword)
        if ch==1:
            print("the payload being sent is",payload)
            client_socket.send(payload.encode('utf-8'))
        # data=client_socket.recv(1024)
        # # print(str(data))
        elif ch==2:
            payload = payload + keyword
            print("the payload being sent is",payload)
            client_socket.send(payload.encode('utf-8'))     
        more=input("want to send again ?")
        if more.lower()!="y":
            break
except KeyboardInterrupt:
    print("exited by the user")
client_socket.close()


    