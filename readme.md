# CAOStar Game in C++
Le projet consiste à créer un logiciel de CAO en C++, et ce à l’aide du logiciel QtCreator. Le logiciel doit
permettre au concepteur de véhicules de dessiner un véhicule à partir de formes élémentaires de couleur proposée
dans une boîte à outils. L’utilisateur peut également déplacer le véhicule qu’il aura créé selon une direction
choisie (horizontale ou verticale).
En vue d’une bonne intégration du logiciel, la société "ToutVéhicule" souhaite une interface homme-machine
conviviale. Plus précisément, l’interface graphique qui s’affiche au démarrage comporte quatre options de menu
à savoir "Composer", "Déplacer", "Arrêter" et "Quitter".
L’option "Composer" constitue le coeur même du logiciel. Elle permet de sélectionner à l’aide de la souris, des
formes dans la boîte à outils et de les faire glisser dans la zone de composition afin de créer le véhicule.
Le bouton "Valider" permet quant à lui de valider cette composition : la fenêtre principale s’affiche alors avec
le véhicule placé en son centre.
En ce qui concerne les deux boutons assurant la gestion de la suppression, il y aura un bouton "Cancel All"
permettant l’annulation complète du véhicule commencé et un second bouton "Cancel" qui supprimera uniquement
la dernière pièce placée.
L’option "Déplacer" quant à elle, permet d’obtenir un menu déroulant avec les options "Horizontal" et "Vertical".
Une fois l’une de ces options choisies, le véhicule se déplace dans la fenêtre de dessin, dans la direction
sélectionnée et rebondit contre les bords jusqu’à ce que l’utilisateur sélectionne l’option "Arrêter" du menu.
