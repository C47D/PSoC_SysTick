#include <project.h>

/* Declaramos las funciones */
void LED(void);

/* CYDEV_BCLK__SYSCLK__HZ: Macro que nos indica a que velocidad esta corriendo el CPU */
/* This interrupt should happen every 100 ms */
#define SYSTICK_RELOAD      ( BCLK__BUS_CLK__HZ / 10 )

int main(){
    
    CySysTickStart();
    
    /* Configuramos el Reload del Systick */
    CySysTickSetReload( SYSTICK_RELOAD );
    
    /* Asignamos posiciones a las funciones */
    CySysTickSetCallback(0, LED);
    
    CySysTickClear();
    
    CyGlobalIntEnable;

    for(;;){
    }
}

void LED(void){
    LED_Write(~LED_Read());
}

/* [] END OF FILE */
