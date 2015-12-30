#! /bin/bash
#in case wifi stops
rfkill unblock all

#block touchpad must after unblock
declare -i ID
ID=`xinput list | grep -Eo 'TouchPad\s*id\=[0-9]{1,2}' | grep -Eo '[0-9]{1,2}'`
xinput set-prop $ID "Device Enabled" 0
echo 'Touchpad has been disabled.'
