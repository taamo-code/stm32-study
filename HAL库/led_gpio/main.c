#define GPIO_CLK (*(volatile unsigned int* )(0x40023800 + 0x10))
#define GPIO_MODER (*(volatile unsigned int* )(0x40020000 + 0x04))
#define GPIO_ODR (*(volatile unsigned int* )(0x40020000 + 0x14))
	

/*片上外设基地址  */
#define PERIPH_BASE           ((unsigned int)0x40000000)                          

/*总线基地址 */
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)	

/*GPIO外设基地址*/
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x0000)


/* GPIOF寄存器地址,强制转换成指针 */
#define GPIOF_MODER				*(unsigned int*)(GPIOF_BASE+0x00)
#define GPIOF_OTYPER			*(unsigned int*)(GPIOF_BASE+0x04)
#define GPIOF_OSPEEDR			*(unsigned int*)(GPIOF_BASE+0x08)
#define GPIOF_PUPDR				*(unsigned int*)(GPIOF_BASE+0x0C)
#define GPIOF_IDR					*(unsigned int*)(GPIOF_BASE+0x10)
#define GPIOF_ODR					*(unsigned int*)(GPIOF_BASE+0x14)
#define GPIOF_BSRR					*(unsigned int*)(GPIOF_BASE+0x18)
#define GPIOF_LCKR					*(unsigned int*)(GPIOF_BASE+0x1C)
#define GPIOF_AFRL					*(unsigned int*)(GPIOF_BASE+0x20)
#define GPIOF_AFRH					*(unsigned int*)(GPIOF_BASE+0x24)

/*RCC外设基地址*/
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)

/*RCC的AHB1时钟使能寄存器地址,强制转换成指针*/
#define RCC_AHB1ENR				*(unsigned int*)(RCC_BASE+0x30)


	

int main(void){

	
	
//	开启 GPIOA 时钟，使用外设时都要先开启它的时钟
	RCC_AHB1ENR |= (1<<0);	
	
	
//	LED 端口初始化 
	
//	GPIOF MODER6清空
	GPIOF_MODER  &= ~( 0x03 << (2*6));	
//	PF6 MODER6 = 01b 输出模式
	GPIOF_MODER |= (1<<2*6);
	
//	GPIOF OTYPER6清空
	GPIOF_OTYPER &= ~(1 << 1*6);
	
//	PF6 OTYPER6 = 0b 推挽模式
	GPIOF_OTYPER |= (0 << 1*6);
	
	
//	GPIOF OSPEEDR6清空
	GPIOF_OSPEEDR &= ~(0x03 << 2*6);
	
//	PF6 OSPEEDR6 = 0b 速率2MHz
	GPIOF_OSPEEDR |= (2 << 2*6);
	
	
//	GPIOF PUPDR6清空
	GPIOF_PUPDR &= ~(0x03 << 2*6);
	
//	PF6 PUPDR6 = 01b 上拉模式
	GPIOF_PUPDR |= (1 << 2*6);
	
//	PF6 BSRR寄存器的 BR6置1，使引脚输出低电平
	GPIOF_BSRR |= (1 << (16+6));
	
//	PF6 BSRR寄存器的 BS6置1，使引脚输出高电平
	GPIOF_BSRR |= (0 << 6);
	
	
	
}
