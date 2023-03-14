import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

plt.figure(figsize=(12, 12))
#A
sp = plt.subplot(221)
data = pd.read_csv("dataA.txt", sep="\t")
N = data.iloc[:, 0]
t = data.iloc[:, 1]
N = N.to_numpy()
t = t.to_numpy()

plt.title("A")
plt.xlabel(r'$N$, $10^6$ элементов', fontsize=14)
plt.ylabel(r'$t$, мс', fontsize=14)
pA = np.polyfit(N, t, deg=1)
p_fA = np.poly1d(pA)
X = np.arange(0, 1000000, 0.1)
plt.plot(X, p_fA(X))

plt.scatter(N, t, marker="s", color="black", s=5)
plt.grid()


#B
sp = plt.subplot(222)
data = pd.read_csv("dataB.txt", sep="\t")
N = data.iloc[:, 0]
t = data.iloc[:, 1]
N = N.to_numpy()
t = t.to_numpy()

plt.title("B")
plt.xlabel(r'$N$, $10^6$ элементов', fontsize=14)
plt.ylabel(r'$t$, мс', fontsize=14)
pB = np.polyfit(N, t, deg=1)
p_fB = np.poly1d(pB)
X = np.arange(0, 1000000, 0.1)
plt.plot(X, p_fB(X))

plt.scatter(N, t, marker="s", color="black", s=5)
plt.grid()


#C
sp = plt.subplot(223)
data = pd.read_csv("dataC.txt", sep="\t")
N = data.iloc[:, 0]
t = data.iloc[:, 1]
N = N.to_numpy()
t = t.to_numpy()

plt.title("C")
plt.xlabel(r'$N$, $10^6$ элементов', fontsize=14)
plt.ylabel(r'$t$, мс', fontsize=14)
pC = np.polyfit(N, t, deg=1)
p_fC = np.poly1d(pC)
X = np.arange(0, 1000000, 0.1)
plt.plot(X, p_fC(X))

plt.scatter(N, t, marker="s", color="black", s=5)
plt.grid()

#ABC
sp = plt.subplot(224)

plt.xlabel(r'$N$, $10^6$ элементов', fontsize=14)
plt.ylabel(r'$t$, мс', fontsize=14)
pC = np.polyfit(N, t, deg=1)
plt.plot(X, p_fA(X))
plt.plot(X, p_fB(X))
plt.plot(X, p_fC(X))

plt.grid()
plt.show()
