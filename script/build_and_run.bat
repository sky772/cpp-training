#!/bin/bash
pushd .

./script/build.sh
if [ $? -ne 0 ]; then
    echo "There was an error during the build process."
else
    ./script/run.sh
    if [ $? -ne 0 ]; then
        echo "There was an error running the application."
    fi
fi

popd