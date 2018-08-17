#set -x
is_clean=$1
REPO_DIR=$(git rev-parse --show-toplevel)
BUILD_DIR=${REPO_DIR}/build
DEBUG_FLAG=b #a

if ${is_clean};
then
    rm -rf ${BUILD_DIR}/bin/
    rm -rf ${BUILD_DIR}/lib/
    rm -rf ${BUILD_DIR}/builds/*
fi

mkdir -p ${BUILD_DIR}/builds

pushd ${BUILD_DIR}/builds/
cmake ../../ -DCMAKE_BUILD_TYPE=Debug
make clean
make -j2 #--debug=${DEBUG_FLAG}
popd





##where DEBUG_FLAG can be:
## a for all debugging (same as make -d and make --debug).
## b for basic debugging.
## v for slightly more verbose basic debugging.
## i for implicit rules.
## j for invocation information.
## m for information during makefile remakes.

