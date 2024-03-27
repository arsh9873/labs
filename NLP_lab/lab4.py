# maximum matching segmentation algorithm for text
# theca will be considered as a word
# has to convert all words to lowercase first
import nltk
nltk.download('words')
from nltk.corpus import words

string = "The sky is clear today, with its vibrant stretch in horizon. As I sat on the tranquil riverbank, the gentle rustle trees add serenity of the moment. In the distance, I can see a solitary yacht sailing gracefully, its white sails billowing in the breeze. It is a perfect day for a leisurely stroll, feeling the warmth of the sun on my skin and the soft touch of the gentle breeze. Truly, nature beauty knows no bounds"
string=string.lower()
string=string.replace(".","")
string=string.replace(",","")
string=string.replace(" ","")
print(string)

tokens = []
lowercaseCorpus = [x.lower() for x in words.words()]

CorpusSet = set(lowercaseCorpus)  # Convert list to set

i = 0
while i < len(string):
    maxWord = ""
    for j in range(i, len(string)):
        tempWord = string[i:j+1]
        if tempWord in CorpusSet and len(tempWord) > len(maxWord):
            maxWord = tempWord
    i = i+len(maxWord)
    tokens.append(maxWord)
    # print(maxWord)
print(tokens)