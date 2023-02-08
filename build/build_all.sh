#!/bin/bash

rm -rf ./output/build-server/

if [[ ${1} == "-r" ]];
then
    rm -rf ./out/
    exit 1
fi

cmake -S . -B ./output/build-server/
CMAKE=$?

if [[ ${CMAKE} != 0 ]];
then
    echo -en "\033[0;31m"
    echo "ERROR - cmake"
    echo -en "\033[0m"
    exit 2
fi

make -C ./output/build-server/
MAKE=$?

if [[ ${MAKE} != 0 ]];
then

    echo -en "\033[0;31m"
    echo "ERROR - make"
    echo -en "\033[0m"
    exit 3
fi

strip ./output/build-server/SCS
echo -en "\033[0;32m"
echo "SUCCESS"
echo -en "\033[0m"