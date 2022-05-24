#!/bin/bash 
DATE=`date +%Y%m%d`
git  add .
git commit -m  "$DATE"
git  push  git@github.com:taizilinger123/C.git
