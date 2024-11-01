# /bin/bash

project=$1

mkdir $project

cd $project

touch main.cpp
mkdir include

cd ./include

mkdir common
mkdir controller
mkdir dto
mkdir entity
mkdir repository
mkdir service