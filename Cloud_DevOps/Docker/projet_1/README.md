/!\ See below for English version /!\  

# Objectif du projet #  

L'objectif est de déployer une application multi-conteneur (Wordpress + MySQL) à l'aide d'un fichier docker-composer.yml  

![dockerc](https://user-images.githubusercontent.com/97849927/202799743-6b6aa097-87e1-4676-91bf-94e966316505.png)

Premier service : MYSQL

On va utiliser une image de mysql en version 5.7 et partager le volume de l'image dans un dossier db_data.  
`services:
  db:
    image: mysql:5.7
    volumes:
      - db_data:/var/lib/mysql`

On y définit ensuite les informations de connexion, tels que les mot de passse, le nom de la bdd , le nom d'utilisateur.  

 `environment:
     MYSQL_ROOT_PASSWORD: somewordpress
     MYSQL_DATABASE: wordpress
     MYSQL_USER: wordpress
     MYSQL_PASSWORD: wordpress`
    
On commence ensuite avec le second service, un serveur wordpress. Notre servevur WP dépend d'une base de donnée MYSQL.  

`  wordpress:
    depends_on:
      - db
    `
    
On va utiliser la dernière version de l'image officielle de WordPress, et wordpress nécessite de tourner sur le port 80 de notre conteneur (mapping du port 8000 du système hôte pointant vers le port 80 du conteneur)

  `  image: wordpress:latest
    ports:
      - "8000:80"
   `
On définit les variables importantes pour une utilisation de WP tel que la BDD, le nom d'utilisateur WP, son mot de passe, et enfin le nom de la BDD WordPress.  
    environment:
      WORDPRESS_DB_HOST: db:3306
      WORDPRESS_DB_USER: wordpress
      WORDPRESS_DB_PASSWORD: wordpress
      WORDPRESS_DB_NAME: wordpress
      

