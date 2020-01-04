import numpy as np

box = np.array([20, 50, 30, 40])
stride = np.array([8, 16, 32])

# np.newaxis
print("box shape: {}, after new axis: {}".format(box.shape,
                                                 box[np.newaxis, :].shape))
print("stride shape: {}, after new axis: {}".format(
    stride.shape, stride[:, np.newaxis].shape))

for i in range(stride.shape[0]):
    bbox_anchor = np.zeros((3, 5 + 20))
    print(box / stride[i])

    # broadcast机制
    bbox_anchor[:, 0:2] = (box / stride[i])[0:2]
    print(bbox_anchor)
    print("===={}-st====".format(i))
