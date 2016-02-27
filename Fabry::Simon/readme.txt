	CPP
	4. C'est une fonction virtuelle. Il faut rajouter =0 à la fin de la déclaration. On la déclare de cette façon: virtual void executer() const = 0;
	5. C'est le polymorphisme. Il faut déclarer la même fonction dans les classes filles avec le même prototype. Le tableau contient des pointeurs vers les objets. Cela permet de la résolution dynamique des liens. En Java, le tableau contiendrait des références vers les objets.
	6. Il faut déclarer la relation d'héritage en public
	8. Cela permet d'ajouter un même objet à plusieurs groupes différents


	Swing
	1. Il faut redimensionner la fenêtre pour faire afficher l'intégralité du texte