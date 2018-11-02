#!/bin/bash

# Run commands inside docker container
docker_run() {
    source Makefile.variables
    echo "Starting container: " "$DOCKER_IMAGE_NAME:$DOCKER_IMAGE_VER"

    echo "Got command: " "$*"
    USER_ID=$(id -u $USER)
    echo "Using USER_ID:" $USER_ID

    docker run  --env LOCAL_USER_ID=$USER_ID \
                --rm \
                --volume "$(pwd)":/tmp/workspace \
				--workdir /tmp/workspace \
                --env "TERM=xterm-256color" \
                --tty \
                --entrypoint /tmp/workspace/tools/entrypoint.sh \
				"$DOCKER_IMAGE_NAME:$DOCKER_IMAGE_VER" \
				$*
}

# 1st command: Run make target inside docker
docker-make() {
    docker_run make "${@}"
}

# 2nd command: Run bash command inside docker
docker-bash() {
    docker_run "${@}"
}