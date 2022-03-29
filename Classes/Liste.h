#ifndef LISTE_H
#define LISTE_H 

template<class T> class Iterateur;

//structure de la cellule de la liste
template<class T> struct Cellule
{
	T valeur;
	Cellule<T> *suivant;
};

template<class T> class Liste
{ 

	protected: 
		Cellule<T> *_pTete;

	public: 
		// constructors
		Liste(); 
		Liste(const Liste<T>&); 
		virtual ~Liste();  
		 
		// fonctions
		bool estVide() const;
		int getNombreElements() const;

		// affichage 
		void Affiche() const; 

		// insertion // retire
		virtual void insere(const T &);
		const T retire(const int);

		// setters--getters
			Cellule<T>* getTete() const;
			void setTete(const Cellule<T>*);//const_cast --> permet de caster la variable en CONST 
		

		// Operators
	    const Liste<T>* operator=(const Liste<T>&);

	    //pour permettre à l'itérateur de modifier la cellule tete de la liste si besoin
	    friend class Iterateur<T>;
};

#endif 
// valeurReturn ligne 149 dans le .cpp peut retourner une cellule à NULL