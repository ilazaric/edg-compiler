#!/usr/bin/env bash

set -euo pipefail

DIR="$(dirname "$(realpath "$0")")"

exec \
    choom -n 1000 -- \
    podman run \
    --rm \
    --privileged \
    --hostname edg \
    --init \
    -e EDG_BASE="$DIR/bases/docker/dev-env/gcc" \
    -e EDG_USER_ID=1000 \
    -e EDG_USER_GROUP_ID=1000 \
    -e EDG_USER_NAME=ilazaric \
    -w "$PWD" \
    -v "$DIR":"$DIR" \
    docker.io/edgcpp/ci-runner:latest \
    "$DIR/wrapper2.sh" \
    "$@"
    # bash -eo pipefail \
    # "$DIR/dev_tools/docker/dev-env/docker-tools/edg-container-exec" \
    # "$*"
