from core import logic
import numpy as np
from matplotlib import pyplot as plt
import matplotlib

l = logic("/home/shrey/Desktop/Project/ssl-project/parser",10)

print(l)

z = np.zeros((89,89))

for i in range(89):
    for j in range(89):
        z[i][j] = l["data"][i*89+j]

cmap=matplotlib.colors.ListedColormap(['green','red'])
bounds=[0,0.5,1]
norm = matplotlib.colors.BoundaryNorm(bounds, cmap.N)
img = plt.imshow(z,interpolation='nearest',cmap = cmap,norm=norm)
# plt.imshow(z,cmap="hot",interpolation="nearest")

# make a color bar
#plt.colorbar(img,cmap=cmap,norm=norm,boundaries=bounds,ticks=[0.2,0.4,0.6])
plt.show()


# print(l["filenames"])
