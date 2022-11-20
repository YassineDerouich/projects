(/!\ SEE BELOW FOR ENGLISH VERSION /!\ )

Bienvenue dans cette section dédiée au déploiement d'une infrastructure as code associée à AWS. 

# Qu'est-ce que Terraform ? #

![schema]( https://miro.medium.com/max/1400/1*JPoEFqmHdt-G4D-MefftRQ.png )

Terraform est un outil d'infrastructure as code utilisant une syntaxe HCL (HashiCorp Configuration Language), qui décrit l'infrastructure cloud ou sur site qu'on souhaite déployer grâce à des fichiers terraform ".tf" . Terraform génère ensuite un plan de tout ce qu'on souhaite déployer, et exécute le plan pour mettre à disposition l'infrastructure.

Terraform est compatible avec un grand nombre de Cloud Providers. La liste est disponible sur https://registry.terraform.io/browse/providers
ainsi que des explications sur leur implémentation.

Par exemple, au lieu d'aller sur la console AWS pour déployer une instance EC2 Linux grâce à Terraform.

Dans notre fichier tf on peut y écrire

![ec2_schem](https://user-images.githubusercontent.com/97849927/202903671-46ceb07f-1c83-4177-9a8b-aba51dc948b8.jpg)


# Utilisation & commandes de base #

Dans le cadre d'AWS, il est nécessaire de configurer ses Access Keys et Secret Keys avant d'utiliser Terraform, en ne les affichant pas dans son code, bien sûr.

Installation sur Linux, voir https://computingforgeeks.com/how-to-install-terraform-on-linux/

Après installation de terraform , il faudra créer un dossier pour l'infrastructure et y créer les fichiers terminant en .tf (format spécifique à Terraform).

Sur ces fichiers on y décrira l'infrastructure à déployer. Par exemple, pour AWS on peut créer un fichier network.tf qui déploiera seulement les éléments réseaux (VPC,subnet,gateway,etc.) et un autre fichier ec2.tf qui se chargera de déployer les instances EC2. 

![terraform_1](https://user-images.githubusercontent.com/97849927/202788209-cac54007-79e5-46a2-bc1a-b2dbde78adff.png)

En 1er lieu on déclarera notre cloud provider , dans un fichier main.tf 

![image](https://user-images.githubusercontent.com/97849927/202902930-4a0655ca-c4ab-4892-a15a-99e6ee33f0c4.png)


Après avoir décris son infrastructure, voici les commandes de base:

`terraform init` pour initialiser le dossier où se trouve Terraform afin de lui indiquer où se trouve tous nos fichiers .tf


`terraform plan` pour afficher un plan de ce que Terraform prévoit de déployer en fonction de vos instructions décris dans vos fichiers .tf

`terraform apply` pour appliquer la configuration

`terraform destroy` pour supprimer toute l'infrastructure déployée

----------------------------------------------------------------------------------------------------------------------------------------------------

ENGLISH VERSION :

Welcome to this section dedicated to the deployment of an infrastructure as code deployment associated to AWS.

# What is Terraform? #

![schema]( https://miro.medium.com/max/1400/1*JPoEFqmHdt-G4D-MefftRQ.png )

Terraform is an infrastructure-as-code tool using a HashiCorp Configuration Language (HCL) syntax formation, which describes the desired cloud or on-premises infrastructure for running an application with its "end state". Terraform then generates a plan to achieve that end state and executes the plan to provision the infrastructure.

# Usage & basic commands #

In the context of AWS, it is necessary to configure its Access Keys and Secret Keys before using Terraform, by not displaying them in its code, of course.

After installation, a folder must be created for the infrastructure and the files ending in .tf (Terraform specific format) must be created there, describing the infrastructure.

![terraform_1](https://user-images.githubusercontent.com/97849927/202788209-cac54007-79e5-46a2-bc1a-b2dbde78adff.png)


After describing the infrastructure, here are the basic commands:

-terraform init to initialize the folder where Terraform is located in order to tell it where all our .tf files are located


`terraform plan` to display a plan of what Terraform plans to deploy according to your instructions

`terraform apply` to apply the configuration

`terraform destroy` to remove all deployed infrastructure

