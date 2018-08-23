#ifndef LISTA_VEC_HPP
#define LISTA_VEC_HPP
#include <cassert>

template<typename T>
class Lista
{
public:

	typedef int posicion;
	explicit Lista(int tamaMax);
	Lista(const Lista<T> L);
	Lista<T>& operator =(const Lista<&> L);

	void insertar(const T& x, posicion p);
	void eliminar(posision p);
	const T& elemento(posision p) const;
	T& elemento(posicion p); // lectura escritura
	posicion buscar(const T& x)const;

	posicion siguiente(posicion p)const;
	posicion anterior(posicion p)const;
	posicion primera()const;
	posicion fin()const;

	~Lista();

private:

	T* elementos;
	int Lmax;
	int n;



};


template<typename T>
Lista<T>::Lista(int tamaMax):
Lmax{tamaMax},
n{0}
elementos{new T[tamaMax]}
{}

template<typename T>
Lista<T>::Lista(const Lista<T>& L):
Lmax{L.Lmax},
n{L.n},
elementos{new T[L.Lmax]}
{

	for(Lista<T>::posicion p= 0 ; Lista<T>::posicion p<n; p++)
		elementos[p]= L.elementos[p];
}

template<typename T>
Lista<T>& Lista<T>::operator =(const Lista<T>& L)
{
	if(this!=&L)
	{
		if(L.Lmax != Lmax)
		{
			Lmax = L.Lmax;
			delete [] elementos;
			elementos = new T[Lmax];
		}

		n = L.n;

		for(Lista<T>::posicion p= 0; p <n ; p++)
			elementos[p] = L.elementos[p];
	}

	return *this;
}


template<typename T>
void Lista<T>::insertar(const T& x, Lista<T>::posicion p)
{

	assert(p>=0 & p <=n);
	assert(n<Lmax);

	for(Lista<T>::posicion q = p; q <=n ; q++)
		elementos[q+1] = elementos[q];

	elementos[p]= x;

	n++;

}


template<typename T>
void Lista<T>::elminar(Lista<T>::posicion p)
{

	assert(p >= 0 && p <n)

	n--;

	for(Lista<T>::posicion q = n ; q>p; q --)
		elementos[q-1] = elementos[q];

}

template<typename T>
inline const T& posicion(Lista<T>::posicion p)const
{
	assert(p<=0 && p >n)
	return elementos[posicion];
}

template<typename T>
Lista<T>::posicion Lista<T>::buscar(const T& x)const
{
	Lista<T>::posicion p = 0;

	while( p < n && elmentos[p] != x)
		p++;
	
	return p;
}
template<typename T>
inline typename Lista<T>::posicion Lista<T>::siguiente(Lista<T>::posicion p)const
{
	assert(p>=0 && p<n)

	return p+1;

}


template<typename T>
inline typename Lista<T>::posicion Lista<T>::anterior(Lista<T>::posicion p)const
{
	assert(p>0 && p<=n)

	return p-1;

}

template<typename T>
inline Lista<T>::posicion Lista<T>::primera()const {return 0;}

template<typename T>
inline typename Lista<T>::posicion Lista<T>::fin()const {return n;}

template<typename T>
inline ~Lista(){ delete [] elementos;}

#endif