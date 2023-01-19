#/bin/bash
echo "Creating shared library"
cd lib
make > /dev/null
make clear > /dev/null
cd ./..
echo "Creating program"
cd program
make > /dev/null
