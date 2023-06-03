FROM ubuntu:22.04

RUN apt-get -y update; apt-get -y install valgrind; apt-get -y install check; apt-get -y install gcc; apt-get -y install make; mkdir -p /usr/src/; apt-get -y install pkg-config;

WORKDIR /usr/src/

COPY . .

ENTRYPOINT ["/bin/bash", "-l", "-c", "make r"]


