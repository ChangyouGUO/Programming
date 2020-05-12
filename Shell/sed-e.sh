#! /bin/bash

ML_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null && pwd )"

for file in $(find $ML_DIR -iname "*.relative"); do
sed -e "s^PATH_TO^$ML_DIR^" ${file} > ${file%.relative}
done