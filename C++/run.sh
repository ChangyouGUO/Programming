#! /bin/bash

cd  $( dirname "${BASH_SOURCE[0]}" )
g++ -o ./build/streams -std=c++11 ./streams.cpp