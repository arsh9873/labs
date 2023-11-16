import math
import matplotlib.pyplot as plt
import numpy as np

def classifyAPoint(points,p,k=3):
	'''
	This function finds the classification of p using
	k nearest neighbor algorithm. It assumes only two
	groups and returns 0 if p belongs to group 0, else
	1 (belongs to group 1).

	Parameters - 
		points: Dictionary of training points having two keys - 0 and 1
				Each key have a list of training data points belong to that 

		p : A tuple, test data point of the form (x,y)

		k : number of nearest neighbour to consider, default is 3 
	'''

	distance=[]
	for group in points:
		for feature in points[group]:

			euclidean_distance = math.sqrt((feature[0]-p[0])**2 +(feature[1]-p[1])**2)

			distance.append((euclidean_distance,group))

	distance = sorted(distance)[:k]

	freq1 = 0 
	freq2 = 0 

	for d in distance:
		if d[1] == 0:
			freq1 += 1
		elif d[1] == 1:
			freq2 += 1

	return 0 if freq1>freq2 else 1

# driver function
def main():

        points = {0:[(1,12),(2,5),(3,6),(3,10),(3.5,8),(2,11),(2,9),(1,7)],1:[(5,3),(3,2),(1.5,9),(7,2),(6,1),(3.8,1),(5.6,4),(4,2),(2,5)]}
        p1  =   [(1,12),(2,5),(3,6),(3,10),(3.5,8),(2,11),(2,9),(1,7)]
        p2  =   [(5,3),(3,2),(1.5,9),(7,2),(6,1),(3.8,1),(5.6,4),(4,2),(2,5)]
        # testing point p(x,y)
        p = (5,2)

        # Number of neighbours 
        k = 5

        
        xpoints1 = [i[0] for i in p1]
        ypoints1 = [i[1] for i in p1]
        xpoints2 = [i[0] for i in p2]
        ypoints2 = [i[1] for i in p2]
        plt.scatter(xpoints1,ypoints1,marker="*",color="green")
		# group 0 is green and *
        plt.scatter(xpoints2,ypoints2,marker="o",color="red")
        # group 1 is red and o
        plt.plot(p[0],p[1],marker="v",color="blue")
        plt.show()
        print("The value classified to unknown point is: {}".\
            format(classifyAPoint(points,p,k)))

        
if __name__ == '__main__':
        main()
