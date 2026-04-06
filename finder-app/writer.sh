#!/bin/sh


writefile=$1
writestr=$2

if [ $# -ne 2 ]
then
    echo "Usage: $0 <writefile> <writestr>"
    exit 1
fi

[ ! -d "$(dirname "$writefile")" ] && mkdir -p "$(dirname "$writefile")"
touch "$writefile"
if [ $? -ne 0 ]
then
    echo "Error creating file $writefile"
    exit 1
fi
echo "$writestr" > "$writefile"