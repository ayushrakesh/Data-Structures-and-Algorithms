import numpy as np
import pandas as pd
from sklearn.datasets import fetch_california_housing
from sklearn.cluster import KMeans
from sklearn.linear_model import SGDRegressor
from sklearn.metrics import mean_squared_error
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, OneHotEncoder
import matplotlib.pyplot as plt

# Load the California Housing dataset
data = fetch_california_housing(as_frame=True)
X = data.data
y = data.target

# Standardize the data
scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

# Step 1: Determine the optimal number of clusters using the elbow method
inertia = []
K = range(1, 11)
for k in K:
    kmeans = KMeans(n_clusters=k, random_state=42)
    kmeans.fit(X_scaled)
    inertia.append(kmeans.inertia_)

# Plot the elbow curve
plt.figure(figsize=(8, 5))
plt.plot(K, inertia, marker='o')
plt.xlabel('Number of Clusters (K)')
plt.ylabel('Inertia')
plt.title('Elbow Method for Optimal K')
plt.show()

# Step 2: Choose K based on the elbow method (e.g., K=4) and perform K-Means clustering
optimal_k = 4
kmeans = KMeans(n_clusters=optimal_k, random_state=42)
X['Cluster'] = kmeans.fit_predict(X_scaled)

# Step 3: One-hot encode the cluster labels
encoder = OneHotEncoder()
cluster_encoded = encoder.fit_transform(X[['Cluster']]).toarray()

# Fix column names for one-hot-encoded cluster labels
encoded_df = pd.DataFrame(cluster_encoded)
encoded_df.columns = encoded_df.columns.astype(str)  # Convert column names to strings

# Combine the original data with the encoded clusters
X_with_clusters = pd.concat([X.drop(columns=['Cluster']), encoded_df], axis=1)
X_with_clusters.columns = X_with_clusters.columns.astype(str)  # Convert all column names to strings

# Step 4: Split the data into training and test sets
X_train_orig, X_test_orig, y_train, y_test = train_test_split(
    X.drop(columns=['Cluster']), y, test_size=0.2, random_state=42
)
X_train_with_clusters, X_test_with_clusters, _, _ = train_test_split(
    X_with_clusters, y, test_size=0.2, random_state=42
)

# Standardize the original features
X_train_orig = scaler.fit_transform(X_train_orig)
X_test_orig = scaler.transform(X_test_orig)

# Standardize the features with clusters
X_train_with_clusters = scaler.fit_transform(X_train_with_clusters)
X_test_with_clusters = scaler.transform(X_test_with_clusters)

# Define a function to train Ridge Regression using SGD
def ridge_regression_sgd(X_train, y_train, X_test, y_test, alpha=0.01, max_iter=1000):
    # Train the SGD Regressor with L2 penalty (Ridge Regression)
    model = SGDRegressor(penalty='l2', alpha=alpha, max_iter=max_iter, random_state=42)
    model.fit(X_train, y_train)
    
    # Predict on test data
    y_pred = model.predict(X_test)
    
    # Calculate Mean Squared Error (MSE)
    mse = mean_squared_error(y_test, y_pred)
    return model, mse

# Step 5: Train and evaluate models
_, mse_without_clusters = ridge_regression_sgd(X_train_orig, y_train, X_test_orig, y_test)
_, mse_with_clusters = ridge_regression_sgd(X_train_with_clusters, y_train, X_test_with_clusters, y_test)

# Step 6: Compare performance and provide insights
print(f"Mean Squared Error without Clustering: {mse_without_clusters:.4f}")
print(f"Mean Squared Error with Clustering: {mse_with_clusters:.4f}")

if mse_with_clusters < mse_without_clusters:
    print("Adding clustering information improved the performance of the Ridge Regression model.")
else:
    print("Adding clustering information did not improve the performance significantly.")
