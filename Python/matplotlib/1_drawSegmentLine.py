import numpy as np
import matplotlib.pyplot as plt

segment_param = [[0.0095, 1], [0.0613, 0.2238], [0.0302, 1]]
segment_speed = [15, 30, 120]
speed_max = 130

speed_x = np.linspace(0, speed_max, speed_max, endpoint=True)
thresh_y = []

for speed in speed_x:
    if speed < segment_speed[0]:
        thresh_y.append(speed * segment_param[0][0] + segment_param[0][1])
        continue

    if speed < segment_speed[1]:
        thresh_y.append(speed * segment_param[1][0] + segment_param[1][1])
        continue

    thresh_y.append(speed * segment_param[2][0] + segment_param[2][1])

assert len(speed_x) == len(thresh_y), "data dimension not equal"

fig, ax1 = plt.subplots()
ax1.plot(speed_x, thresh_y, color="b")
ax1.axis([0, speed_max, 0, 10])

ax1.set_xlabel('speed(m/h)')
ax1.set_ylabel('TTCThresh(s)')

plt.show()
