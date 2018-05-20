#!/bin/bash

# Automatically gets the latest autorice script from github

rm autorice.sh
curl -o autorice.sh https://raw.githubusercontent.com/creikey/autorice/master/autorice.sh
chmod +x autorice.sh
