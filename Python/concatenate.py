import numpy as np

gt = np.array([50, 20, 60, 80])
anchor = np.array([[10, 30, 80, 70], [40, 20, 90, 30], [50, 30, 100, 70]])

union = np.concatenate(
    (np.maximum(gt[np.newaxis, 0],
                anchor[:, 0]), np.maximum(gt[np.newaxis, 1], anchor[:, 1]),
     np.minimum(gt[np.newaxis, 2],
                anchor[:, 2]), np.minimum(gt[np.newaxis, 3], anchor[:, 3])),
    axis=0).reshape((3, 4))

print(union)

"""
YOLOv3 中采用[True, False, True] 控制哪一位进行赋值
"""
bboxes_label = np.zeros([3, 7, 7, 3, 5])
iou_threadhold = [True, False, True]

print(bboxes_label)

bboxes_label[0][5, 6, iou_threadhold, 0:2] = np.array((1, 1))

print(bboxes_label[0, 5, 6, :])
