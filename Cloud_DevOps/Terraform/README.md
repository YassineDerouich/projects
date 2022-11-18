(/!\ SEE BELOW FOR ENGLISH VERSION /!\ )

Bienvenue dans cette section dédiée au déploiement d'une infrastructure as code associée à AWS. 

# Qu'est-ce que Terraform ? #

![schema]( https://miro.medium.com/max/1400/1*JPoEFqmHdt-G4D-MefftRQ.png )

Terraform est un outil d'infrastructure as code utilisant un formation de syntaxe HCL (HashiCorp Configuration Language), qui décrit l'infrastructure cloud ou sur site souhaitée pour l'exécution d'une application avec son "état final". Terraform génère ensuite un plan permettant d'atteindre cet état final et exécute le plan pour mettre à disposition l'infrastructure.

# Utilisation & commandes de base #

Dans le cadre d'AWS, il est nécessaire de configurer ses Access Keys et Secret Keys avant d'utiliser Terraform, en ne les affichant pas dans son code, bien sûr.

Après installation, il faudra créer un dossier pour l'infrastructure et y créer les fichiers terminant en .tf (format spécifique à Terraform), en y décrivant l'infrastructure.

![terraform_1](https://user-images.githubusercontent.com/97849927/202788209-cac54007-79e5-46a2-bc1a-b2dbde78adff.png)


Après avoir décris son infrastructure, voici les commandes de base:

-terraform init pour initialiser le dossier où se trouve Terraform afin de lui indiquer où se trouve tous nos fichiers .tf


-terraform plan pour afficher un plan de ce que Terraform prévoit de déployer en fonction de vos instructions

-terraform apply pour appliquer la configuration

-terraform destroy pour supprimer toute l'infrastructure déployée

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


-terraform plan to display a plan of what Terraform plans to deploy according to your instructions

-terraform apply to apply the configuration

-terraform destroy to remove all deployed infrastructure

