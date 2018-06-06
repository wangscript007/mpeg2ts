#
# Simple Dockerfile for building and debugging ts-lib with necessary tools.
#
# Copyright © 2018 All rights reserved for skullanbones™
#

FROM ubuntu:16.04 as base

### Create user account ###
FROM base as user
RUN apt-get update && apt-get -y --no-install-recommends install \
    ca-certificates \
    curl

RUN gpg --keyserver ha.pool.sks-keyservers.net --recv-keys B42F6819007F00F88E364FD4036A9C25BF357DD4
RUN curl -o /usr/local/bin/gosu -SL "https://github.com/tianon/gosu/releases/download/1.4/gosu-$(dpkg --print-architecture)" \
    && curl -o /usr/local/bin/gosu.asc -SL "https://github.com/tianon/gosu/releases/download/1.4/gosu-$(dpkg --print-architecture).asc" \
    && gpg --verify /usr/local/bin/gosu.asc \
    && rm /usr/local/bin/gosu.asc \
    && chmod +x /usr/local/bin/gosu

COPY entrypoint.sh /usr/local/bin/entrypoint.sh

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

### Builder image ###
FROM user as build

RUN apt-get update && apt-get install --yes --no-install-recommends
RUN apt-get install --yes --no-install-recommends software-properties-common
RUN apt-get install --yes --no-install-recommends build-essential
RUN apt-get install --yes --no-install-recommends clang-format-5.0
RUN apt-get install --yes --no-install-recommends tstools
RUN apt-get install --yes --no-install-recommends git
RUN apt-get install --yes --no-install-recommends gdb
RUN apt-get install --yes --no-install-recommends gdbserver
RUN apt-get install --yes --no-install-recommends cmake

# Install gtest/gmock
RUN git clone -q https://github.com/google/googletest.git /googletest \
  && cd googletest \
  && git checkout tags/release-1.8.0 \
  && mkdir -p /googletest/build \
  && cd /googletest/build \
  && cmake .. && make && make install \
  && cd / && rm -rf /googletest

# Install benchmark
RUN git clone -q https://github.com/google/benchmark.git /benchmark \
  && cd benchmark \
  && git checkout tags/v1.3.0 \
  && mkdir -p /benchmark/build \
  && cd /benchmark/build \
  && cmake -DCMAKE_BUILD_TYPE=Release .. && make && make install \
  && cd / && rm -rf /benchmark



WORKDIR /tmp/workspace
