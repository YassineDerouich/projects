(/!\ SEE BELOW FOR ENGLISH VERSION /!\ )

# Objectif du projet #

L'objectif est de déployer une instance EC2 pouvant communiquer avec Internet et accessible à distance. 

Ce petit projet débutant est l'occasion de découvrir l'utilisation de Terraform.



Schéma de l'architecture :

![image](https://user-images.githubusercontent.com/97849927/202912909-55736596-4c4c-4bf5-a6d6-ef8fbe7b0bbe.png)


1. Nous allons dans un premier temps créer un VPC. 
2. Ensuite nous créérons un subnet public et un subnet private contenant l'instance EC2.
3. Notre subnet public relié à l'internet gateway permettra, grâce à la création d'une Nat Gateway, de faire sortir vers internet notre instance du subnet privé.
4.  Nous souhaitons également nous connecter à distance à la machine, nous allons utiliser le service AWS SSM. Pour se faire, nous devons créer un rôle avec des permissions qui lui sont attachés.
5. Enfin nous créerons un profil d'instance, qui contiendra notre rôle, et qui sera attribué à notre instance EC2.

### > Fichier main.tf ###
- Déclaration du Cloud Provider (AWS)  
![image](https://user-images.githubusercontent.com/97849927/202905079-81198c45-7995-48bf-8973-7d6814c6497a.png)  

### > Fichier network.tf ###

- Création du VPC qui contiendra toute notre architecture, il aura le réseau 10.0.0.0/16   
![vpc](https://user-images.githubusercontent.com/97849927/202911525-2a9bc443-8515-419f-b2ef-19a05f9e05d8.png)  

- Création d'un subnet public pour sortir d'internet, et d'un subnet privé qui contiendra notre instance EC2.

![subnet](https://user-images.githubusercontent.com/97849927/202911640-6fa17146-6bd2-43c3-87a1-f87b97dcdcdc.PNG)  


- Création de l'internet gateway reliée au subnet public, et de l'elastic IP associé à la nat gateway pour fournir une IP publique à notre instance EC2.

![igw_eip_ngw](https://user-images.githubusercontent.com/97849927/202911687-6ced5d3d-2291-41ab-b9c7-e4961b79a957.PNG)  


- Création des tables de routage pour les 2 subnets. Le subnet private balancera son traffic vers la ngw , et le public subnet balancera son traffic vers l'igw.

![route_public_et_route_private](https://user-images.githubusercontent.com/97849927/202911702-91ade934-8f44-44d8-b8ad-5666fc9ca7ca.PNG)  


- Association de chaque table de routage avec son subnet approprié  

![route_association](https://user-images.githubusercontent.com/97849927/202911733-1b1a86d5-7bbe-4e6d-a285-bda7e8a21648.PNG)  

### > Fichier iam.tf ###  


- Création du rôle "ec2-ssm-access" et de la policy  "SSMPolicy"

![iam_role_policy](https://user-images.githubusercontent.com/97849927/202911807-5256ebe4-6e34-4062-8f79-b43bd88fa2a1.PNG)  

- Attachement de cette policy au rôle créée, et création d'un profil d'instane qui sera délivré à notre instance EC2 pour utiliser SSM.  

![iam_policy_attachment_and_instance_profile](https://user-images.githubusercontent.com/97849927/202911842-44cf2da6-1926-4944-924a-c07745593b8d.PNG)  


### > Fichier ec2.tf ###  

-Création de l'instance EC2 

![ec2](https://user-images.githubusercontent.com/97849927/202911761-64166cba-41e6-4a2f-baa4-a0cfa7748749.jpg)


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


