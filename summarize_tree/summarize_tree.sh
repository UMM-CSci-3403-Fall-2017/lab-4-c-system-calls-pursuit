#!/bin/sh

cd $1       #go to the current address

#finding the amount of regular files
File=$(find $TAR_DIR -type f|wc -l)
#finding the amount of directoers
directories=$(find  $TAR_DIR -type d|wc -l)

echo "There were $directories directories."
echo "There were $File regular files."