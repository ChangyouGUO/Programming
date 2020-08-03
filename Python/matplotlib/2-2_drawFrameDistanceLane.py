import numpy as np
import sys
import matplotlib.pyplot as plt
"""
Draw ZDistance-frame.png, XDistance-frame.png, DeltaDistancePerFrame-frame.png

params: input file

format:(Frame, realX, realX, Confidence, speed(km/h), speed(m/s), speed(m/frame))
===
594,47308, -5077, 1.0,47.099998,13.083333,1.3083337
...
===
"""


def readFileReturnAllLines(file):
    with open(file, "r") as rf:
        return rf.readlines()


if __name__ == "__main__":
    """file format
    frameNo, Z, confidence, speed(km/h), speed(m/s), speed(m/frame)
    """
    file = sys.argv[1]
    lines = readFileReturnAllLines(file)
    contents = []
    for line in lines:
        contents.append([float(item.strip()) for item in line.split(",")])
    info = np.asarray(contents)
    print("data dim: {}".format(info.shape))

    x_frame = np.arange(info.shape[0])
    y_data_z = info[:, 1]
    y_data_x = info[:, 2]

    assert len(x_frame) == len(y_data_z), "y_data_z dim not equal to x_frame"
    assert len(x_frame) == len(y_data_x), "y_data_x dim not equal to x_frame"

    fig, ax1 = plt.subplots()
    ax1.plot(x_frame, y_data_z, color="b", label="ZDistance-frame")
    ax1.axis([0, len(x_frame) + 1, 0, 100000])
    ax1.set_xlabel('Frame')
    ax1.set_ylabel('Z_distance(mm)')
    ax1.legend()
    plt.savefig(file.split(".")[0] + "_ZDistance-frame.png")
    plt.show()

    fig, ax2 = plt.subplots()
    ax2.plot(x_frame, y_data_x, color="b", label="XDistance-frame")
    ax2.axis([0, len(x_frame) + 1, -50000, 50000])
    ax2.set_xlabel('Frame')
    ax2.set_ylabel('X-distance(mm)')
    ax2.legend()
    plt.savefig(file.split(".")[0] + "_XDistance-frame.png")
    plt.show()

    speedPerFrame = info[1:, 6] * 1000
    deltaZ = info[:, 1][0:-1] - info[:, 1][1:]
    assert len(speedPerFrame) == len(
        deltaZ), "speedPerFrame size not equal to deltaZ size"

    fig, ax3 = plt.subplots()
    ax3.plot(x_frame[0:-1],
             speedPerFrame,
             color="b",
             label="SpdPerFrame-frame")
    ax3.plot(x_frame[0:-1], deltaZ, color="r", label="DeltaZ-frame")
    ax3.set_xlabel('Frame')
    ax3.set_ylabel('DeltaDistancePerFrame(mm)')
    ax3.legend()
    plt.xlim(0, len(x_frame) + 1)
    plt.savefig(file.split(".")[0] + "_DeltaDistancePerFrame-frame.png")
    plt.show()