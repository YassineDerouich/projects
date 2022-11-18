#!/bin/bash

ping -c 1 8.8.8.8


if  [ $? == 0  ]; then
	echo success
else
	echo $(date)  >> /home/etudiant/Bureau/pbreseau.txt
	nmcli radio wifi off
	nmcli radio wifi on
fi
