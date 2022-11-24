import socket
import sys


alphabet = "abcdefghijklmnopqrstuvwxyz "

letter_to_index = dict(zip(alphabet, range(len(alphabet))))
index_to_letter = dict(zip(range(len(alphabet)), alphabet))


def decrypt(cipher, key):
    decrypted = ""
    split_encrypted = [
        cipher[i : i + len(key)] for i in range(0, len(cipher), len(key))
    ]

    for each_split in split_encrypted:
        i = 0
        for letter in each_split:
            number = (letter_to_index[letter] - letter_to_index[key[i]]) % len(alphabet)
            decrypted += index_to_letter[number]
            i += 1

    return decrypted




server_socket= socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server_socket.bind(('127.0.0.1',12345))
server_socket.listen(5)#5 is a backlog parameter, upto 5 connections can wait if the server is busy

while True:
    print("Server waiting for connection")
    client_socket,addr=server_socket.accept()
    print("client connected from:",addr)
    while True:
        data=client_socket.recv(1024)
        if not data or data.decode('utf-8') == 'END':#in case data not recv or end of data recv
            print("not recieved")
            break
        print("recived from client: %s"% data.decode("utf-8"))
        encrypted_message = data.decode("utf-8")
        ch = input("1- server enters the key 2- key was appeneded to the message?")
        ch=int(ch)
        if ch == 1:
            keyword=input("enter the key used for encrypting:")
            plain_text = decrypt(encrypted_message, keyword)
            print("Decrypted message is:",plain_text)
        elif ch == 2:
            len_of_key = input("enter the lenght of the key used")
            len_of_key = int(len_of_key)
            itr = -len_of_key
            keyword=""
            while itr<=-1:
                keyword+=encrypted_message[itr]
                itr=itr+1
            encrypted_message = encrypted_message.replace(keyword,"")
            plain_text = decrypt(encrypted_message, keyword)
            print("Decrypted message is:",plain_text)
    #     try:
    #         sending_data=input("Enter data to send to the server")
    #         client_socket.send(bytes(sending_data,'utf-8'))#send sends bytes so converting str to bytes
    #     except:
    #         print("exited by user")
    client_socket.close()
server_socket.close()

