/* Dependencies */
#include "Watchdog.h"

/**
 * @brief Default constructor for the __WATCHDOG__ class.
 * 
 * @details This constructor does not perform any initialization. 
 *          It is intentionally left empty, assuming that watchdog 
 *          configuration will be handled separately.
 * 
 * @note Ensure proper initialization before enabling the watchdog 
 *       to avoid unintended resets.
 */
__WATCHDOG__::__WATCHDOG__()
{
    /* Empty */
}

/**
 * @brief Destructor for the __WATCHDOG__ class.
 * 
 * @details This destructor does not perform any specific operations.
 *          The watchdog timer, once enabled, typically remains active 
 *          until a system reset. If explicit disabling of the watchdog 
 *          is required, it should be handled separately before object 
 *          destruction.
 * 
 * @note The watchdog timer is a hardware feature and is not automatically 
 *       disabled upon object destruction.
 */
__WATCHDOG__::~__WATCHDOG__()
{
    /* Empty */
}

/**
 * @brief Enables the watchdog timer with a specified timeout.
 * 
 * This function enables the watchdog timer with a given timeout value.
 * It ensures that only valid timeout values are used and prevents
 * enabling the watchdog multiple times if it's already active.
 * 
 * @param timeout The watchdog timeout value (e.g., WDTO_15MS, WDTO_1S).
 * @return 1 if successfully enabled, 0 if already enabled or invalid value.
 */
const uint8_t __WATCHDOG__::enable(const uint8_t timeout)
{
    // Check if the watchdog is already enabled
    if (this->isEnabled())
        return (0);

    // Ensure that at least one watchdog timeout value is defined
    #if defined(WDTO_15MS)  || defined(WDTO_30MS)  || defined(WDTO_60MS)  || \
        defined(WDTO_120MS) || defined(WDTO_250MS) || defined(WDTO_500MS) || \
        defined(WDTO_1S)    || defined(WDTO_2S)    || defined(WDTO_4S)    || defined(WDTO_8S)
    
    switch (timeout)
    {
        #if defined(WDTO_15MS)
        case WDTO_15MS:
        #endif
        #if defined(WDTO_30MS)
        case WDTO_30MS:
        #endif
        #if defined(WDTO_60MS)
        case WDTO_60MS:
        #endif
        #if defined(WDTO_120MS)
        case WDTO_120MS:
        #endif
        #if defined(WDTO_250MS)
        case WDTO_250MS:
        #endif
        #if defined(WDTO_500MS)
        case WDTO_500MS:
        #endif
        #if defined(WDTO_1S)
        case WDTO_1S:
        #endif
        #if defined(WDTO_2S)
        case WDTO_2S:
        #endif
        #if defined(WDTO_4S)
        case WDTO_4S:
        #endif
        #if defined(WDTO_8S)
        case WDTO_8S:
        #endif
            wdt_enable(timeout); /**< Enable the watchdog with the given timeout */
            wdt_reset();         /**< Reset the watchdog to prevent immediate reset after enabling */
            break;
        
        default:
            return (0); /**< Return 0 if the timeout value is invalid */
    }

    this->enabled = 1; /**< Mark watchdog as enabled */
    return (1);

    #else /**< If no timeout values are defined, compilation will fail with this error */
    #error "No valid watchdog timeout values are defined" 
    return (0);
    #endif
}



/**
 * @brief  Disables the watchdog timer.
 * @return 1 if the watchdog was successfully disabled, 0 if it was already disabled.
 */
const uint8_t __WATCHDOG__::disable(void)
{
    if (*this->isEnabled())  /**< Ensure the watchdog is currently enabled before proceeding */
        return (0);

    wdt_disable();  /**< Disable the watchdog timer */
    this->enabled = 0;  /**< Update the internal flag to indicate the watchdog is disabled */
    return (1);  /**< Return success status */
}



/**
 * @brief  Checks if the watchdog timer is enabled.
 * @return 1 if the watchdog is enabled, 0 otherwise.
 */
const uint8_t __WATCHDOG__::isEnabled(void)
{
    return (this->enabled);  /**< Returns the internal flag indicating watchdog status */
}


/**
 * @brief  Resets the watchdog timer to prevent a reset.
 * @note   This function does nothing if the watchdog is not enabled.
 */
void __WATCHDOG__::feed(void)
{
    if (*this->isEnabled())  /**< Check if the watchdog is enabled */
        return;

    wdt_reset();  /**< Reset the watchdog timer to prevent a reset */
}


/**
 * @brief  Creates an instance of the Watchdog class.
 * @note   This instance allows controlling the watchdog timer, such as enabling, disabling, and feeding it.
 */
__WATCHDOG__ Watchdog = __WATCHDOG__();  /**< Instantiate the Watchdog object */
