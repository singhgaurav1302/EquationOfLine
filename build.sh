#!/bin/sh

mkdir -p out
cd out
cmake ./..
cmake --build .
