import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.cluster import KMeans
from sklearn.metrics import confusion_matrix, accuracy_score
from sklearn.preprocessing import LabelEncoder
from sklearn.cluster import SpectralClustering

# Load the Iris dataset
iris = datasets.load_iris()
X = iris.data
y = iris.target

# Perform KMeans clustering with 3 clusters
kmeans = KMeans(n_clusters=3, random_state=42)
y_kmeans = kmeans.fit_predict(X)

# Perform Spectral Clustering (Normalized Cut-based method) with 3 clusters
spectral = SpectralClustering(n_clusters=3, affinity='nearest_neighbors', random_state=42)
y_spectral = spectral.fit_predict(X)

# Plot KMeans Clustering Results with updated colors
plt.figure(figsize=(8, 6))
plt.scatter(X[y_kmeans == 0, 0], X[y_kmeans == 0, 1], s=100, c='darkorange', label='Cluster 1', marker='o')
plt.scatter(X[y_kmeans == 1, 0], X[y_kmeans == 1, 1], s=100, c='dodgerblue', label='Cluster 2', marker='x')
plt.scatter(X[y_kmeans == 2, 0], X[y_kmeans == 2, 1], s=100, c='forestgreen', label='Cluster 3', marker='^')
plt.scatter(kmeans.cluster_centers_[:, 0], kmeans.cluster_centers_[:, 1], s=200, c='black', marker='*', label='Centroids')
plt.title('KMeans Clustering of Iris Dataset')
plt.xlabel('Sepal length')
plt.ylabel('Sepal width')
plt.legend()
plt.show()

# Plot Spectral Clustering Results with updated colors
plt.figure(figsize=(8, 6))
plt.scatter(X[y_spectral == 0, 0], X[y_spectral == 0, 1], s=100, c='seagreen', label='Cluster 1', marker='o')
plt.scatter(X[y_spectral == 1, 0], X[y_spectral == 1, 1], s=100, c='mediumpurple', label='Cluster 2', marker='x')
plt.scatter(X[y_spectral == 2, 0], X[y_spectral == 2, 1], s=100, c='darkviolet', label='Cluster 3', marker='^')
plt.title('Spectral Clustering (Normalized Cut) of Iris Dataset')
plt.xlabel('Sepal length')
plt.ylabel('Sepal width')
plt.legend()
plt.show()

# Compute the confusion matrix for KMeans
encoder = LabelEncoder()
y_encoded = encoder.fit_transform(y)
conf_matrix_kmeans = confusion_matrix(y_encoded, y_kmeans)

# Compute the confusion matrix for Spectral Clustering
conf_matrix_spectral = confusion_matrix(y_encoded, y_spectral)

# Show confusion matrices
print("Confusion Matrix for KMeans Clustering:")
print(conf_matrix_kmeans)

print("\nConfusion Matrix for Spectral Clustering (Normalized Cut):")
print(conf_matrix_spectral)

# Compute accuracy for both methods
accuracy_kmeans = accuracy_score(y_encoded, y_kmeans)
accuracy_spectral = accuracy_score(y_encoded, y_spectral)

print(f"\nAccuracy of KMeans Clustering: {accuracy_kmeans:.4f}")
print(f"Accuracy of Spectral Clustering: {accuracy_spectral:.4f}")