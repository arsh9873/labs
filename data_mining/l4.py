def uni(s1, s2):
	ans = ''
	i = 0
	j = 0
	while i<len(s1) or j<len(s2):
		if i==len(s1):
			ans += s2[j]
			j += 1
		elif j == len(s2):
			ans += s1[i]
			i += 1
		elif s1[i] < s2[j]:
			ans += s1[i]
			i += 1
		elif s1[i] > s2[j]:
			ans += s2[j]
			j += 1
		else:
			ans += s1[i]
			i += 1
			j += 1
	return ans

TransList = [
    ['A','C','D'],
    ['B','C','E'],
    ['A','B','C','E'],
    ['B','E']]

minSupport=2
C1 = {}
for item in TransList:
    for i in item:
        C1[i]=0

for item in TransList:
    for i in item:
        C1[i]+=1

itemsToBeRemoved = []
for i in C1:
    if(C1[i]<minSupport):
        itemsToBeRemoved.append(i)

for i in itemsToBeRemoved:
    C1.pop(i)


keys=list(C1.keys())
C2={}
startIdx=1
for item in C1:
    for i in range(startIdx,len(keys)):
        newstring = uni(str(item),str(keys[i]))
        C2[newstring]=0
    startIdx+=1

for item in C2:
    toCheck = str(item)
    for i in TransList:
        if(toCheck[0] in i and toCheck[1] in i):
            C2[toCheck]+=1


itemsToBeRemoved.clear()

itemsToBeRemoved = []
for i in C2:
    if(C2[i]<minSupport):
        itemsToBeRemoved.append(i)

for i in itemsToBeRemoved:
    C2.pop(i)

C3={}
keys=list(C2.keys())
startIdx=1
for item in C2:
    for i in range(startIdx,len(keys)):
        newstring = uni(str(item),str(keys[i]))
        C3[newstring]=0
    startIdx+=1

for item in C3:
    toCheck = str(item)
    for i in TransList:
        if(toCheck[0] in i and toCheck[1] in i and toCheck[2] in i):
            C3[toCheck]+=1


itemsToBeRemoved.clear()

itemsToBeRemoved = []
for i in C3:
    if(C3[i]<minSupport):
        itemsToBeRemoved.append(i)

for i in itemsToBeRemoved:
    C3.pop(i)

print(C3)
