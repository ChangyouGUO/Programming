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
    xObjectThresh = np.arange(0, 92)
    yObjectThresh = offset(xObjectThresh) + nSafePassHeight
    yObjectSafePass = np.ones(92) *nSafePassHeight
    
    fig, ax1 = plt.subplots()

    lineThreshold, = ax1.plot(xObjectThresh, yObjectThresh, linestyle='-', color="orange", label='目标高度报警阈值')
    lineThreshold.set_dashes([3, 3])

    lineSafe, = ax1.plot(xObjectThresh, yObjectSafePass, color="black", label='车辆最低可安全通过高度')
    # lineSafe.set_dashes([3, 3])

    # draw points

    yPoints = np.array([3.6, 3.8, 4.0, 4.2, 4.3, 4.3, 4.2, 4.0, 3.8, 3.6, 3.5, 3.5,
                        3.6, 3.8, 4.0, 4.2, 4.4, 4.6, 4.7, 4.7, 4.6, 4.4, 4.2, 4.0, 3.8, 3.7, 3.7, 
                        3.8, 4.0, 4.2, 4.4, 4.6, 4.8, 5.0, 5.1, 5.1, 5.0, 4.8, 4.6, 4.4, 4.2, 4, 3.9, 3.9,
                        4, 4.2, 4.5, 4.8, 5.1, 5.4, 5.7, 6, 6.1, 6.1, 6, 5.7, 5.4, 5.1, 4.8, 4.5, 4.2, 3.9, 3.8, 3.8,
                        3.9, 4.2, 4.5, 4.8, 5.1, 5.4, 5.7, 6.0, 6.3, 6.4, 6.4, 6.3, 6.0, 5.7, 5.4, 5.1, 4.8, 4.5, 4.2, 4.1, 4.1,
                        4.2, 4.6, 5.0 
                       ])
    xPoints = np.arange(85-yPoints.size*0.7, 85, 0.7)

    # line fit方程拟合. 拟合绘图是点间用直线连接，不光滑
    # fFitLine = np.polyfit(xPoints, yPoints, 10)
    # yFitValue = np.polyval(fFitLine, xPoints)
    # ax1.plot(xPoints[:3], yFitValue[:3], "b")
    # ax1.plot(xPoints[2:11], yFitValue[2:11], "r")
    # ax1.plot(xPoints[10:], yFitValue[10:], "b")

    # 散点插值
    xnew = np.linspace(xPoints.min(), xPoints.max(), 300)
    tck = interpolate.splrep(xPoints, yPoints)
    y_bspline = interpolate.splev(xnew, tck)

    # 分段画线
    ax1.plot(xnew[0:30], y_bspline[0:30], color="r")
    ax1.plot(xnew[31:66], y_bspline[31:66], color="b")
    ax1.plot(xnew[68:79], y_bspline[68:79], color="r")
    ax1.plot(xnew[80:], y_bspline[80:], color="b", label='目标高度的拟合曲线\n蓝色: 不报警\n红色: 报警')

    # plot points
    ax1.scatter(xnew[1], y_bspline[1], marker="o", color=["r"], label="目标高度\n蓝色: 不报警\n红色: 报警")   
    ax1.scatter(xnew[6], y_bspline[6], marker="o", color="r")
    ax1.scatter(xnew[15], y_bspline[15], marker="o", color="r")
    ax1.scatter(xnew[25], y_bspline[25], color="r")
    ax1.scatter(xnew[30], y_bspline[30], color="r")
    ax1.scatter(xnew[42], y_bspline[42], color="b")
    ax1.scatter(xnew[47], y_bspline[47], color="b")

    ax1.scatter(xnew[66], y_bspline[66], color="b")
    ax1.scatter(xnew[73], y_bspline[73], color="r")
    ax1.scatter(xnew[79], y_bspline[79], color="r")
    ax1.scatter(xnew[87], y_bspline[87], color="b")
    ax1.scatter(xnew[96], y_bspline[96], color="b")

    ax1.scatter(xnew[136], y_bspline[136], color="b")
    ax1.scatter(xnew[146], y_bspline[146], color="b")
    ax1.scatter(xnew[156], y_bspline[156], color="b")

    ax1.scatter(xnew[204], y_bspline[204], color="b")
    ax1.scatter(xnew[208], y_bspline[208], color="b")
    ax1.scatter(xnew[221], y_bspline[221], color="b")
    ax1.scatter(xnew[225], y_bspline[225], color="b")

    ax1.scatter(xnew[278], y_bspline[278], color="b")
    ax1.scatter(xnew[284], y_bspline[284], color="b")
    ax1.scatter(xnew[294], y_bspline[294], color="b")

    # ax1.scatter(xPoints, yPoints, marker="o", color=["b", "b", "r", "r", "r", "r", "r", "r", "r", "r", "b", "b", "b", "b", "b", "b", "b"], label="目标高度\n蓝色: 不报警\n红色: 报警")

    ax1.annotate("1", xy=(xnew[294], y_bspline[294]), xytext=(xnew[294]+1, y_bspline[294]), color="b")
    ax1.annotate("2", xy=(xnew[284], y_bspline[284]), xytext=(xnew[284], y_bspline[284]-0.4), color="b")
    ax1.annotate("3", xy=(xnew[278], y_bspline[278]), xytext=(xnew[278]-2.5, y_bspline[278]), color="b")

    ax1.annotate("4", xy=(xnew[225], y_bspline[225]), xytext=(xnew[225]+1.3, y_bspline[225]), color="b")
    ax1.annotate("5", xy=(xnew[221], y_bspline[221]), xytext=(xnew[221]+1.3, y_bspline[221]-0.25), color="b")
    ax1.annotate("6", xy=(xnew[208], y_bspline[208]), xytext=(xnew[208]-2.5, y_bspline[208]), color="b")
    ax1.annotate("7", xy=(xnew[204], y_bspline[204]), xytext=(xnew[204]-2.5, y_bspline[204]), color="b")

    ax1.annotate("8", xy=(xnew[156], y_bspline[156]), xytext=(xnew[156]+1.5, y_bspline[156]), color="b")
    ax1.annotate("9", xy=(xnew[146], y_bspline[146]), xytext=(xnew[146], y_bspline[146]-0.4), color="b")
    ax1.annotate("10",xy=(xnew[136], y_bspline[136]), xytext=(xnew[136]-3.5, y_bspline[136]), color="b")

    ax1.annotate("11", xy=(xnew[96], y_bspline[96]), xytext=(xnew[96]+1.5, y_bspline[96]), color="b")
    ax1.annotate("12", xy=(xnew[87], y_bspline[87]), xytext=(xnew[87], y_bspline[87]-0.3), color="b")
    ax1.annotate("13", xy=(xnew[79], y_bspline[79]), xytext=(xnew[79]-2, y_bspline[79]-0.3), color="b")
    ax1.annotate("14", xy=(xnew[73], y_bspline[73]), xytext=(xnew[73]+1, y_bspline[73]), color="b")
    ax1.annotate("15", xy=(xnew[66], y_bspline[66]), xytext=(xnew[66]+1, y_bspline[66]), color="b")

    ax1.annotate("16", xy=(xnew[47], y_bspline[47]), xytext=(xnew[47]+1, y_bspline[47]-0.2), color="b")
    ax1.annotate("17", xy=(xnew[42], y_bspline[42]), xytext=(xnew[42]+0.7, y_bspline[42]-0.2), color="b")
    ax1.annotate("18", xy=(xnew[30], y_bspline[30]), xytext=(xnew[30]-3, y_bspline[30]-0.1), color="b")
    ax1.annotate("19", xy=(xnew[25], y_bspline[25]), xytext=(xnew[25], y_bspline[25]+0.1), color="b")
    ax1.annotate("20", xy=(xnew[15], y_bspline[15]), xytext=(xnew[15]-1, y_bspline[15]+0.2), color="b")
    ax1.annotate("21", xy=(xnew[6], y_bspline[6]),   xytext=(xnew[6]-2, y_bspline[6]), color="b")
    ax1.annotate("22", xy=(xnew[1], y_bspline[1]),   xytext=(xnew[1]-3, y_bspline[1]), color="b")

    ax1.axis([0, 90, 0, 8])
    ax1.set_xlabel('距离(m)')
    ax1.set_ylabel('高度(m)')

    ax2 = ax1.twinx()
    ax2.axis([0, 90, 0, 8])
    ax2.set_ylabel('高度(m)')
    
    ax1.legend()
    plt.show()


if __name__ == "__main__":
    main()