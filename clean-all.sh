#!/bin/bash
set echo on

echo "Cleaning everything..."

# pushd engine
# source build.sh
# popd
make -f Makefile.engine.linux.mak clean

ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]
then
echo "Error:"$ERRORLEVEL && exit
fi

# pushd testbed
# source build.sh
# popd

make -f Makefile.testbed.linux.mak clean
ERRORLEVEL=$?
if [ $ERRORLEVEL -ne 0 ]
then
