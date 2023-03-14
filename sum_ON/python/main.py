import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("data.txt", sep="\t")
N = data.iloc[:, 0]
t = data.iloc[:, 1]
N = N.to_numpy()
t = t.to_numpy()

a = ((N * t).mean() - N.mean() * t.mean()) / ((N * N).mean() - N.mean() ** 2)
b = t.mean() - a * N.mean()
print("a =", a)
print("b = ", b)

sigma_a = ((1 / (N.shape[0] - 1)) * (
        ((t * t).mean() - t.mean() ** 2) / ((N * N).mean() - N.mean() ** 2) - a ** 2)) ** 0.5
sigma_b = sigma_a * ((N * N).mean() - N.mean() ** 2) ** 0.5

print("sigma_a = ", sigma_a)
print("sigma_b = ", sigma_b)

epsilon_a = abs(sigma_a / a)
epsilon_b = abs(sigma_b / b)

print("epsilon_a =", epsilon_a * 100, "%")
print("epsilon_b =", epsilon_b * 100, "%")

plt.figure(figsize=(8, 6))

plt.xlabel('$N$, $10^6$ элементов', fontsize=14)
plt.ylabel('$t$, мс', fontsize=14)

X = np.arange(0, 1000000, 0.1)
plt.plot(X, a * X + b)

plt.scatter(N, t, marker="s", color="black", s=10)
plt.grid()
plt.legend(['$t = a \cdot N +b$ ($a = 0.002$ мc, $b = -1$ мc)'], loc="upper left")
plt.show()
