#!/bin/bash

source=$(playerctl metadata --format "{{playerName}}")

if [[ $source ==  "chromium" ]] || [[ $source == "chrome" ]]; then
    echo ""
elif [[ $source == "firefox" ]]; then
    echo ""
elif [[ $source == "spotify" ]]; then
    echo ""
else
	echo "$source"
fi
