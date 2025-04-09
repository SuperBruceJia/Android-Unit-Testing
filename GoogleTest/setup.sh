#!/bin/bash

# Update and install required packages
apt-get update && apt-get install -y \
    g++ \
    cmake \
    git \
    python3 \
    python3-pip

# Install Googletest
git clone https://github.com/google/googletest.git /googletest
cd /googletest
cmake .
make
make install