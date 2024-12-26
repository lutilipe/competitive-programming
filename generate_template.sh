#!/bin/sh

# filename
filename=$1
# file extension
extension="${filename##*.}"

if [ "$extension" == "cpp" ]; then
   cp -n ~/.vim/templates/cpp_template.cpp ./$filename;
else
  echo "Template not found"
  exit
fi

gvim $filename
