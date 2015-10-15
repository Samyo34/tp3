# tp3

Client - Serveur

Pour mettre en place une communication client/serveur, j'ai attribué à chaque fenetre un thread chargé des communications.
J'ai donc créé deux class héritant de QThread, une classe ThreadClient et une class ThreadServer.

La class ThreadClient :

Elle posède un attribut de type TcpSocket pour pouvoir récupérer les informations envoyées par le serveur via le réseau (internet ou local).
Le threadClient possède également un slot readData() qui s'execute lorsque la socket reçoit des données.
Pour permettre le l'execution du slot, j'ai connecté la socket (avec son signal readyRead()) avec le slot.
Le serveur envoi une seul information, celle indiquant qu'il faut changer de saison. Donc le slot, lorsqu'il s'execute, indique à la fenêtre à laquelle il est lié de changer de saison.
Pour ce faire, j'utilise un signal (nommé change()).
Dans chaque gameWindow, il y a donc un threadClient. J'ai lié les gameWindow au signal change() du thread pour qu'elles excute un slot leChangementCMaintenant().
Le slot leChangementCMaintenant() incrémente une variable saison de gameWindow (1 = ete, 2 = automne, 3 = hiver, 4 = printemps) pour simuler le passage à la saison suivante.
Dans la fonction render(), je change la couleur d'affichage en fonction de cette variable saison.

La class ThreadServer :

Cette class possède un attribut de type TcpServer qui permet des communications via le réseau, un Timer et un ensemble de client (vide au départ).
La class possède egalement un slot newClient() qui s'execute lorsque le TcpServer recoit un sigal newConnection() et qui ajoute le client à l'ensemble des clients.
Enfin, ThreadServer possède un slot emitSaison() qui envoi (via la socketServer) un ordre de changement de saison à l'ensemble des clients. Ce slot s'exectute lorsque le timer envoi un tick ( = au signal timeout()).
Cette class est un attribut d'une classe fenetreServeur qui a pour seul rôle d'être un serveur qui envoie toutes les x secondes un ordre de changement de saison.


La neige :

La class neige est constitué d'un ensemble de particules stocké dans un vecteur (QVector). Les particules sont un ensemble 5 coordonnées stockés dans un tableau à une dimension.
La class Particule possède une méthode draw() qui affiche les 5 points grace à un GL_POINT. La class Neige possède un méthode draw() qui affiche toutes les particules et une méthode update() qui a pour but de changer les coordonnées des particules afin de simuler la chute des particules et gérer la collision avec le terrain.
Malheursement je n'arrive pas simuler cette chute, les flocons ne sont pas sur le bonne axe.

(idem pour la pluie)
