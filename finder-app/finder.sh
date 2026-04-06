#!/bin/sh

filesdir=$1
searchstr=$2

if [ $# -ne 2 ]
then
    echo "Usage: $0 <filesdir> <searchstr>"
    exit 1
fi

[ ! -d "$filesdir" ] && echo "Directory $filesdir DOES NOT exists." && exit 1

filesNumber=$(ls -l "$filesdir" | grep -c ^-)
matchingLineNumber=$(grep -n "$searchstr" "$filesdir"/* | wc -l)

echo "The number of files are $filesNumber and the number of matching lines are $matchingLineNumber."