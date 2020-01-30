import fnmatch
import os

def main():
    paths = os.listdir(".")
    fnmatch.filter(paths, '*.jpg')
    print(paths)
    print("\n")
    print(file_paths)
    print("\n")

if __name__ == '__main__':
    main()