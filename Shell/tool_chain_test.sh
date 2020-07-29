#!/bin/bash

OS_VERSION="$( python3 -c "import platform; a=platform.dist(); print(a[1])" )"
PATH_VAR="$( pwd )"
echo ${OS_VERSION}
echo ${PATH_VAR}

OS_VERSION_MAJ=${OS_VERSION%.*}
OS_VERSION_MIN=${OS_VERSION#*.}
echo "MAJ: $OS_VERSION_MAJ"
echo "MIN: $MinOS_VERSION_MIN"

if [ ${OS_VERSION_MAJ} -lt 18 ]; then
    echo "less than 18"
fi

if [ ${OS_VERSION_MAJ} -lt 16 ]; then
    echo "less than 16"
else
    echo "large than 16"
fi

echo -n "Testing?(Y/N):"
read ANSWER
case $ANSWER in
[Nn]*)
    echo "You choose NO!"
    ;;
*)
    if [ ${OS_VERSION_MAJ} -ge 18 ]; then
        echo "greate than 18"
    fi
    
    echo "Although warning, but finish everything"
    ;;
esac
