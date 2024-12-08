import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import load_breast_cancer
from sklearn.preprocessing import StandardScaler
from sklearn.decomposition import KernelPCA
from mpl_toolkits.mplot3d import Axes3D

data = load_breast_cancer()
X = data.data
y = data.target

scaler = StandardScaler()
X_scaled = scaler.fit_transform(X)

def custom_cubic_kernel(X1, X2):
    gram_matrix = np.dot(X1, X2.T)
    return (gram_matrix + 1) ** 3

K = custom_cubic_kernel(X_scaled, X_scaled)

kpca = KernelPCA(n_components=3, kernel='precomputed')
X_kpca = kpca.fit_transform(K)

fig = plt.figure(figsize=(10, 8))
ax = fig.add_subplot(111, projection='3d')

scatter = ax.scatter(X_kpca[:, 0], X_kpca[:, 1], X_kpca[:, 2],
                    c=y, cmap='viridis',
                    s=50, alpha=0.6)

ax.set_title('Breast Cancer Dataset - Kernel PCA with Cubic Kernel')
ax.set_xlabel('First Principal Component')
ax.set_ylabel('Second Principal Component')
ax.set_zlabel('Third Principal Component')

plt.colorbar(scatter, label='Class (0: Benign, 1: Malignant)')

ax.view_init(elev=20, azim=45)

plt.tight_layout()
plt.show()

total_variance = np.sum(np.var(X_kpca, axis=0))
explained_variance_ratio = np.var(X_kpca, axis=0) / total_variance
print("\nApproximate explained variance ratio:")
for i, ratio in enumerate(explained_variance_ratio):
    print(f"Component {i+1}: {ratio:.3f}")