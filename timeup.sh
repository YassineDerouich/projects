#!/bin/bash

i=0

while [ $i -ge 0 ]; do
	sleep 1
        i=$(($i+1))
	if [[  $1 ==  'start' ]]; then
		echo $i >>  /home/etudiant/Bureau/uptime.txt
	elif  [[ $1 == 'stop' ]]; then
		compteur=$(echo $(wc -l < /home/etudiant/Bureau/uptime.txt))
		temps=$(echo "scale=2; ($compteur/3600)" | bc > yop.txt )
		heure=$(cut -d '.' -f 1 yop.txt)
		minute=$(cut -d '.' -f 2 yop.txt)
		reelminute=$(echo "scale=0; ($minute*0.6)/1" | bc)
		echo "L'ordinateur est allumé depuis $heure"'h'"$reelminute"'minutes'
	exit 0
	else
		echo "ERREUR, SELECTIONNER START ou STOP"
	exit 0
	fi
done

