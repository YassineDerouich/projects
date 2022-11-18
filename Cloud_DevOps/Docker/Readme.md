Bienvenue dans cette section dédiée aux conteneurs. J'utiliserais l'outil Docker dans cette partie.


# Qu'est-ce qu'un conteneur ? #

<img width="557" alt="docker_concept" src="https://user-images.githubusercontent.com/97849927/202792608-61d215de-e837-48ba-b93c-5784dac1475a.png">


Un conteneur est une solution logicielle permet d'exécuter des processus dans un environnement isolé du système d'exploitation,  qui  regroupe le code et toutes ses dépendances afin que l'application fonctionne rapidement et de manière fiable d'un environnement informatique à un autre.


# Qu'est-ce que Docker ? #

Docker est une solution logicielle permettant de lancer certaines applications dans des conteneurs logiciels. A noter que , par défaut, les conteneurs Docker sont automatiquement stoppé si le processus à l'intérieur de l'application a finit ses tâches. 

Une image Docker est un modèle en lecture seule, utiliser pour créer des conteneurs Docker. Elle est composée de plusieurs couches empaquetant toutes les installations, dépendances, bibliothèques, processus et codes d'application nécessaires pour un environnement de conteneur pleinement opérationnel.

example: l'image MySQL ( https://hub.docker.com/_/mysql ) contient l'application base de donnée MYSQL.



# Utilisation et commande de base ? #


`docker pull [nom de l'image] ` pour télécharger une image depuis le Docker Hub  

`docker images` pour afficher toutes les images docker  

`docker rmi [id_image]` pour supprimer une image

`docker run -it -d [nom de l'image]` pour lancer un conteneur. Le paramètres -it avec -i pour pouvoir créer un shell interactif et effectuer des actions depuis notre conteneur et -d pour lancer le conteneur en arrière-plan et libérer ainsi la ligne de commande.  

`docker ps -a` pour afficher tous les conteneurs, ainsi que ceux stoppés

`docker stop [id_conteneur]` pour stopper un conteneur

`docker rm [id_conteneur]` pour supprimer un conteneur

`docker login` pour se connecter au DockerHub dans l'éventualité d'y upload une image.





--------------------------------------------------------------------------------------------------------

Welcome to this section dedicated to containers. I will use the Docker tool in this part.
