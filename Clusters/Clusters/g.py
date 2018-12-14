import matplotlib.pyplot as plt
import numpy as np

ks = []
bs = []

k = 0
b = 0


with open('outX.txt', 'rb') as f:
    lines = f.readlines()
    k, b = map(float, lines[0].split())
    for i in range(1, 400):
        nk, nb = map(float, lines[i].split())
        ks.append(nk)
        bs.append(nb)

x = np.linspace(-5, 5, 2)
y = k*x + b

fig, ax = plt.subplots()
for i in range(len(ks)):
    y = ks[i] * x + bs[i]
    ax.plot(x, y, color="red")

y = k*x + b
ax.plot(x, y, color="blue")

plt.show()

# fig.savefig('1.png')
