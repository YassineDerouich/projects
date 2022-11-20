/!\ See below for English version /!\  

# Objectif du projet #  

- L'objectif est de déployer une application multi-conteneur (Wordpress + MySQL) à l'aide d'un fichier docker-compose.yml  

![dockerc](https://user-images.githubusercontent.com/97849927/202799743-6b6aa097-87e1-4676-91bf-94e966316505.png)

# Premier service : MYSQL #

#### On va utiliser une image de mysql en version 5.7 et partager le volume de l'image dans un dossier db_data.  ####

![image](https://user-images.githubusercontent.com/97849927/202802596-ce5119a0-3661-4898-80a5-2094f964a77d.png)

#### On y définit ensuite les informations de connexion, tels que les mot de passse, le nom de la bdd , le nom d'utilisateur.  ####

 ![image](https://user-images.githubusercontent.com/97849927/202802638-4c15c451-9449-4796-a1bc-004706962dcd.png)

    
# Deuxième service : un serveur wordpress # 

#### Notre servevur WP dépend d'une base de donnée MYSQL####

![image](https://user-images.githubusercontent.com/97849927/202802681-1e66b7b1-ffdc-4523-a1f9-043c1d989666.png)

    
#### On va utiliser la dernière version de l'image officielle de WordPress, et wordpress nécessite de tourner sur le port 80 de notre conteneur (mapping du port 8000 du système hôte pointant vers le port 80 du conteneur)####

 ![image](https://user-images.githubusercontent.com/97849927/202802745-ca66f901-3841-4c98-b775-9200efa6ce5b.png)

 
#### On définit les variables importantes pour une utilisation de WP tel que la BDD, le nom d'utilisateur WP, son mot de passe, et enfin le nom de la BDD WP ####    
 ![image](https://user-images.githubusercontent.com/97849927/202802784-649873ae-5ae3-4ce6-9504-7d5c14721e41.png)
 
Lancement des conteneurs `docker-compose up -d`


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
ENGLISH VERSION :

# Project Goal  

The objective is to deploy a multi-container application (Wordpress + MySQL) using a docker-compose.yml file  

![dockerc](https://user-images.githubusercontent.com/97849927/202799743-6b6aa097-87e1-4676-91bf-94e966316505.png)

# First service : MYSQL #

#### We will use an image of mysql in version 5.7 and share the image volume in a db_data folder.  ####

![image](https://user-images.githubusercontent.com/97849927/202802596-ce5119a0-3661-4898-80a5-2094f964a77d.png)

#### Then we define the connection information, such as the password, the name of the database, the user name.  ####

 ![image](https://user-images.githubusercontent.com/97849927/202802638-4c15c451-9449-4796-a1bc-004706962dcd.png)

    
# Second service : a wordpress server # 

#### Our WP server depends on a MYSQL database####

![image](https://user-images.githubusercontent.com/97849927/202802681-1e66b7b1-ffdc-4523-a1f9-043c1d989666.png)

    
#### We will use the latest version of the official WordPress image, and wordpress needs to run on port 80 of our container (mapping from port 8000 of the host system to port 80 of the container)####

 ![image](https://user-images.githubusercontent.com/97849927/202802745-ca66f901-3841-4c98-b775-9200efa6ce5b.png)

 
#### We define the important variables for the use of WP such as the DB, the WP user name, his password, and finally the name of the WP DB ####    
 ![image](https://user-images.githubusercontent.com/97849927/202802784-649873ae-5ae3-4ce6-9504-7d5c14721e41.png)


