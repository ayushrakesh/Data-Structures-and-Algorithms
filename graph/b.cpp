// #Import necessary libraries
import numpy as np import matplotlib.pyplot as plt from sklearn.linear_model import Ridge from sklearn.preprocessing import PolynomialFeatures from sklearn.metrics import mean_squared_error from sklearn.model_selection import train_test_split

    // # Generate random sample dataset
    np.random.seed(42)
                       X = 2 * np.random.rand(100, 1)
                                                       y = 4 + 3 * X + np.random.randn(100, 1) #Linear data with some noise

                                                                                       // # Polynomial transformation
                                                                                       poly_features = PolynomialFeatures(degree = 4)
                                                                                                                              X_poly = poly_features.fit_transform(X)

                                                                                                                                                                   // # Split data into training and testing sets
                                                                                                                                                                   X_train,
                                                                                                                                                                   X_test, y_train, y_test = train_test_split(X_poly, y, test_size = 0.2, random_state = 42)

                                                                                                                                                                                                              // # Ridge regression (L2 regularization)
                                                                                                                                                                                                              ridge_reg = Ridge(alpha = 0.1) ridge_reg.fit(X_train, y_train) y_pred_ridge = ridge_reg.predict(X_test)

                                                                                                                                                                                                                                                                                                              // # Plotting the Ridge regression results
                                                                                                                                                                                                                                                                                                              plt.figure(figsize =(8, 6)) plt.scatter(X[ :, 0], y, color = 'blue', label = 'Data') plt.plot(X[ :, 0], ridge_reg.predict(poly_features.transform(X)), color = 'purple', label = 'Ridge Regression') plt.title('L2 Regularization (Ridge)') plt.legend() plt.show()

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     // # Calculate and print Mean Squared Error for Ridge regression
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     mse_ridge = mean_squared_error(y_test, y_pred_ridge) print(f "Ridge Regression MSE: {mse_ridge}")