#pragma once
#include <concepts>
#include <iostream>
#include <numeric>

template<typename I> requires std::integral<I>
class razionali
{
	I num_;
	I den_;
	
	void semplifica() {
		//gestisco quando il denominatore è uguale a 0
		if (den_ == 0) {
			if (num_ > 0) num_ = 1;   //da come risultato +inf
			else if (num_ < 0) num_=-1;	  //da come risultato -inf
			else num_ = 0;   //da come risultato NaN
			return;
		}
		
		//gestisco quando il numeratore è uguale a zero
		if (num_ == 0) {
			den_ = 1;
			return;
		}
		
		//il segno va messo al numeratore
		if (den_ < 0) {
			num_=-num_;
			den_=-den_;
		}
		
		//gestisco la semplificazione
		I mcd = std::gcd(num_, den_);
		if (mcd > 1) {  //escluso =1, i numeri sarebbero primi
			num_ /= mcd;
			den_ /= mcd;
		}
	}	

public:
	/* Costruttore di default */
	razionali()	
		: num_(I{0}), den_(I{1})
	{}
	
	/* Costruttore user-defined */
	razionali(const I& num, const I& den)
		: num_(num), den_(den) 
		{
			semplifica();
		}
		
	/* Restituiscono i valori di num e den */
	I num() const {return num_; }
	I den() const {return den_; }
	 
	/* Implementazione canonica dell'incremento */ 
	razionali& operator+= (const razionali& other) {
		if (den_==0 || other.den_==0) {
			//se uno dei 2 è (0/0)
			if ((den_==0 && num_==0)|| (other.den_==0 && other.num_==0)){
				num_=0; den_=0; return *this;
			}
			//se sono entrambi infiniti
			if (den_==0 && other.den_==0) {
				if ((num_>0 && other.num_>0) || (num_<0 && other.num_<0)) {
					return *this; //inf+inf=inf o (-inf)+(-inf)=-inf
				} else {
					num_=0; den_=0; return *this; //inf+(-inf)= NaN
				}
			}
		}
		num_ =num_ * other.den_ + other.num_ * den_;
		den_= den_ * other.den_;
		semplifica();
		return *this;
	}
	
	/* Implementazione canonica della somma */	
	razionali operator+ (const razionali& other) const {
		razionali ret= *this;
		ret += other;
		return ret;
	}
	
	/* Implementazione canonica dell'incremento negativo */
	razionali& operator-= (const razionali& other) {
		if (den_==0 || other.den_==0) {
			//se uno dei 2 è NaN, il risultato è NaN
			if ((den_==0 && num_==0) || (other.den_==0 && other.num_==0)){
				num_=0; den_=0; return *this;
			}
			//se sono entrambi infiniti
			if (den_==0 && other.den_==0) {
				if (num_>0 && other.num_<0) {
					return *this; //inf - (-inf) = +inf
				} else if (num_<0 && other.num_>0) {
					return *this; //-inf -(+inf) = -inf
				} else {
					num_=0; den_=0; return *this; // inf - inf=NaN, -inf -(inf)= NaN
				}
			}
		}		
		num_ =num_ * other.den_ - other.num_ * den_;
		den_= den_ * other.den_;
		semplifica();
		return *this;
	}
	
	/* Implementazione canonica della sottrazione */
	razionali operator- (const razionali& other) const {
		razionali ret= *this;
		ret -= other;
		return ret;
	} 
	
	/* Implementazione canonica di *= */	
	razionali& operator*=(const razionali& other) {
		if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
        	num_ = 0;
        	den_ = 0;
        	return *this;
    	}
		// Caso: 0 * Inf → NaN
    	if ((num_ == 0 && other.den_ == 0) || (other.num_ == 0 && den_ == 0)) {
        	num_ = 0;
       		den_ = 0;
        	return *this;
    	}
		// Caso: almeno uno è infinito
    	if (den_ == 0 || other.den_ == 0) {
        	I segno1;
        	if (num_ > 0)
            	segno1 = 1;
        	else
            	segno1 = -1;
        	I segno2;
        	if (other.num_ > 0)
            	segno2 = 1;
        	else
            	segno2 = -1;
       		num_ = segno1 * segno2; 
        	den_ = 0;               

        	return *this;
    	}
		num_ *=other.num_;
		den_ *=other.den_;
		semplifica();
		return *this;
	}
	
	/* implementazione cononica della moltiplicazione */
	razionali operator*(const razionali& other) const {
		razionali ret = *this;
		ret *= other;
		return ret;
	}
	
	/*implementazione canonica di =/ */
	razionali& operator/=(const razionali& other) {
		// NaN
		if ((den_ == 0 && num_ == 0) || (other.den_ == 0 && other.num_ == 0)) {
    		num_ = 0; den_ = 0;
    		return *this;
		}
		// divisione per zero
		if (other.num_ == 0) {
    		if (num_ == 0) {
        		num_ = 0; den_ = 0; // NaN
    		} else if (num_ > 0) {
        		num_ = 1; den_ = 0; // +Inf
    		} else {
        		num_ = -1; den_ = 0; // -Inf
    		}
    		return *this;
		}
		if (den_ == 0 && other.den_ == 0) {
    		num_ = 0; den_ = 0;
    		return *this;
		}
		if (den_ == 0) {
			return *this;
		}
		if (other.den_ == 0) {
    		num_ = 0;
    		den_ = 1;
    		return *this;
		}		
		num_ *=other.den_;
		den_ *=other.num_;
		semplifica();
		return *this;
	}
	
	/* implementazione cononica della divisione */
	razionali operator/(const razionali& other) const {
		razionali ret = *this;
		ret /= other;
		return ret;
	}
};

template<typename I>
std::ostream&
operator<<(std::ostream& os, const razionali<I>& r) 
{
	//quando il denominatore è uguale a 0
	if (r.den() == 0) {
		if (r.num()>0) os <<"+Inf";
		else if (r.num() < 0) os <<"-Inf";
		else os <<"NaN";
	}
	else if (r.den() == 1) {
		//se il dominatore è uguale a 1, stampa solo il numeratore
		os << r.num();
	}
	else {
		//stampo la frazione
		os <<r.num() << "/" << r.den();
	}
	return os;
}
	