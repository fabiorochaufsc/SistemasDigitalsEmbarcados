#include <inttypes.h> 
#include "onewire.h"

#include "digital.h"
#include "debug.h"


class DS18B20 {

private:
	ONEWIRE *onewire;
public:
	DS18B20 (gpio_num_t pino);
	float readTemp (void);
	void init (void);



};