#!/bin/sh -e

LICENSE_FILE="LICENSE-3RD-PARTY.txt"

rm $LICENSE_FILE

for license in tools/3rdpartylicenses/*.txt
do
  echo "Adding license: $license"
  cat $license >> $LICENSE_FILE
  echo "" >> $LICENSE_FILE
done
