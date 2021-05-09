#ifndef WF_H
#define WF_H

#include "Animal.h"

class Wolf : public Animal {
private:
	Organism* clone() override;
public:
	Wolf(Wolf*, Position*, World*);
	void initialParameters() override;

};

#endif