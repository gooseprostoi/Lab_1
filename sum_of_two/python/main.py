import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("data.txt", sep="\t")
N = data.iloc[:, 0]
t = data.iloc[:, 1]
N = N.to_numpy()
t = t.to_numpy()

plt.figure(figsize=(8, 6))

plt.xlabel('$N$, элементов', fontsize=14)
plt.ylabel('$t$, мс', fontsize=14)
p = np.polyfit(N, t, deg=2)
p_f = np.poly1d(p)
X = np.arange(0, 100000, 0.1)
plt.plot(X, p_f(X))
print(p)

plt.scatter(N, t, marker="s", color="black")
plt.grid()
plt.legend(['$t = aN^2 + bN + c$ ($a = 7.47 \cdot 10^{-7}$ мc, $b = 1 \cdot 10^{-5}$ мc, $c = -4.8 \cdot 10^{-2}$ мc)'],
           loc="upper left")
plt.show()
