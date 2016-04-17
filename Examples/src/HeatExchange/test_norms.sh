#!/bin/bash

echo Test L2 norm
./main -p L2norm_test.pot
echo
echo Test H1 norm
./main -p H1norm_test.pot
