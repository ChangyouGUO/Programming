import sys
"""
Combine two file base on first file's frameNo

first params: ground truth file

format:(Frame, realX, realX, Confidence)
===
Frame, realX, realX, Confidence
594, 47308, -5077, 1.07
...
===

second params: speed file
format:(Frame, speed(km/h), speed(m/s), speed(m/frame))
===
451,2.820000,0.783333,0.078333
...
===
"""


def readFileReturnAllLines(file):
    with open(file, "r") as rf:
        return rf.readlines()


def processTruthFile(truth_file):
    contents = readFileReturnAllLines(truth_file)
    truth_dict = {}
    for index, line in enumerate(contents):
        if index == 0:
            continue
        frame, info = line.strip().split(",", 1)
        frame = int(frame.strip())
        truth_dict[frame] = info.strip()
    return truth_dict


def processSpeedFile(speed_file, truth_dict):
    contents = readFileReturnAllLines(speed_file)
    for line in contents:
        frameNo, speedInfo = line.strip().split(",", 1)
        frameNo = int(frameNo.strip())

        if frameNo not in truth_dict:
            continue
        else:
            truth_dict[frameNo] = truth_dict[frameNo] + "," + speedInfo.strip()
    return truth_dict


def writeCombineFile(filename, truth_dict):
    with open(filename, "w") as wf:
        for key in sorted(truth_dict.keys()):
            wf.writelines(str(key) + "," + truth_dict[key] + "\n")


def main():
    truth_file = sys.argv[1]
    speed_file = sys.argv[2]

    truth_dict = processTruthFile(truth_file)
    truth_dict = processSpeedFile(speed_file, truth_dict)

    filename = truth_file.split("/")
    filename[-1] = "combine.txt"
    filename = "/".join(filename)
    writeCombineFile(filename, truth_dict)


if __name__ == "__main__":
    main()