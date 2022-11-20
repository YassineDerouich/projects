(/!\ SEE BELOW FOR ENGLISH VERSION /!\ )

# Objectif du projet #

L'objectif est de déployer une instance EC2 pouvant communiquer à Internet et accessible à distance. Ce petit projet débutant est l'occasion de découvrir l'utilisation de Terraform.



Schéma de l'architecture :

![schema](https://user-images.githubusercontent.com/97849927/202782014-ed5c7e28-75c1-4486-9f5d-614715752fcf.png)

### > Fichier main.tf ###
- Déclaration du Cloud Provider (AWS)  
![image](https://user-images.githubusercontent.com/97849927/202905079-81198c45-7995-48bf-8973-7d6814c6497a.png)  

### > Fichier network.tf ###

-Création du VPC   
![image](https://user-images.githubusercontent.com/97849927/202808008-a884d700-8b75-412d-9543-5fd641c52c0e.png)

-Création d'un subnet public sortant par l'Internet Gateway  

![image](https://user-images.githubusercontent.com/97849927/202808119-a4702afe-9f7a-474c-bf8b-02614c88fa57.png)


-Création d'un subnet private pour protéger notre instance EC2  
![image](https://user-images.githubusercontent.com/97849927/202808068-c9fed2e0-5538-4186-9084-313ef5f9ddd7.png)

-Création de l'instance EC2

![ec2](https://user-images.githubusercontent.com/97849927/202909711-20bc0bb3-a40f-4ef3-aa33-c28ff2c0682b.jpg)


-Création de la NAT Gateway dans le subnet public pour permettre l'accès internet à l'instance EC2  


-Attribution d'une elastic IP à la Nat Gateway  

![image](https://user-images.githubusercontent.com/97849927/202808234-7faaceab-c439-449a-8bf8-7180d40f9f24.png)

-Définition des tables de routage pour permettre la sortie vers Internet  


-Création d'un role "SSM" attribuée à l'intance EC2pour permettre l'accès à distance directement sur la console AWS  


----------------------------------------------------------------------------------------------------------------------------------------------------

ENGLISH VERSION :

# Project goal #



The goal is to deploy an EC2 instance that can communicate with the Internet. This small beginner project is an opportunity to discover the use of Terraform.



Architecture schema :

![schema](https://user-images.githubusercontent.com/97849927/202782014-ed5c7e28-75c1-4486-9f5d-614715752fcf.png)


-Creation of the VPC   
-Creation of a private subnet to protect our EC2 instance  
-Creation of a public subnet outgoing through the Internet Gateway  
-Creation of the NAT Gateway in the public subnet to allow internet access to the EC2 instance  
-Assign an IP elastic to the Nat Gateway  
-Definition of the routing tables to allow the exit to the Internet  
-Creation of an "SSM" role assigned to the EC2 instance to allow remote access directly on the AWS console  


