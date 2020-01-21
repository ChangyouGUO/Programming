import numpy as np
import matplotlib.pyplot as plt
from scipy import optimize


nSafePassHeight = 4.0

def offset(distance, offset_b =0, offset_k = 0.003):
    return offset_b + offset_k * distance;


def main():
    xObjectThresh = np.arange(0, 90)
    yObjectThresh = offset(xObjectThresh) + nSafePassHeight
    yObjectSafePass = np.ones(90) *nSafePassHeight
    
    plt.plot(xObjectThresh, yObjectThresh, label='HeightThresh')
    lineSafe, = plt.plot(xObjectThresh, yObjectSafePass, linestyle='-', label='VehicleSafePassHeight')
    lineSafe.set_dashes([3, 3])

    # draw points
    xPoints = np.arange(85, 35, -3)
    yPoints = np.array([4.15, 4.1, 3.9, 3.85, 3.95, 4.1, 4.4, 4.12, 3.95, 4.25, 4.3, 4.25, 4.0, 3.95, 4.2, 4.25, 4.25])

    # line fit
    fFitLine = np.polyfit(xPoints, yPoints, 10)
    yFitValue = np.polyval(fFitLine, xPoints)
    plt.plot(xPoints[:3], yFitValue[:3], "b")
    plt.plot(xPoints[2:11], yFitValue[2:11], "r")
    plt.plot(xPoints[10:], yFitValue[10:], "b")
   
    plt.scatter(xPoints, yPoints, marker="o", color=["b", "b", "r", "r", "r", "r", "r", "r", "r", "r", "b", "b", "b", "b", "b", "b", "b"], label="ObjectHeight\n blue: warning off\n red:  warning on")

    plt.annotate("1", xy=(85, 4.15), xytext=(84, 4.3), color="b")
    plt.annotate("2", xy=(82, 4.1),  xytext=(81, 4.2), color="b")
    plt.annotate("3", xy=(79, 3.9),  xytext=(78, 3.6), color="r")
    plt.annotate("4", xy=(67, 4.4),  xytext=(66, 4.53), color="r")
    plt.annotate("5", xy=(58, 4.25), xytext=(57.3, 4.4), color="r")
    plt.annotate("6", xy=(55, 4.3), xytext=(54, 4.45), color="b")
    plt.annotate("7", xy=(49, 4.0), xytext=(48, 3.65), color="b")
    plt.annotate("8", xy=(46, 3.95), xytext=(45, 3.6), color="b")


    plt.axis([0, 90, 0, 7])
    plt.xlabel('Distance(m)')
    plt.ylabel('Height(m)')
    
    plt.legend()
    plt.show()


if __name__ == "__main__":
    main()