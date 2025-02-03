#ifndef __WATCHDOG_H__
#define __WATCHDOG_H__

/* Dependencies */
#include <avr\wdt.h>

class __WATCHDOG__
{
    public:
        __WATCHDOG__();
        ~__WATCHDOG__();
        const uint8_t enable   (const uint8_t timeout);
        void          disable  (void);
        const uint8_t isEnabled(void);
        void          feed     (void);
    private:
        uint8_t enabled;
};

extern __WATCHDOG__ Watchdog;

#endif
