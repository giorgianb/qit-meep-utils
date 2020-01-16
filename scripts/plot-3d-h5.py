#!/usr/bin/env python3
import h5py
import sys
from mayavi import mlab
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

with h5py.File(sys.argv[1], 'r') as f:
    print("Available keys:")
    for key in f.keys():
        print(key)

    data = np.array(f[sys.argv[2]])
    s = mlab.contour3d(data, colormap="YlGnBu")
    mlab.show()


    s = mlab.volume_slice(data, colormap="YlGnBu")
    mlab.show()

   

