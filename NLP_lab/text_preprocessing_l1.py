# take any text from anywhere on the net using web scraping, it will contain html,links,special symbols etc
# word tokenization, sentence tokenization, remove punctuations, lowercase, convert all date and currency symbols to common format
# remove url, remove html, remove stopwords, stemmization, lemmatization, 
import nltk
import string
import re
nltk.download('punkt')
nltk.download('stopwords')
nltk.download('wordnet')
text = """<p><b>Adolf Hitler <sup id="cite_ref-1" class="reference"><a href="#cite_note-1">[a]</a></sup></b> (20 April 1889 to 30 April 1945) 
was an Austrian-born German politician who was the <a href="/wiki/Dictatorship" title="Dictatorship">dictator</a> of 
<a href="/wiki/Nazi_Germany" title="Nazi Germany">Germany</a> from 1933 until <a href="/wiki/Death_of_Adolf_Hitler"
title="Death of Adolf Hitler">his suicide</a> in 1945. <a href="/wiki/Adolf_Hitler_rise_to_power"
title="Adolf Hitler's rise to power">He rose to power</a> as the leader of the <a href="/wiki/Nazi_Party"
title="Nazi Party">Nazi Party</a>,<sup id="cite_ref-3" class="reference"><a href="#cite_note-3">[c]</a></sup>
becoming the <a href="/wiki/Chancellor_of_Germany" title="Chancellor of Germany">chancellor</a> in 1933 and then taking the 
title of <span title="German-language text"><i lang="de"><a href="/wiki/F%C3%BChrer_und_Reichskanzler" class="mw-redirect" 
title="Führer und Reichskanzler">Führer und Reichskanzler</a></i></span> in 1934 .<sup id="cite_ref-6" class="reference">
<a href="#cite_note-6">[d]</a></sup> During his dictatorship, he initiated <a href="/wiki/World_War_II_in_Europe" class="mw-redirect" 
title="World War II in Europe">World War II in Europe</a> by <a href="/wiki/Invasion_of_Poland" title="Invasion of Poland">
invading Poland</a> on 1&nbsp;September 1939 . He was closely involved in military operations throughout the war and was central to 
the perpetration of <a href="/wiki/The_Holocaust" title="The Holocaust">the Holocaust</a>, the <a href="/wiki/Genocide" title="Genocide">
genocide</a> of <a href="/wiki/Holocaust_victims" title="Holocaust victims">about six million Jews and millions of other victims</a>.
</p>"""

text=re.sub(r"[\([{})\]]", "", text)

# converting all to lowercase
text=text.lower()


# define a regular expression pattern to match URLs
pattern = r"(http|ftp|https)://([\w_-]+(?:(?:\.[\w_-]+)+))([\w.,@?^=%&:/~+#-]*[\w@?^=%&/~+#-])?"
# replace URLs with an empty string
text = re.sub(pattern, "", text)


# remove leading and trailing white space
text = text.strip()

# define a regular expression pattern to match HTML tags
html_pattern = r"<[^>]+>"
# replace HTML tags with an empty string
text = re.sub(html_pattern, "", text)
# print("Text without HTML code:", text)


#tokenizer 
tokens = nltk.word_tokenize(text)
# print("Tokens:", tokens)

# remove punctuation words
filtered_tokens = [token for token in tokens if token not in string.punctuation]
# print("Tokens without punctuation:", filtered_tokens)


# get list of stopwords in English
stopwords = nltk.corpus.stopwords.words("english")
# remove stopwords
sfiltered_tokens = [token for token in filtered_tokens if token.lower() not in stopwords]
# print("Tokens without stopwords:", sfiltered_tokens)

# create stemmer object
stemmer = nltk.stem.PorterStemmer()
# stem each token
stemmed_tokens = [stemmer.stem(token) for token in sfiltered_tokens]
# print("Stemmed tokens:", stemmed_tokens)

# create lemmatizer object
lemmatizer = nltk.stem.WordNetLemmatizer()
# lemmatize each token
lemmatized_tokens = [lemmatizer.lemmatize(token) for token in stemmed_tokens]
print("Lemmatized tokens:", lemmatized_tokens)
