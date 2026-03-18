#include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
	static const int N = 10;
	double arr[N] = {2.3, 6.7, 5.8, 1.1, 9.2, 6.4, 17.5, 33.3, 45.6, 13.3};
	
	double massimo = arr[0];
	double minimo = arr[0];
	double somma= 0.0;
	double somma_scarti= 0.0;
	
	
	//calcolo il valore del massimo, del minimo e della somma
	
	for (int i = 0; i<N; i++) {
		minimo = std::min(minimo, arr[i]);
		massimo= std::max(massimo, arr[i]);
		somma=somma+ arr[i];
	}
	
	double media= somma / N;
	
	for (int i = 0; i<N; i++) {
		double differenze = arr[i]- media;
		somma_scarti = somma_scarti + (differenze * differenze);
	}
	double varianza = somma_scarti / N;
	double deviazione_standard= std::sqrt(varianza);
	
	std::cout << "Minimo: " <<minimo << "\n";
	std::cout << "Massimo: "<<massimo << "\n";
	std::cout << "Media: "<<media <<"\n";
	std::cout << "Deviazione standard: "<<deviazione_standard <<"\n";
	
	return 0;
	
}
	
	