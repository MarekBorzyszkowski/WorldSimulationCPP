#include "Animal.h"
#ifndef WF_H
#define WF_H

class Wolf : public Animal {
public:
	Wolf(Wolf*, Position*, World*);
	Organism* clone() override;
	void initialParameters() override;

};

#endif