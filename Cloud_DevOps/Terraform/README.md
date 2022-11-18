Bienvenue dans cette section dédiée au déploiement d'une infrastructure as code associée à AWS.

L'objectif est de déployer une instance EC2 pouvant communiquer à Internet. Ce petit projet débutant est l'occasion de découvrir l'utilisation de Terraform.



Schéma de l'architecture :

![schema](https://user-images.githubusercontent.com/97849927/202782014-ed5c7e28-75c1-4486-9f5d-614715752fcf.png)


-Création du VPC 
-Création d'un subnet private pour protéger notre instance EC2
-Création d'un subnet public sortant par l'Internet Gateway 
-Création de la NAT Gateway dans le subnet public pour permettre l'accès internet à l'instance EC2 
-Attribution d'une elastic IP à la Nat Gateway 
-Définition des tables de routage pour permettre la sortie vers Internet 
-Création d'un role "SSM" attribuée à l'intance EC2pour permettre l'accès à distance directement sur la console AWS
