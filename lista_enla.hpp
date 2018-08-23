#ifndef LISTA_ENLA_HPP
#define LISTA_ENLA_HPP
#include <cassert>

template<typename T>
class Lista
{
	struct nodo;
public:

	typedef nodo* posicion;
	Lista();
	Lista(const Lista<T>& L);
	Lista<T>& operator =(const Lista<T>& L);

	void insertar(const T& x, posicion p);
	void eliminar(posicion p);
	T& elemento(posicion p)const;
	const T& elemento(posicion p)const;

	posicion primera()const;
	posicion ultima()const;
	posicion siguiente(posicion p)const;
	posicion anterior(posicion p)const;
	posicion buscar(const T& x)const;

	~Lista();

private:

	struct nodo
	{
		T elto;
		nodo* sig;
		nodo(const T& x, nodo* p =0): elto{x}, sig{p}{} 
	};

	nodo* L;

	void copiar(const Lista<T>& L);
};


template<typename T>
void Lista<T>::copiar(const Lista<T>& l)
{
	L = nodo(T()); //cabecera
	nodo* q = L;
	for(Lista<T>::posicion p = l.L->sig; p; p = p->sig)
		q=q->sig= nodo(p->elto);


}


template<typename T>
Lista<T>::Lista():
L{new nodo(T())}; // crear cabecera


template<typename T>
inline Lista<T>::Lista(const Lista<T>::Lista& L){copiar(L);}

template<typename T>
xLista<T>& Lista<T>::operator =(const Lista<T>& l)
{
	if(this != &L)
	{
		this->~Lista();
		copiar(l);
	}

	return *this;
}

template<typename T>
inline void Lista<T>::insertar(const T& x, Lista<T>::posicion p)
{
	p->sig = new nodo(x,p->sig);
}

template<typename T>
inline void Lista<T>::eliminar(Lista<T>::posicion p)
{
	assert(p->sig) // no es fin;

	nodo* q = p->sig;
	p->siguiente = q->siguiente;
	delete q;
}

template<typename T>
inline const T& Lista<T>::elemento(Lista<T>::posicion p)const
{
	assert(p->sig) // p no es fin

	return p->sig->elto;

}

template<typename T>
Lista<T>::posicion Lista<T>::buscar(const T& x)const
{
	nodo*p = L->sig; // nos pasamos la cabecera

	while(p && p->elto != x )
		p= p->sig;

	return p;
}

template<typename T>
Lista<T>::posicion siguiente(Lista<T>::posicion p)const
{
	assert(p->sig);
	return p->sig;
}

template<typename T>
Lista<T>::posicion anterior(Lista<T>::posicion p)const
{
	assert(p != L);
	nodo* q = L->sig;

	while(p!= p->sig)
		q= q->sig;

	return q;
}


template<typename T>
Lista<T>::posicion Lista<T>::fin()const
{

	nodo* p = L;

	while(p)
		p= p->sig;

	return p;
}

template<typename T>
inline Lista<T>::posicion Lista<T>::primera()const
{
	return L;
}

template<typename T>
Lista<T>::~Lista()
{
	nodo* p = L;

	while (L)
	{

		p = p->sig;
		delete L;
		L = p;
	}

}

#endif