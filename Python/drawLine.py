import numpy as np
import matplotlib
import matplotlib.pyplot as plt
from scipy import interpolate

# 显示默认的字体库
# print(matplotlib.matplotlib_fname())

#显示中文标签
plt.rcParams['font.sans-serif']=['SimHei'] 

nSafePassHeight = 4.0

def offset(distance, offset_b =0, offset_k = 0.003):
    return offset_b + offset_k * distance


def main():
    xObjectThresh = np.arange(0, 90)
    yObjectThresh = offset(xObjectThresh) + nSafePassHeight
    yObjectSafePass = np.ones(90) *nSafePassHeight
    
    fig, ax1 = plt.subplots()

    ax1.plot(xObjectThresh, yObjectThresh, label='目标高度报警阈值')
    lineSafe, = ax1.plot(xObjectThresh, yObjectSafePass, linestyle='-', label='车辆最低可安全通过高度')
    lineSafe.set_dashes([3, 3])

    # draw points
    yPoints = np.array([4.35, 4.3, 4.2, 4.1, 4.0, 3.9, 3.9, 3.8, 3.8, 3.7, 3.7, 3.8, 3.8, 3.9, 3.9, 4.0, 4.0, 4.1, 4.2, 4.3, 4.4, 4.5, 4.6, 4.7, 4.7, 4.6, 4.6, 4.5, 4.4, 4.3, 4.2, 4.1, 4, 3.8, 3.8, 3.6, 3.6, 3.5, 3.5, 3.6, 3.6, 3.7, 3.7, 3.9, 3.9, 4.0, 4.0, 4.2, 4.3, 4.4, 4.6, 4.8, 5, 5.3, 5.5])
    xPoints = np.arange(85-yPoints.size*1, 85, 1)

    # line fit 方程拟合
    # fFitLine = np.polyfit(xPoints, yPoints, 10)
    # yFitValue = np.polyval(fFitLine, xPoints)
    # ax1.plot(xPoints[:3], yFitValue[:3], "b")
    # ax1.plot(xPoints[2:11], yFitValue[2:11], "r")
    # ax1.plot(xPoints[10:], yFitValue[10:], "b")

    # use scipy.interpolate.spline拟合曲线
    xnew = np.linspace(xPoints.min(), xPoints.max(), 700)
    tck = interpolate.splrep(xPoints, yPoints)
    y_bspline = interpolate.splev(xnew, tck)
    ax1.plot(xnew, y_bspline)

   
    # ax1.scatter(xPoints, yPoints, marker="o", color=["b", "b", "r", "r", "r", "r", "r", "r", "r", "r", "b", "b", "b", "b", "b", "b", "b"], label="目标高度\n蓝色: 不报警\n红色: 报警")

    # ax1.annotate("1", xy=(85, 4.15), xytext=(84, 4.3), color="b")
    # ax1.annotate("2", xy=(82, 4.1),  xytext=(81, 4.2), color="b")
    # ax1.annotate("3", xy=(79, 3.9),  xytext=(78, 3.6), color="r")
    # ax1.annotate("4", xy=(67, 4.4),  xytext=(66, 4.53), color="r")
    # ax1.annotate("5", xy=(58, 4.25), xytext=(57.3, 4.4), color="r")
    # ax1.annotate("6", xy=(55, 4.3), xytext=(54, 4.45), color="b")
    # ax1.annotate("7", xy=(49, 4.0), xytext=(48, 3.65), color="b")
    # ax1.annotate("8", xy=(46, 3.95), xytext=(45, 3.6), color="b")



    ax1.axis([0, 90, 0, 7])
    ax1.set_xlabel('距离(m)')
    ax1.set_ylabel('高度(m)')

    ax2 = ax1.twinx()
    ax2.axis([0, 90, 0, 7])
    
    ax1.legend()
    plt.show()


if __name__ == "__main__":
    main()