#!/bin/bash
echo "Compiling COB theme CSS"
pysassc -t compact -m screen.scss screen.css
