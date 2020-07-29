#!/bin/bash

sudo mkdir -p /tmp/sh
sudo tee /tmp/sh/test.txt <<-'EOF'
{
    helloworld
}
EOF
