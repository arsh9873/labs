from numpy.linalg import norm
from numpy import dot

def cosine_similarity(a, b):
  return dot(a, b)/(norm(a)*norm(b))

ignore_characters = [char for char in '.,/?<>;{[]}|\\+=–-_!@#$%^&*()\n']

stopWords = []
with open('inputs/stopWords.txt', 'r') as stopWords_file:
  for row in stopWords_file:
    stopWords.append(row.rstrip('\n\r'))
  stopWords_file.close()

def getWordList (fileName: str):
  words = set()
  with open(fileName, 'r') as input_file:
    for word in input_file.read().split():
      if word.lower() in stopWords: continue
      if word.lower() in ignore_characters: continue
      words.add("".join([c.lower() for c in word if c not in ignore_characters]))
    input_file.close()
  return words

docs = [f"inputs/{i}.txt" for i in range(1, 6)]
all_words = set()
words_doc_wise = []

# get all words from each document using getworldlist func
for file in docs:
  words = getWordList(file)
  words_doc_wise.append(words)
  for word in words:
    all_words.add(word)

def check_present(key: str, words_list: list[str]) -> bool:
  for word in words_list:
    if (key == word): return True
  return False

# creating frequency vectors for each doc 
frequency_vector = []
for i in range(len(docs)):
	frequency_arr = []
	for word in all_words:
		if (check_present(word, words_doc_wise[i])): frequency_arr.append(1)
		else: frequency_arr.append(0)
	frequency_vector.append(frequency_arr)
   

# then calculate cosine similarites between each frequency vector
cosine_similarities = []
for i in range(4):
  temp = []
  for j in range(i+1, 5):
    temp.append(cosine_similarity(frequency_vector[i], frequency_vector[j]))
    cosine_similarities.append(temp)

for i in range(4):
  for j in range(i + 1, 5):
    similarity = cosine_similarities[i][j - (i + 1)]
    print(f"Similarity b/w Doc {i+1} & Doc {j+1}: {similarity:.4f}")    