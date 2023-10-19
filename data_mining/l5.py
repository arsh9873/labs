import numpy as np
import matplotlib.pyplot as plt

# dataset generation using rand values
np.random.seed(0)
X = np.random.rand(100, 2)
k = 3

# centroids picking from those random values
centroids = X[np.random.choice(X.shape[0], k, replace=False)]

max_iterations = 100

for i in range(max_iterations):
    distances = np.linalg.norm(X[:, np.newaxis, :] - centroids, axis=2)
    labels = np.argmin(distances, axis=1)

    new_centroids = np.array([X[labels == j].mean(axis=0) for j in range(k)])

    if np.all(centroids == new_centroids):
        break

    centroids = new_centroids

print("Final Cluster Centroids:")
print(centroids)

plt.scatter(X[:, 0], X[:, 1], c=labels, cmap='viridis')
plt.scatter(centroids[:, 0], centroids[:, 1], c='red', marker='x', s=100, label='Centroids')
plt.legend()
plt.title(f'K-Means Clustering (k={k})')
plt.show()