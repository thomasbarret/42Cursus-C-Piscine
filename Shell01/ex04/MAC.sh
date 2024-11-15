#!/bin/sh
ip link show | awk '/ether/ {print $2}' 