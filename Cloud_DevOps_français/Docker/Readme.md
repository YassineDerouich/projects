/!\ See below for english version /!\

Bienvenue dans cette section dédiée aux conteneurs. J'utiliserais l'outil Docker dans cette partie.


# Qu'est-ce qu'un conteneur ? #

<img width="557" alt="docker_concept" src="https://user-images.githubusercontent.com/97849927/202792608-61d215de-e837-48ba-b93c-5784dac1475a.png">


Un conteneur est une solution logicielle qui permet d'exécuter des processus dans un environnement isolé du système d'exploitation,  qui  regroupe le code et toutes ses dépendances afin que l'application fonctionne rapidement et de manière fiable d'un environnement informatique à un autre.

### Avantages des conteneurs : ###
- portabilité
- faible consommation de ressources
- rapidité d'éxecution et d'administration



# Qu'est-ce que Docker ? #

Docker est une solution logicielle permettant de lancer certaines applications dans des conteneurs logiciels. A noter que , par défaut, les conteneurs Docker sont automatiquement stoppé si le processus à l'intérieur de l'application a finit ses tâches. 

- Une image Docker est un modèle en lecture seule, utilisé pour créer des conteneurs Docker. Elle est composée de plusieurs couches empaquetant toutes les installations, dépendances, bibliothèques, processus et codes d'application nécessaires pour un environnement de conteneur pleinement opérationnel.

example: l'image MySQL ( https://hub.docker.com/_/mysql ) contient l'application base de donnée MYSQL. Et pour éxécuter cette application, on doit créer un conteneur contenant cette image.

- Pour créer ses propres images, docker utilise les "dockerfile". 

Les dockerfile sont des fichiers décrivant des instructions permettant la construction d'une image.  

exemple:

![dockerfile](https://user-images.githubusercontent.com/97849927/202914759-2bec52c1-adbd-4cce-a759-3b7a96986a77.PNG)

Ici, on prend la dernière version de l'image de python 3.7 et on l'a modifie en créant des dossiers (mkdir) et d'autres opérations.  

Une fois cette image créée, on devra la lancé via un conteneur.  

- Pour lancer une application avec plusieurs conteneurs, on utilise le fichier docker-compose.yml (voir projet).

# Utilisation et commande de base  #


`docker pull [nom de l'image] ` pour télécharger une image depuis le Docker Hub  

`docker images` pour afficher toutes les images docker  

`docker rmi [id_image]` pour supprimer une image

`docker run -it -d [nom de l'image]` pour lancer un conteneur. Le paramètre `-it` pour lancer un shell interactif (via une ligne tty) et effectuer des actions depuis notre conteneur, et `-d` pour lancer le conteneur en arrière-plan et libérer ainsi la ligne de commande.  

`docker ps -a` pour afficher tous les conteneurs, ainsi que ceux stoppés

`docker stop [id_conteneur]` pour stopper un conteneur

`docker rm [id_conteneur]` pour supprimer un conteneur

`docker login` pour se connecter au DockerHub dans l'éventualité d'y upload une image.

`docker-compose up -d` lancer une application multi-conteneurs en arrière-plan



--------------------------------------------------------------------------------------------------------

Welcome to this section dedicated to containers. I will use the Docker tool in this section.


# What is a container ? #

<img width="557" alt="docker_concept" src="https://user-images.githubusercontent.com/97849927/202792608-61d215de-e837-48ba-b93c-5784dac1475a.png">


A container is a software solution for running processes in an environment isolated from the operating system, which bundles the code and all its dependencies so that the application runs quickly and reliably from one computing environment to another.


# What is Docker ? #

Docker is a software solution that allows you to run certain applications in software containers. Note that, by default, Docker containers are automatically stopped if the process inside the application has finished its tasks. 

A Docker image is a read-only model used to create Docker containers. It is composed of several layers packaging all the installations, dependencies, libraries, processes and application code needed for a fully operational container environment.

example: the MySQL image ( https://hub.docker.com/_/mysql ) contains the MYSQL database application.



# Basic usage and control  #

`docker pull [image name] ` to download an image from the Docker Hub  


`docker images` to display all docker images  


`docker rmi [image_id]` to delete an image


`docker run -it -d [image name]` to launch a container. The `-it` parameter to be able to launch an interactive shell and perform actions from our container, and `-d` to launch the container in the background and free the command line.  


`docker ps -a` to display all containers, including the stopped ones


`docker stop [container_id]` to stop a container


`docker rm [container_id]` to remove a container


`docker login` to connect to the DockerHub in case you want to upload an image.





