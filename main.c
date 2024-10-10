#include <stdint.h>

		uint32_t* const RCC_AHB1ENR = (uint32_t*) 0x40023830 ;
		uint32_t* const GPIOA_MODER = (uint32_t*) 0x40020000 ;
		uint32_t* const GPIOA_ODR = (uint32_t*) 0x40020014 ;

int main(void)
{
	(*RCC_AHB1ENR)  |= (1<<0);   // Enable Clock GPIOA 	(RCC->AHB1ENR)
	(*GPIOA_MODER) |= (1<<10);  // PA5 Output
        (*GPIOA_MODER) &=~(1<<11);
	while(1){

		(*GPIOA_ODR) |= (1<<5);

		for(uint32_t i = 0 ; i<100000; i++);

		(*GPIOA_ODR) &= ~(1<<5);

		for(uint32_t i = 0 ; i<100000; i++);

		// Toggle PA5		(GPIOA->ODR)
	}
}


