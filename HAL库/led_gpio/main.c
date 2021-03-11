#define GPIO_CLK (*(volatile unsigned int* )(0x40023800 + 0x10))
#define GPIO_MODER (*(volatile unsigned int* )(0x40020000 + 0x04))
#define GPIO_ODR (*(volatile unsigned int* )(0x40020000 + 0x14))
	

/*Ƭ���������ַ  */
#define PERIPH_BASE           ((unsigned int)0x40000000)                          

/*���߻���ַ */
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)	

/*GPIO�������ַ*/
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x0000)


/* GPIOF�Ĵ�����ַ,ǿ��ת����ָ�� */
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

/*RCC�������ַ*/
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800)

/*RCC��AHB1ʱ��ʹ�ܼĴ�����ַ,ǿ��ת����ָ��*/
#define RCC_AHB1ENR				*(unsigned int*)(RCC_BASE+0x30)


	

int main(void){

	
	
//	���� GPIOA ʱ�ӣ�ʹ������ʱ��Ҫ�ȿ�������ʱ��
	RCC_AHB1ENR |= (1<<0);	
	
	
//	LED �˿ڳ�ʼ�� 
	
//	GPIOF MODER6���
	GPIOF_MODER  &= ~( 0x03 << (2*6));	
//	PF6 MODER6 = 01b ���ģʽ
	GPIOF_MODER |= (1<<2*6);
	
//	GPIOF OTYPER6���
	GPIOF_OTYPER &= ~(1 << 1*6);
	
//	PF6 OTYPER6 = 0b ����ģʽ
	GPIOF_OTYPER |= (0 << 1*6);
	
	
//	GPIOF OSPEEDR6���
	GPIOF_OSPEEDR &= ~(0x03 << 2*6);
	
//	PF6 OSPEEDR6 = 0b ����2MHz
	GPIOF_OSPEEDR |= (2 << 2*6);
	
	
//	GPIOF PUPDR6���
	GPIOF_PUPDR &= ~(0x03 << 2*6);
	
//	PF6 PUPDR6 = 01b ����ģʽ
	GPIOF_PUPDR |= (1 << 2*6);
	
//	PF6 BSRR�Ĵ����� BR6��1��ʹ��������͵�ƽ
	GPIOF_BSRR |= (1 << (16+6));
	
//	PF6 BSRR�Ĵ����� BS6��1��ʹ��������ߵ�ƽ
	GPIOF_BSRR |= (0 << 6);
	
	
	
}
