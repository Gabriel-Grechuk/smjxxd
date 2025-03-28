#!/bin/sh
set -e
SGDK_VERSION_TAG="v2.00"

printf "Running build with docker...\n"
docker run --rm -v $PWD:/m68k -t registry.gitlab.com/doragasu/docker-sgdk:$SGDK_VERSION_TAG
printf "Done!\n"
