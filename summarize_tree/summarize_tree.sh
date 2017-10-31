#!/bin/bash

#Targeting the dir that needs work
TAR_DIR=$1
#Type d is getting the directory
NUM_DIRS=$(find "$TAR_DIR"/ -type d | wc -1)
#Type f is getting the fiels
NUM_REG=$(find "$TAR_DIR"/ -type f | wc -1)


echo "There were $dir_number directories."
echo "There were $regular_files regular files."