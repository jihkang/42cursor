#/bin/sh

name=$1
if [ $name ]
then
	mkdir $name
	cd $name
	touch Makefile
	mkdir inc
	mkdir src
else
	echo "no workname"
fi
