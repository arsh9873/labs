

from langchain.retrievers import WikipediaRetriever
import re

# sklearn matrix implementation

retriever = WikipediaRetriever()

# Queries for retrieving documents
query = ["UFC", "IPL", "FIFA", "GATE", "UPSC"]

def remove_special_characters(text):
    # Use regex to remove non-alphanumeric characters
    cleaned_text = re.sub(r'[^a-zA-Z0-9\s]', '', text)
    return cleaned_text

# List to store cleaned documents
docs = []

# Retrieve and preprocess documents
for q in query:
    doc = retriever.get_relevant_documents(query=q)[0]
    no_spec = remove_special_characters(doc.dict()["page_content"])
    docs.append(no_spec)

# Display the number of documents retrieved
lengthfdocs=len(docs)
print("Documents - ",lengthfdocs)

# Function to create unigram count matrix
def create_unigram_count_matrix(corpus):
    tokens = [document.split() for document in corpus]

    # Create a vocabulary of unique words
    vocabulary = list(set(word for document in tokens for word in document))

    # Initialize the count matrix
    count_matrix = [[0] * len(vocabulary) for _ in range(len(corpus))]

    # Populate the count matrix with word counts
    for i, document in enumerate(tokens):
        for word in document:
            if word in vocabulary:
                count_matrix[i][vocabulary.index(word)] += 1

    return count_matrix, vocabulary

# Generate unigram count matrix and vocabulary
unigram_count_matrix, vocabulary = create_unigram_count_matrix(docs)

print("Unigram Count Matrix:")
for row in unigram_count_matrix:
    print(row)

print("\nVocabulary:")
print(vocabulary)

# Function to create bigram count matrix
def create_bigram_count_matrix(corpus):
    # Tokenize the corpus into words
    tokens = [document.split() for document in corpus]

    # Generate bigrams from tokens
    bigrams = [tuple(tokens[i][j:j+2]) for i in range(len(tokens)) for j in range(len(tokens[i]) - 1)]

    # Create a vocabulary of unique bigrams
    vocabulary = list(set(bigrams))

# intialize count matrix
    count_matrix = [[0] * len(vocabulary) for _ in range(len(corpus))]

    # Populate the count matrix with bigram counts
    for i, document in enumerate(tokens):
        document_bigrams = [tuple(document[j:j+2]) for j in range(len(document) - 1)]
        for bigram in document_bigrams:
            if bigram in vocabulary:
                count_matrix[i][vocabulary.index(bigram)] += 1

    return count_matrix, vocabulary


# Generate bigram count matrix and vocabulary
bigram_count_matrix, vocabulary = create_bigram_count_matrix(docs)

print("Bigram Count Matrix:")
for row in bigram_count_matrix:
    print(row)

print(f"\nvocabulary of len : {len(vocabulary)}")
print(vocabulary)

import math

# Function to calculate term frequency in a document
def calculate_term_frequency(document):
    term_frequency = {}
    total_terms = len(document)

    # Count occurrences of each term in the document
    for term in document:
        term_frequency[term] = term_frequency.get(term, 0) + 1

    # Normalize term frequencies
    for term, count in term_frequency.items():
        term_frequency[term] = count / total_terms

    return term_frequency

# Function to calculate inverse document frequency for a term
def calculate_inverse_document_frequency(corpus, term):
    document_count = sum(1 for document in corpus if term in document)
    if document_count > 0:
        return math.log(len(corpus) / document_count)
    else:
        return 0.0

# Function to create TF-IDF matrix
def create_tfidf_matrix(corpus):
    # Tokenize the corpus into words
    tokens = [document.split() for document in corpus]

    # Get unique terms (words) from the corpus
    vocabulary = list(set(word for document in tokens for word in document))

    # Initialize TF-IDF matrix
    tfidf_matrix = []

    # Calculate TF-IDF values for each document and term
    for document in tokens:
        tfidf_vector = []
        term_frequency = calculate_term_frequency(document)

        for term in vocabulary:
            tf = term_frequency.get(term, 0)
            idf = calculate_inverse_document_frequency(tokens, term)
            tfidf_vector.append(tf * idf)

        tfidf_matrix.append(tfidf_vector)

    return tfidf_matrix, vocabulary


tfidf_matrix, vocabulary = create_tfidf_matrix(docs)

# Display the TF-IDF matrix and vocabulary
print("TF-IDF Matrix:")
for row in tfidf_matrix:
    print(row)

print("\nVocabulary:")
print(vocabulary)

from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.model_selection import train_test_split
from sklearn import metrics

labels = [0,0,0,1,1]

# Split the data into training and testing sets
matrices = [unigram_count_matrix, bigram_count_matrix, tfidf_matrix]
matrix_labels = ['Unigram', 'Bigram', 'Tf-IDF']

for i in range(3):
    X_train, X_test, y_train, y_test = train_test_split(matrices[i], labels, test_size=0.25, random_state=42)

    classifier = MultinomialNB()
    classifier.fit(X_train, y_train)

    predictions = classifier.predict(X_test)

    accuracy = metrics.accuracy_score(y_test, predictions)
    precision = metrics.precision_score(y_test, predictions)
    recall = metrics.recall_score(y_test, predictions)

    print(f"\n\nPerformance in {matrix_labels[i]} matrix")
    print("Accuracy:", accuracy)
    print("Precision:", precision)
    print("Recall:", recall)