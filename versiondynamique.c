#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*Utile pour les fonctions avec des strings*/
#include "../lib/libgraphique.h" /*Bibliothèque graphique utile pour la version graphique*/

int compter_nombre_totale(float liste[]){ /*Fonction pour compter le nombre total de mois, ou de logs appartir d'une liste */
	int i;
	int totale = 0;
	for(i=0;i<12;i++){ /*on a constaté que compter le nombre de ligne n'est pas precis et efficace, car chaque ligne ne correspond forcement pas a un log*/
		totale = totale + liste[i];}/*on aditionne les valeur de chaque mois ensembre*/
    return totale;}

void compter_nombre_mois(float list[]){ /*cette fonction va permettre de calculer le nombre totale de chaque mois et le mettre dans une liste*/
	int taille = 3;
	char tab[taille];

	FILE *fichier = fopen("/var/log/apache2/access.log","r"); /*Ouverture du fichier access.log*/

	while(fgetc(fichier) != EOF){ /*Tant qu'on n'est pas à la fin du fichier (EOF)*/
		fscanf(fichier,"%*[^/]/%[A-Za-z]%*[^\n]\n", tab); /*lis chaque ligne du fichier a chaque fois, ce qu'il y a entre "/" et une retour a la ligne, elle ne prend que les alphabets*/

		if(strcmp(tab, "Jan") == 0){ /*Si "Jan" apparait dans la lecture*/
			list[0]++;}   /* alors incrémentation du tableau list[0], qui recense le nombre de fois qu'apprait "Jan" */
		if(strcmp(tab, "Feb") == 0){
			list[1]++;}
		if(strcmp(tab, "Mar") == 0){
			list[2]++;}
		if(strcmp(tab, "Apr") == 0){
			list[3]++;}
		if(strcmp(tab, "May") == 0){
			list[4]++;}
		if(strcmp(tab, "Jun") == 0){
			list[5]++;}
		if(strcmp(tab, "Jul") == 0){
			list[6]++;}
		if(strcmp(tab, "Aug") == 0){
			list[7]++;}
		if(strcmp(tab, "Sep") == 0){
			list[8]++;}
		if(strcmp(tab, "Oct") == 0){
			list[9]++;}
		if(strcmp(tab, "Nov") == 0){
			list[10]++;}
		if(strcmp(tab, "Dec") == 0){
			list[11]++;}}
	rewind(fichier);
	fclose(fichier);/* fermeture du fichier */
}

void pourcent(const float ListMois[], float ListPourcent[], float nbtotale){ /*calcule le pourcentage de chaque mois */
	int i;
	for(i=0;i<12;i++){
		ListPourcent[i] = (ListMois[i]*100)/nbtotale;}  /*Le tableau listpourcent est  affecté par le pourcentage de chaque mois*/
	}

		/*cette fonction affiche la première date de connection avec un pointeur*/
char* premierdate(char *premier){
	FILE *pointeur = fopen("/var/log/apache2/access.log","r");   /*Ouverture du fichier access.log*/
	char date[100];
	fscanf(pointeur,"%*[^[][%s%*[^/]/", date); /*scan dans le fichier avec le pointeur et met la chaine de carractere dans la list date qui est une list de chaine de caractere*/
	rewind(pointeur);
	fclose(pointeur);
	sprintf(premier,"%.*s", 11, date); /* 11 premiers carractere du variable date */
	return premier;}


void affichage(float list[], int totale){ /*Fonction Version Texte*/


	char date[100];
	premierdate(date); /*appel de  la fonction premierdate(date)*/

	printf("Depuis le %s on a enregistre %d connexions.\n", date, totale);
	printf("  Janvier: %.2f%%\n", list[0]);
	printf("  Fevrier: %.2f%%\n", list[1]);
	printf("     Mars: %.2f%%\n", list[2]);
	printf("    Avril: %.2f%%\n", list[3]);
	printf("      Mai: %.2f%%\n", list[4]);
	printf("     Juin: %.2f%%\n", list[5]);
	printf("  Juillet: %.2f%%\n", list[6]);
	printf("     Aout: %.2f%%\n", list[7]);
	printf("Septembre: %.2f%%\n", list[8]);
	printf("  Octobre: %.2f%%\n", list[9]);
	printf(" Novembre: %.2f%%\n", list[10]);
	printf(" Decembre: %.2f%%\n", list[11]);}


  /*Création de la fonction de la version graphique*/
