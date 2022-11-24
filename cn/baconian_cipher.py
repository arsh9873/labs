
dc = {'A': 'aaaaa', 'B': 'aaaab', 'C': 'aaaba', 'D': 'aaabb', 'E': 'aabaa',
		'F': 'aabab', 'G': 'aabba', 'H': 'aabbb', 'I': 'abaaa', 'J': 'abaab',
		'K': 'ababa', 'L': 'ababb', 'M': 'abbaa', 'N': 'abbab', 'O': 'abbba',
		'P': 'abbbb', 'Q': 'baaaa', 'R': 'baaab', 'S': 'baaba', 'T': 'baabb',
		'U': 'babaa', 'V': 'babab', 'W': 'babba', 'X': 'babbb', 'Y': 'bbaaa', 'Z': 'bbaab'}
def encrypt(string):
	enc = ''
	for alph in string:
		
		if(alph != ' '):
			
			enc += dc[alph]
		else:
			
			enc += ' '

	return enc


def decrypt(string):
	dec = ''
	i = 0

	
	while True:
		
		if(i < len(string)-4):
			
			substr = string[i:i + 5]
			
			if(substr[0] != ' '):
				
				dec += list(dc.keys())[list(dc.values()).index(substr)]
				i += 5 

			else:
				
				dec += ' '
				i += 1
		else:
			break 

	return dec


def main():
	string = input("Enter plaintext to encrypt")
	res = encrypt(string.upper())
	print("the encrypted string is",res)
	res = decrypt(res.lower())
	print("the decrypted string is",res.lower())

if __name__ == '__main__':
	main()
