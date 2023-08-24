import numpy as np
from numpy.linalg import norm
questions=[
    "where is jmi located",
    "what is the location of jmi",
    "what is the full form of jmi",
    "what are the courses offered in jmi",
    "in which year was jmi established",
    "is jmi central university or state university",
    "who established jmi university",
    "what is the motto of jmi",
    "what is the rank of jmi",
    "what is the ranking of jmi",
    "who is the chancellor of jmi",
    "who is the vice chancellor of jmi"
]


answers=[
    "it is located in delhi",
    "full form of jmi is jamia millia islamia",
    "there are a variety of courses offered in jamia like btech,mba,bba etc",
    "jamia was established in the year 1923",
    "jamia is a central university",
    "mohammed ali jauhar, dr zakir hussain, mahmud hassan deobandi",
    "Taught man what he knew not.",
    "it ranks number 1 on NIRF",
    "Mufaddal Saifuddin",
    "Najma Akhtar"
]


dictofanwers ={
    0:0,
    1:0,
    2:1,
    3:2,
    4:3,
    5:4,
    6:5,
    7:6,
    8:7,
    9:7,
    10:8,
    11:9

}
allwords = []
for sentence in questions:
    splitwords = sentence.split()
    allwords+=splitwords

setofwords = set(allwords)
allwords = (list(setofwords))

dictofvectors = {} #sentenceIDX,binary vector which tells whether a word from the allwords is there or not
cntr=0

# print(allwords,"\n")
# print(len(questions))
for sentence in questions:
    binvector=[]
    # print("words in sentence:{cntr} are:\n",cntr)
    sentencesplit = sentence.split()
    for item in allwords:
        if(item in sentencesplit):
            # print(item)
            binvector.append(1)
        else:
            binvector.append(0)
    dictofvectors[cntr]=binvector
    cntr+=1    

# print("vectors\n")

# for item in dictofvectors:
#     print(item,dictofvectors[item])
#     print("\n")

user_input=input("What is your question:")
splitwords=user_input.split()
userbinvector=[]
for item in allwords:
    if(item in splitwords):
        userbinvector.append(1)
    else:
        userbinvector.append(0)

# print(allwords,"\n")
# print("userbinvector of user input is:\n")
# print(userbinvector)

maxval=0
curridx=-1
for item in dictofvectors:
    vect_A = np.array(userbinvector)
    vect_B = np.array(dictofvectors[item])
    cosine = np.dot(vect_A,vect_B)/(norm(vect_A)*norm(vect_B))
    # print(cosine,"\n")
    if(cosine >= maxval):
        maxval=cosine
        curridx=item
    
if(curridx!=-1):
    print(answers[dictofanwers[curridx]])
else:
    print("no match found")
