#include <iostream>
#include "razionali.hpp"

int main(void)
{
	//quando il denominatore è uguale a 0
	razionali<int> inf_pos(5,0);
	std::cout << "4/0 = " <<inf_pos << "\n";
	
	razionali<int> inf_neg(-6,0);
	std::cout << "(-6)/0 = " <<inf_neg << "\n";
	
	razionali<int> NaN(0,0);
	std::cout << "0/0 = " <<NaN << "\n";

	//semplificazione
	razionali<int> r(4,8);
	std::cout << "Frazione semplifata: 4/8 = " << r << "\n";
	
	//operazione tra 0 al numeratore e un numero al denominatore
	razionali<int> zero(0,5);
	std::cout << "0/5 = " << zero <<"\n";
	
	//operazioni tra un numero e 1 al donominatore
	razionali<int> c(4,1);
	std::cout << "4/1 = " << c <<"\n";
	
	//operazioni aritmetiche
	razionali<int> a(2,7);
	razionali<int> b(3,5);
	razionali<int> neg((-1),3);
	razionali<int> neg2 (1,(-3));
	
	std::cout << " 2/7 = " << a <<"\n";
	std::cout << " -(1/3) = " << neg << "\n";
	std::cout << " -(1/3) = " << neg2 << "\n";
	
	//svolgo le operazione tra due numeri
	std::cout << a << "+" << b << "=" << (a+b) << "\n";
	std::cout << a << "-" << b << "=" << (a-b) << "\n";
	std::cout << a << "*" << b << "=" << (a*b) << "\n";
	std::cout << a << "/" << b << "=" << (a/b) << "\n";
	
	//operazioni con lo 0
	std::cout << a << "/ 0 = " << a / zero << "\n";
	std::cout << "0 / " << a << " = " << zero / a << "\n";
	
	//operazioni tra un numero e un numero con denominatore uguale a 0
	//con inf_pos
	std::cout << a << " + Inf = " << a + inf_pos << "\n";
	std::cout << a << " - Inf = " << a - inf_pos << "\n";
	std::cout << a << " * Inf = " << a * inf_pos << "\n";
	std::cout << a << " / Inf = " << a / inf_pos << "\n";
	std::cout << " Inf - " << a << " = " << inf_pos - a << "\n";
	std::cout << " Inf / " << a << " = " << inf_pos / a << "\n";
	//con inf_neg
	std::cout << a << " + (-Inf) = " << a + inf_neg << "\n";
	std::cout << a << " - (-Inf) = " << a - inf_neg << "\n";
	std::cout << a << " * (-Inf) = " << a * inf_neg << "\n";
	std::cout << a << " / (-Inf) = " << a / inf_neg << "\n";
	std::cout << " (-Inf) - " << a << " = " << inf_neg - a << "\n";
	std::cout << " (-Inf) / " << a << " = " << inf_pos / a << "\n";
	//con NaN
	std::cout << a << " + NaN = " << a + NaN << "\n";
	std::cout << a << " - NaN = " << a - NaN << "\n";
	std::cout << a << " * NaN = " << a * NaN << "\n";
	std::cout << a << " / NaN = " << a / NaN << "\n";
	std::cout << " NaN - " << a << " = " << NaN - a << "\n";
	std::cout << " NaN / " << a << " = " << NaN / a << "\n";
	
	//operazioni tra Inf e NaN
	//con inf_pos
	std::cout << " Inf + NaN = " << inf_pos + NaN << "\n";
	std::cout << " Inf - NaN = " << inf_pos - NaN << "\n";
	std::cout << " Inf * NaN = " << inf_pos * NaN << "\n";
	std::cout << " Inf / Nan = " << inf_pos / NaN << "\n";
	std::cout << " Nan - Inf = " << NaN - inf_pos << "\n";
	std::cout << " Nan / Inf = " << NaN / inf_pos << "\n";
	//con inf_neg
	std::cout << " (-Inf) + NaN = " << inf_neg + NaN << "\n";
	std::cout << " (-Inf) - NaN = " << inf_neg - NaN << "\n";
	std::cout << " (-Inf) * NaN = " << inf_neg * NaN << "\n";
	std::cout << " (-Inf) / Nan = " << inf_neg / NaN << "\n";
	std::cout << " Nan - (-Inf) = " << NaN - inf_neg << "\n";
	std::cout << " Nan / (-Inf) = " << NaN / inf_neg << "\n";
	
	//operazione tra Inf e Inf
	//quando ho entrambi inf_pos
	std::cout << " Inf + Inf = " << inf_pos + inf_pos << "\n";
	std::cout << " Inf - Inf = " << inf_pos - inf_pos << "\n";
	std::cout << " Inf * Inf = " << inf_pos * inf_pos << "\n";
	std::cout << " Inf / Inf = " << inf_pos / inf_pos << "\n";
	//quando ho inf_pos e inf_neg
	std::cout << " Inf + (-Inf) = " << inf_pos + inf_neg << "\n";
	std::cout << " Inf - (-Inf) = " << inf_pos - inf_neg << "\n";
	std::cout << " Inf * (-Inf) = " << inf_pos * inf_neg << "\n";
	std::cout << " Inf / (-Inf) = " << inf_pos / inf_neg << "\n";
	std::cout << " (-Inf) - Inf = " << inf_neg - inf_pos << "\n";
	std::cout << " (-Inf) / Inf = " << inf_neg / inf_pos << "\n";
	//quando ho entrambi inf_neg
	std::cout << "(-Inf) + (-Inf) = " << inf_neg + inf_neg << "\n";
	std::cout << "(-Inf) - (-Inf) = " << inf_neg - inf_neg << "\n";
	std::cout << "(-Inf) * (-Inf) = " << inf_neg * inf_neg << "\n";
	std::cout << "(-Inf) / (-Inf) = " << inf_neg / inf_neg << "\n";
	
	//operazioni tra NaN e NaN
	std::cout << "NaN + NaN = " <<  NaN + NaN << "\n";
	std::cout << "NaN - NaN = " <<  NaN - NaN << "\n";
	std::cout << "NaN * NaN = " <<  NaN * NaN << "\n";
	std::cout << "NaN / NaN = " <<  NaN / NaN << "\n";
	
	//operazioni tra Inf o NaN e 0
	std::cout << "Inf * 0 = " << inf_pos * zero << "\n";
	std::cout << "Inf / 0 = " << inf_pos / zero << "\n";
	std::cout << "0 / Inf = " << zero / inf_pos << "\n";
	
	std::cout << "(-Inf) * 0 = " << inf_neg * zero << "\n";
	std::cout << "(-Inf) / 0 = " << inf_neg / zero << "\n";
	std::cout << "0 / (-Inf) = " << zero / inf_neg << "\n";
	
	std::cout << "NaN * 0 = " << NaN * zero << "\n";
	std::cout << "NaN / 0 = " << NaN / zero << "\n";
	std::cout << "0 / NaN = " << zero / NaN << "\n";
	
	//operatori di assegnamento (+=, -=, *=, /=)
	razionali<int> x;
	
	x=a;
	std::cout << " a += b = " << ( a += b) << "\n";
	x=a;
	std::cout << " a -= b = " << ( a -= b) << "\n";
	x=a;
	std::cout << " a *= b = " << ( a *= b) << "\n";
	x=a;
	std::cout << " a /= b = " << ( a /= b) << "\n";
	
	x=a;
	std::cout << " a += Inf = " << (a += inf_pos) << "\n";
	x=a;
	std::cout << " a -= Inf = " << (a -= inf_pos) << "\n";
	x=a;
	std::cout << " a *= Inf = " << (a *= inf_pos) << "\n";
	x=a;
	std::cout << " a /= Inf = " << (a /= inf_pos) << "\n";
	
	x=a;
	std::cout << " a += NaN = " << ( a += NaN) << "\n";
	x=a;
	std::cout << " a -= NaN = " << ( a -= NaN) << "\n";
	x=a;
	std::cout << " a *= NaN = " << ( a *= NaN) << "\n";
	x=a;
	std::cout << " a /= NaN = " << ( a /= NaN) << "\n";
	
	return 0;
};
	
	
	
	