#!/bin/sh -e

git ls-files | grep -E "src|include/**/*.*pp"  | xargs cloc