void versiongraphique(float pourcent[], int totale) {
		/*declaration des variables nécessaires*/
	int pointX = 30; /*point coordonnes de abscisse x */
	int i;
	float listHauteur[12]; /*tableau servant à la hauteur du rectangle*/
	float listY[12]; /*tableau servant à la position Y du rectangle sur le repère*/
	char str[1024];
	Point p = {30,50}; /*point */

		/*elle cherche la premiere date de connection*/
	char date[100];
	premierdate(date);

		/* ecrit et prépare le texte  afficher */
	sprintf(str, "Depuis le %s on a enregistre %d connexions.",date,totale);

		/* ouvre la fenetre graphique */
	ouvrir_fenetre(430,350);
	dessiner_rectangle((Point){0,0},430,350,blanc);
	afficher_texte(str,15,p,noir);

	p.y=300;
	afficher_texte(" Jan  Fev  Mar  Avr  Mai  Juin  Juil  Aou  Sep  Oct  Nov  Dec",14,p,vert);  /*Affiche les mois en taille 14 et de couleur verte*/


	for(i=0; i<12; i++){  /*Pour i = 0 allant jusqu'à 12 (nombre max de mois), i s'incrémente de 1*/
		listHauteur[i] = (pourcent[i]*300)/40; /*le tableau litHauteur[i] de paramètre i prend la valeur du tableau pourcent[i]*300/40, on choisit le multiplicateur 40 pour que le rectangle soit plus grand*/
		listY[i] = 300-listHauteur[i]; /*cela va permettre de definir la bonne coordonnes de abscisse pour bien tracer le rectangle proportionnelement sans depasser les bornes et etre dans la bonne position*/
		dessiner_rectangle((Point){pointX,listY[i]},30,listHauteur[i],orange); /*Dessine un rectangle */
		sprintf(str, "%.0f", pourcent[i]);
		afficher_texte(str,14,(Point){pointX+5,listY[i]},blanc);
		pointX = pointX+31;} /*cela a permettre de ajouter un ecart entre chaque baton*/

	actualiser(); /*Actualiser les changements*/
	attendre_clic();
	fermer_fenetre();} /*Fermer la fenetre après le clic*/

void lecture_style()
{

  FILE *fd;
  char str[1024];
  if ((fd = fopen("aecrire.html","r")) == NULL) /*Si le fichier "aecrire.html" est vide*/
    fprintf(stderr,"ERREUR DE CHARGEMENT DE FICHIER\n"); /*On affiche le message d'erreur*/
  else {
    while (!feof(fd)){ /*Tant qu'on n'est pas à la fin du fichier*/
      fgets(str,1024,fd); /*fgets lit les chaines de caractères du fichier*/
      printf("%s",str); /*affiche les caractères du fichier*/

    }
    fclose(fd);
  }
}

void versionweb(float pourcent[], int totale) /*Fonction web*/
{
	int i;
	float listHauteur[12];
	int ecart = 10;

	char date[100];    /* recupere la première date*/
	premierdate(date);

	for(i=0; i<12; i++){
		listHauteur[i] = (pourcent[i]*300)/40;} /* calcule la longeur de chaque baton*/

	printf("Content-type: text/html\n\n");  /*Début du HTML à afficher*/

	printf("<!doctype html>\n");
	printf("<html lang=\"fr\">\n");
	printf("<body>\n");

	lecture_style();

	printf("Depuis le %s on a enregistr&eacute; %d connexions.<br>\n",date, totale);

	printf("<div id = \"vertgraph\">\n");
	printf("    <ul>\n");
/*
 
 */
	for(i=0;i<12;i++){
		if (listHauteur[i]>25){
			printf("        <li style=\"left: %dpx;  height: %fpx;\">%.0f</li>\n", ecart, listHauteur[i], pourcent[i]); /*si la hauteur est superieur a 25 alors on l'affiche la valeur numerique */
		}
		else
		{
			printf("        <li style=\"left: %dpx;  height: %fpx;\"> </li>\n",ecart, listHauteur[i]);/*sinon on ne l'affiche pas*/
		}
		ecart = ecart + 31;}




	printf("</html>\n");
	printf("</body>\n\n");
/*fin du HTML à afficher*/
}


int main(int argc, char* argv[])
{

	int nbtotale = 0; /*nombre totale de log initialisé a 0*/
 	float listMois[12];/*la liste de mois est là pour contenir le nombre totale de chaque mois*/
 	float listpourcent[12]; /*cette liste permet de contenir le nombre en poucentange de chaque mois*/

    compter_nombre_mois(listMois);/*on commence par compter le nombre de chaque mois et les mettre dans une liste */
	nbtotale = compter_nombre_totale(listMois);/*ensuite on essaye de calculer le nombre totale de mois ou de logs en additionnant chaque element de la listMois*/
	pourcent(listMois, listpourcent, nbtotale);/*enfin, a partir des elements definit on va les utiliser pour calculer une list de pourcentage de chaque mois*/

    if (argc > 1) {
		if (strcmp(argv[1],"-txt")==0) {    /*Si l'utilisateur exécute le programme avec -txt*/
			affichage(listpourcent, nbtotale); /*Affiche version texte*/
    }
		if (strcmp(argv[1],"-gr")==0){ /*Si l'utilisateur exécute le programme avec -gr*/
			versiongraphique(listpourcent, nbtotale);} /*Affiche version graphique*/

    }	else {
			versionweb(listpourcent,nbtotale); /*Autrement, affiche la version web*/

    }

    return EXIT_SUCCESS;
}








