# Docker Important Commands

### Pull any image which is present in the official registry of docker, Docker hub.

```bash
docker pull <image_name>

```

### List of all the running containers

```bash

 docker ps [options..]
```

- -a flag: shows us all the containers, stopped or running.
- -l flag: shows us the latest container.
- -q flag: shows only the Id of the containers.

### Stop/start/restart container

```bash
docker stop/start/restart <container_ID>
```

### Delete a container

```bash
docker rm {options} <container_name or ID>
```

- -f flag: remove the container forcefully.
- -v flag: remove the volumes.
- -l flag: remove the specific link mentioned.

### Delete the image in docker

```bash
docker rmi <image ID/ image name>
```

### Lists all the pulled images which are present in our system.

```bash
docker images
```

### Run new commands in a running container

```bash
docker exec {options}
```

- -d flag: for running the commands in the background.
- -i flag: it will keep STDIN open even when not attached.
- -e flag: sets the environment variables

### Docker Ports (Port Mapping)

```bash
docker run -d -p <port_on_host> <port_on_container> Container_name
```

- This is usually done to start a port locally

### Docker build command is used to build the docker images with the help of Dockerfile.

```bash
docker build -t image_name:tag .
```

### Docker Inspection

```bash
docker inspect container_name_or_id
```

### Docker Commit command

```bash
docker commit container_name_or_id new_image_name:tag
```

- After running the containers by using the current image you can make the updates to the containers by interacting with the containers from that containers you can create an image by using the following commands.
