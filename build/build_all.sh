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
    echo "ERROR - cmake"
    exit 2
fi

make -C ./output/build-server/
MAKE=$?

if [[ ${MAKE} != 0 ]];
then 
    echo "ERROR - make"
    exit 3
fi

mv ./output/build-server/server ./out/

echo "SUCCESS"