#include <project.h>

/* Declaramos las funciones que se van a ejecutar en la interrupción del SysTick timer,
* se ejecutan al mismo tiempo.
*/
void LED(void);
void LED_B(void);

/* CYDEV_BCLK__SYSCLK__HZ: Macro que nos indica a que velocidad esta corriendo el CPU */
/* This interrupt should happen every 100 ms */
#define SYSTICK_RELOAD      ( CYDEV_BCLK__SYSCLK__HZ / 10 )

int main(){
    
    CySysTickStart();
    
    /* Configuramos el Reload del Systick */
    CySysTickSetReload(SYSTICK_RELOAD);
    
    /* Asignamos posiciones a las funciones */
    CySysTickSetCallback(0, LED);
    CySysTickSetCallback(1, LED_B);
    
    CySysTickClear();
    
    CyGlobalIntEnable;

    for(;;){
    }
}

void LED(void){
    RED_Write(~RED_Read());
}

void LED_B(void){
    BLUE_Write(~BLUE_Read());
}

/* [] END OF FILE */
